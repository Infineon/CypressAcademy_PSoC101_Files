/* ========================================
 * Copyright Cypress Semiconductor, 2012
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Cypress Semiconductor.
 * ======================================== */
#include <project.h>

/* This must be commented out if an LCD is not connected */
#define LCD_ENABLE

#define FALSE			0
#define TRUE			1

#define NUM_BUTTONS     4

#define I2CSIZE			3
#define I2CWRITE		1

#define WDT_COUNT       3277    /* 100ms from a 32.768KHz clock is 3277 cycles */
#define SLEEP_COUNT		100		/* 200 * 100ms = 10,000ms = 10s */

#define ALLOFF			0xF		/* Code to turn off all LEDs */

#define DEBOUNCE_COUNT  10

#define SPEED1          0x01
#define SPEED2          0x02
#define SPEED3          0x04

#define INIT			0x40
#define	PASS			0x20
#define FAIL			0x10
#define RUN				0x00

/* I2C register map */
#define INFO			0
#define BUTTON			1
#define	SPEED			2

/* Function prototypes */
void checkSpeed(void);
void playSong(void);

uint8   i2cBuf[I2CSIZE] = {INIT,0x00,0x00};	/* 3 byte I2C buffer */
uint8   sleepCount=SLEEP_COUNT;	            /* Counter to determine when to sleep */
uint16	resultADC; 						    /* ADC result used for speed setting */
uint8 	speedVal;					    	/* Current speed setting */

/* Watchdog timer ISR */
/* This triggers every 100ms. It decrements the counter and after */
/* it has counted down to zero, sleep will be initiated */
CY_ISR(SleepISR)
{
    CySysWdtClearInterrupt(CY_SYS_WDT_COUNTER0_INT);
    
    if(sleepCount)
    {
		sleepCount--;
	}

}

/* This ISR stops the fail PWM once the beep is done */
CY_ISR(FailISR)
{
    PWM_Fail_ClearInterrupt(PWM_Fail_INTR_MASK_TC);
    
    /* The fail PWM will go through this many periods before turning off */
    #define FAIL_COUNT      75
    
    static uint8 failCount = FAIL_COUNT;
    
    if(failCount)
    {
        failCount--;
    }
    else
    {
        PWM_Fail_Stop();
        failCount = FAIL_COUNT;
    }
}

int main()
{
	uint8 i;						    /* Loop counter */
	uint8 buttonData;				    /* Contains value of button being pressed */
    uint8 debounce = DEBOUNCE_COUNT;    /* Button debounce counter */

    
	/* Cheat mode variables */
	uint8  cheatMode = FALSE;	                /* Flag to toggle cheat mode on/off */
    uint8  debounceCheat = DEBOUNCE_COUNT;      /* Cheat button debounce counter */
    uint8  debounceToggled = FALSE;             /* Flag so we don't toggle cheat mutilple times */
	uint8  sequenceCount = 1;	                /* Sequence length for the current round */
	uint8  sequence[99];			            /* This holds the passing sequence */
	uint8  doneFlag = FALSE;		            /* Flag to know when game is done */
	uint16 endFlag = FALSE;		                /* Count to control fail beeper and pass song */

   	CyGlobalIntEnable;
    
	/* Start/Initialize everything */
	#ifdef LCD_ENABLE
        LCD_Start();
	    LCD_Position(1,0);
	    LCD_PrintString("Speed: ");
    #endif
	ADC_Start();
    ADC_StartConvert();
    EZI2C_EzI2CSetBuffer1(I2CSIZE,I2CWRITE,i2cBuf); /* 3 byte buffer but only 1st byte can be written by the master */
    EZI2C_Start();

    LED_AWAKE_Write(TRUE); /* Turn on LED */

	/* Start up Watchdog timer */
	CySysWdtWriteMode(CY_SYS_WDT_COUNTER0,CY_SYS_WDT_MODE_INT);
	CySysWdtWriteMatch(CY_SYS_WDT_COUNTER0,WDT_COUNT);
	CySysWdtWriteClearOnMatch(CY_SYS_WDT_COUNTER0, 1u);
	CySysWdtWriteCascade(CY_SYS_WDT_CASCADE_NONE);
	CySysWdtEnable(CY_SYS_WDT_COUNTER0_MASK);    
    
    isr_fail_StartEx(FailISR);
    isr_sleep_StartEx(SleepISR);
    
    for(;;)
    {
		/****************************************************************************************/
		/* Check Cheat Mode Switch */
		/****************************************************************************************/
        if(!Cheat_Read()) /* Toggle cheat mode when switch is pressed/released */
		{
			if(debounceCheat) /* Not past the debounce yet */
            {
                debounceCheat--;
            }
            else if(!debounceToggled) /* Past the debounce - toggle cheat mode */
            {
                debounceToggled = TRUE;     /* Set flag so we don't toggle on next loop */
                sleepCount = SLEEP_COUNT;   /* Reset sleep count */
                cheatMode = !cheatMode;     /* Toggle cheat mode */
			    #ifdef LCD_ENABLE
                    LCD_Position(0,11);
    			    if(cheatMode)
    			    {
    				    LCD_PrintString("Cheat");
    			    }
    			    else
    			    {
    				    LCD_PrintString("     ");
    			    }
                #endif
            }
		}
        else /* Button not pressed - reset debounce */
        {
            debounceCheat = DEBOUNCE_COUNT;
            debounceToggled = FALSE;
        }
		
		/****************************************************************************************/
		/* Check buttons and update the LED state and I2C register */
		/****************************************************************************************/
        if(!cheatMode) /* Regular game play */
		{
			checkSpeed();	/* Check for new speed value */
			
			/* Read button press state from register. */
			/* The XOR inverts each bit since the buttons are active low */
			buttonData = (Button_Reg_Read() ^ 0xF);
			
            if(buttonData == 0) /* No button is being pressed - reset debounce */
            {
                debounce = DEBOUNCE_COUNT;
            }
            else /* A button is being pressed */
            {
                sleepCount = SLEEP_COUNT; /* Reset sleep count */
                if(debounce)    /* We are not yet passed the debounce */
                {
                    buttonData = 0;
                    debounce--;               
                }
            }
            i2cBuf[BUTTON] = buttonData; /* Update I2C register with pressed button value */
		}
		else /* Cheat mode - look at sequence and send back */
		{
			if(i2cBuf[INFO] == PASS || i2cBuf[INFO] == FAIL || i2cBuf[INFO] == INIT) /* Reset sequence for next game */
			{
				sequenceCount = 1;
				doneFlag = FALSE;
			}
			else /* Game in progress */
			{
				for(i=0;i<sequenceCount;i++) /* Capture the sequence */
				{
					while(i2cBuf[INFO] == RUN)
					{
						CyDelay(1); 	/* Wait until we have button press info from master */	
						checkSpeed();	/* Check for new speed value */
					}
					if(i2cBuf[INFO] == PASS || i2cBuf[INFO] == FAIL ) /* We have completed the game */
					{
						doneFlag = TRUE;
						LEDreg_Write(ALLOFF);
                        if(i2cBuf[INFO] == PASS)
                        {
                            if(endFlag == FALSE)
                            {
                                playSong();
                                endFlag = TRUE; /* Flag so that pass song only plays once */
                            }
                        }
					}
					else /* Game still in progress - wait for next value from master */
					{
						sequence[i] = i2cBuf[INFO]; /* Capture the button press */
						LEDreg_Write(~sequence[i]); /* Turn on LED for this button */
						while(i2cBuf[INFO] != RUN)
						{	
							CyDelay(1); /* Wait until we have no button press */
						}
						LEDreg_Write(ALLOFF);	/* Turn LED back off again */
                        endFlag = FALSE;        /* Reset flag to play pass song */
					}
				}
				CyDelay(400); /* Wait for master to be looking for user input */
				if(!doneFlag) /* Game still in progress */
				{
					for(i=0;i<sequenceCount;i++) /* Send back the sequence */
					{
						i2cBuf[BUTTON] = sequence[i]; /* Send button press */
						LEDreg_Write(~sequence[i]); /* Turn on LED */
						CyDelay(60); /* Wait long enough for master to get the button press */
						i2cBuf[BUTTON] = 0; /* Clear button press */
						LEDreg_Write(ALLOFF); /* Turn off LED */
						CyDelay(60); /* Wait long enough for master to get button clear */
						checkSpeed();	/* Check for new speed value */
					}
					sequenceCount++; /* Get read for next sequence */
				}
			}
		} /* End Cheat Mode */
        
		/****************************************************************************************/
		/* Update LCD based on info register */
		/****************************************************************************************/
	    #ifdef LCD_ENABLE
            LCD_Position(0,0);
		#endif
        
		i = i2cBuf[INFO];
		switch(i)
		{
			case INIT:
			    #ifdef LCD_ENABLE
                    LCD_PrintString("INIT");
                #endif
				break;
			case PASS:
			    #ifdef LCD_ENABLE
                    LCD_PrintString("PASS");
                #endif
				if(endFlag == FALSE) /* Start song when we transition to pass state */
				{
					playSong();
                    endFlag = TRUE;
                }
                break;
			case FAIL:
				#ifdef LCD_ENABLE
                    LCD_PrintString("FAIL");
                #endif
                if(endFlag == FALSE) /* Start beep when we transition to fail state */
				{                     /* The stop is done by the PWM isr */
					PWM_Fail_Start();
                    endFlag = TRUE;
                }
				break;
			case RUN:
				#ifdef LCD_ENABLE	
                    LCD_PrintString("RUN ");
                #endif
				endFlag = FALSE; /* Reset fail flag for next game */
				sleepCount=SLEEP_COUNT; /* Reset sleep count */
				break;
			default: 	/* If we get here, an LED is being lit by the host */ 
						/* We need to light same one on slave */
				LEDreg_Write(~i);
				buttonData = 1; /* Set button data flag so that we don't turn off the LED right away */		
				sleepCount=SLEEP_COUNT; /* Reset sleep count */
				break;
		}

		/* If LED is not written by either button press on slave or from host then turn off all LEDs */
		if(!buttonData)
		{
			LEDreg_Write(ALLOFF);
		}

		/****************************************************************************************/
		/* Low Power Mode */
		/****************************************************************************************/
		if (!sleepCount) /* Time to go to sleep */
		{
            CySysWdtDisable(CY_SYS_WDT_COUNTER0_MASK); /* Turn off the WDT interrupt so that it doesn't wake us up */
			#if (!LED_Indicator__DISABLED)
                Sleep_Reg_Write(TRUE); /* Turn off 3-color LED */
            #endif
            #ifdef LCD_ENABLE	
                LCD_Sleep();
			#endif
			ADC_Sleep();                
			LED_AWAKE_Write(FALSE); /* Turn off LED */
			LEDreg_Write(ALLOFF);	/* Turn off all button LEDs */
            EZI2C_Sleep();

            CySysPmDeepSleep(); /* Prepare to Deep Sleep: enables wakeup interrupt */
            /* When we get here, it is time to wake back up */
            
            EZI2C_Wakeup();; /* Restore for Active operation */
			
			LED_AWAKE_Write(TRUE); /* Turn on LED */
			ADC_Wakeup();
		    #ifdef LCD_ENABLE
                LCD_Wakeup();
			#endif
            LEDreg_Write(ALLOFF); /* Reset the LED control register since it wakes with all 0's */			
            #if (!LED_Indicator__DISABLED)
                Sleep_Reg_Write(FALSE); /* Turn on 3-color LED */
            #endif
                CySysWdtEnable(CY_SYS_WDT_COUNTER0_MASK); /* Turn off the WDT interrupt so that it doesn't wake us up */
			sleepCount=SLEEP_COUNT; /* Reset sleep count */
		} /* End of low power mode */
	} /* End of infinite loop */
} /* End of main */


/****************************************************************************************/
/* Check speed control and update I2C register and LCD */
/****************************************************************************************/
void checkSpeed(void)
{
    if(ADC_IsEndConversion(ADC_RETURN_STATUS)) /* A conversion result is ready */
    {
        resultADC = ADC_GetResult16(0); /* Get result from channel 0 */
        if(resultADC < 70)
        {
            speedVal = SPEED1;
        }
        else if (resultADC < 220)
        {
            speedVal = SPEED2;
        }
        else
        {
            speedVal = SPEED3;
        }
    }
	i2cBuf[SPEED] = speedVal;
    #ifdef LCD_ENABLE
        LCD_Position(1,8);
        LCD_PrintNumber(speedVal);
	#endif
}

/****************************************************************************************/
/* Play the pass song */
/****************************************************************************************/
void playSong(void)
{
    /* Song Notes */
    /* PWM period required is clock frequency divided by the note frequency */
    #define CLK (10000)
    #define E3  (CLK/165)
    #define G3  (CLK/196)
    #define A3  (CLK/220)
    #define BF3 (CLK/233)
    #define B3  (CLK/247)
    #define C4  (CLK/262)
    #define D4  (CLK/294)
    #define E4  (CLK/330)
    #define F4  (CLK/349)
    #define G4  (CLK/392)
    #define A4  (CLK/440)
    #define RE  (0)
    #define PAUSE (10)
    
    /* Note Durations: S - Sixteenth, E - Eighth, Q - quarter, LS - Long Sixteenth */
    #define S   (150)
    #define LS  (S*1.5)
    #define E   (S*2)
    #define Q   (E*2)

    static uint16 notes[]       = {E4, E4, E4, RE, C4, E4, G4, G3,                      /* First measure  */
                                   C4, RE, G3, RE, E3, RE, A3, RE, B3, RE, BF3, A3,     /* Second measure */
                                   G3, E4, G4, A4, F4, G4, RE, E4, RE, C4, D4,  B3};    /* Third measure  */
    
    static uint16 duration[]    = {S,  E,  S,  S,  S,  E,  Q,  Q,                       /* First measure  */
                                   E,  S,  S,  E,  E,  S,  S,  S,  S,  S,  S,   E,      /* Second measure */
                                   LS, LS, LS, LS,  S,  S,  S,  S, S,  S,  S,   S};     /* Third measure  */
    
    uint8 i;
      
    /* Play each note. Need to divide sizeof(notes) by 2 since it is an array of uint16's */
    for (i = 0; i < (sizeof(notes)>>1); i++)
    {
        PWM_Pass_WritePeriod(notes[i]);
        PWM_Pass_WriteCounter(notes[i]);
        PWM_Pass_WriteCompare(notes[i]>>1);
        PWM_Pass_Start();
        CyDelay(duration[i]);
        PWM_Pass_Stop();
        CyDelay(PAUSE); /* Pause between notes */
    }
}
/* [] END OF FILE */
