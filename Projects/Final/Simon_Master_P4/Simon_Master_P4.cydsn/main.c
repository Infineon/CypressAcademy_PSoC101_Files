/* ========================================
 *
 * Copyright Cypress Semiconductor, 2012
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Cypress Semiconductor.
 *
 * ========================================
*/
#include <project.h>
#include <stdlib.h>

#define SLAVE_ADDRESS	0x36
#define I2COFFSET		0x00

/* I2C register map */
#define INFO	0
#define BUTTON  1
#define SPEED   2

#define MAX_SEQUENCE 	99	/* Longest allowed sequence to pass the game */

#define ALLOFF		0x00	/* Turn off all LEDs */

/* Button values from slave */
#define NOBUTTON	0x00	
#define BUTTON1		0x01	
#define BUTTON2		0x02
#define BUTTON3		0x04
#define BUTTON4		0x08

/* Info messages passed to slave */
#define INIT		0x40
#define	PASS		0x20	
#define FAIL		0x10
#define RUN			0x00
#define LED1		0x01
#define LED2		0x02
#define LED3		0x04
#define LED4		0x08

/* State machine for game state */
#define IDLE		0x00	
#define RUNNING		0x01

/* Speed values from slave */
#define SLOW		1		
#define MEDIUM		2
#define FAST		4

/* Blink delays in ms */
#define SLOW_DELAY		300
#define MEDIUM_DELAY	100
#define FAST_DELAY		1

/* Number of correct guesses to pass the game */
#define MAX1	5
#define MAX2	10
#define MAX3	99

#define RESET_PRESSES	3	/* Nuber of presses until HS is reset */

#define DEBOUNCE        100 /* Cycles used for switch debounce */

/* function prototyptes */
void   	getI2Cdata(void);
void   	putI2Cdata(uint8 I2Cdata);
uint16	checkSpeed(void);

/* global varialbls */
uint8	rdData[3] = {0x00,0x00,0x00}; 	/* Three byte I2C read buffer */
uint8	wrData[2];						/* Two byte I2C write buffer (first byte is the offset) */
uint8	status;

static const uint8 CYCODE   EEData[1] = {0x00};     /* 1 byte of non-volatile data to hold the high score */
uint8                       SRData[1] = {0x00};     /* 1 byte SRAM array to hold high score in SRAM */

int main()
{
	uint16  blinkDelay  = SLOW_DELAY; 		/* Blink delay in ms */
	uint8 	count 		= 0; 				/* Running count of how many sequences have been completed */
	uint8  	gameOn 		= IDLE; 			/* State machine for game state - 0: not running, 1: started, 2: running */
	uint8   button;							/* Variable indicating which button is pressed */
	uint16	loop;							/* Loop counter */
	uint8	badPressFlag = 0;				/* Flag to tell if sequence was incorrect */
	uint8	sequence[MAX_SEQUENCE];			/* Array which holds the random LED sequence */
	uint8	sequenceMask;					/* Bitmask value of sequence (i.e. 1->1, 2->2, 3->4, 4->8) */
    uint8   debounceMax = DEBOUNCE;         /* Debounce for max sequence selector switch */
    uint8	maxCount = MAX3;			    /* Max sequence to pass the game */
	uint8	resetCounter = RESET_PRESSES;	/* Nuber of presses until HS is reset */
    uint8   debounceHS = DEBOUNCE;          /* Debounce for high score reset */
	uint8   seed = 0;                       /* Seed for random number generator - will be set based on button press length */
    
	CyGlobalIntEnable;
	
	/* Start LCD and print static information */
	LCD_Start();
	LCD_ClearDisplay();
	LCD_Position(0,0);
	LCD_PrintString("       #:     HS");
	LCD_Position(1,0);
	LCD_PrintString("     MAX:");
    LCD_Position(1,10);
    LCD_PrintNumber(maxCount);
	
	I2C_Start();

	EEPROM_Start();

	/* Write the offset pointer to the slave with a value of 0. */
	/* We always write to offset 0 and we always read 3 bytes from */
	/* offset 0 so we only need to set this once */
	wrData[0] = I2COFFSET; /* Set pointer to the slave->master byte */
	status = I2C_I2CMasterWriteBuf(SLAVE_ADDRESS, wrData, 1, I2C_I2C_MODE_COMPLETE_XFER);
	while (status != I2C_I2C_MSTR_NO_ERROR); /* Wait for transfer to start */
	while(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_XFER_INP); /* Wait for transfer to complete */
	status = I2C_I2CMasterClearStatus(); /* Clear status for next time */
	
	/* Start out with the INIT state in the info register */
	putI2Cdata(INIT);
	
	for(;;)
    {
		/* Print current high score */
		LCD_Position(1,14);
		SRData[0] = *(volatile uint8 *) &EEData[0];
        if(SRData[0] < 10)
		{
			LCD_PutChar(' '); /* Leading space */
		}	
		LCD_PrintNumber(SRData[0]);

		/* Print how many have passed in current game */
		LCD_Position(0,10);
		if(count < 10)
		{
			LCD_PutChar(' '); /* Leading space */
		}
		LCD_PrintNumber(count);
		
		switch (gameOn)
		{
       		/* Loop until Start switch is pressed */
			case IDLE: /* Game not started */ 		

                /* Look for change to passing sequence length */
    		    if(!Max_Read()) /* Max button is being pressed */
                {
                    if(debounceMax > 1) /* We are not passed the debounce yet */
                    {
                        debounceMax--;
                    }
                    else if (debounceMax == 1) /* Change max on this cycle */
                    {
                        LCD_Position(1,10);
                        if(maxCount == MAX1)
                        {
                            maxCount = MAX2;
                        }
                        else if(maxCount == MAX2)
                        {
                            maxCount = MAX3;
                        }
                        else
                        {
                            maxCount = MAX1;
                            LCD_PutChar(' '); /* Leading space needed since MAX1 is 1 digit instead of 2 */
                        }
                        LCD_PrintNumber(maxCount);
                        debounceMax = 0; /* Use this so toggle only happens once per press of the switch */ 
                    }
                }
                else /* Switch not pressed - reset the debounce */
                {
                    debounceMax = DEBOUNCE;
                }       


                /* Reset high score after 3 presses of SW3 */
				if(!ResetHS_Read())
				{
					if(debounceHS > 1) /* We are not passed the debounce yet */
                    {
                        debounceHS--;
                    }
                    else if (debounceHS == 1) /* Just passed debounce - look to see if HS should be reset yet */
                    {
    					debounceHS = 0; /* Use this so we only recognize one event per press */
                        if(resetCounter)
    					{
    						resetCounter--;
    					}
    					else /* Switch has been pressed 3 times - reset high score */
    					{
    						resetCounter = RESET_PRESSES;
    						SRData[0] = 0x00;
    						status = EEPROM_Write(SRData,EEData, 1u);  /* Write 1 byte to EEPROM */
    					}
                    }
				}
                else /* Switch not pressed - reset the debounce */
                {
                    debounceHS = DEBOUNCE;
                }
				
                /* Switch is pressed, start the game */
                /* We don't need debounce on this one since once the game starts we */
                /* move out of the IDLE state to the RUNNING state and that state */
                /* doesn't look at the start switch. Therefore, the game will start on */
                /* the first falling edge of the Start switch. */
				if(!Start_Read()) 
				{
                    /* Set the random seed based on how long the switch is held */
                    while (!Start_Read())
                    {
                        seed++;
						
						/* Test mode */
						/* If the Reset HS switch is held while start is being */
						/* held we will turn all 4 master LEDs on for 500ms each */
						/* until ResetHS is released */
						while(!ResetHS_Read())
						{
							for(loop = 0; loop < 4; loop++)
							{
								LEDreg_Write(0x01 << loop);
								CyDelay(500);
								LEDreg_Write(ALLOFF);
							}
						}
                    }
                    srand(seed);   
                    
					
					
                    count = 0;
					badPressFlag = 0;
					/* Display running state to LCD */
					LCD_Position (0,0);
					LCD_PrintString("RUN ");
                    
					/* Create a sequence of LEDs to flash */
					for (loop = 0; loop < MAX_SEQUENCE; loop++)
					{
						sequence[loop] = (rand() % 4 + 1); /* random integer from 1 to 4 */
					}
					
					putI2Cdata(RUN);
					
					CyDelay(SLOW_DELAY); /* Wait before first sequence */
					
					gameOn++; /* Go on to the next state */
				}
				
				break; /* End of IDLE state */
			
			case RUNNING: /* Game is running */
			
				/* Blink LEDs for the complete sequence for this round */
				for (loop = 0; loop < count+1; loop++)
				{
					/* Look for speed change from the slave */
					getI2Cdata();
					blinkDelay = checkSpeed();
					
					CyDelay(blinkDelay);
					sequenceMask = (1 << (sequence[loop]-1)); /* Bitmask  of sequence value */
					LEDreg_Write(sequenceMask); /* Light LED */
				 	putI2Cdata(sequenceMask); /* Put value in i2c register */
					CyDelay(blinkDelay);
					LEDreg_Write(ALLOFF); /* Turn off LED */
					putI2Cdata(RUN); /* Clear i2c register */
				}
				
				for (loop = 0; loop < count+1; loop++) /* Check for each button in the sequence */
				{
					do
					{
						getI2Cdata();
						button = rdData[BUTTON];
						blinkDelay = checkSpeed();
                    } while(button == NOBUTTON); /* Wait for a button press */
					
					/* We get here when a button has been pressed */
					/* Light LED that is being pressed */
					LEDreg_Write(button);

					/* Check for correct button press */
					if(button != (1 << (sequence[loop]-1)))
					{
						badPressFlag = 1;
						LEDreg_Write(ALLOFF); /* Make sure all LEDs are off */
						break; /* This will break out of the for loop as soon as a bad button is pressed */
					}
					                                        
					/* Wait for button release before looking for next button */
					while(rdData[BUTTON] != NOBUTTON)
					{
						getI2Cdata();
					}

					/* Turn off LED */
					LEDreg_Write(ALLOFF);
				} /* End of for loop that checks the button press sequense */
				
				/* When we get here, the whole sequence has been tested */
					
				if(!badPressFlag) /* Sequence passed - increment count and go on to the next round */
				{
					count++;
					CyDelay(SLOW_DELAY); /* Delay before starting next sequence */
				}
				else /* Sequence failed */
				{
					if(count > SRData[0])
					{
						/* Write high score to EEPROM */
						SRData[0] = count; /* Save new high score to array with write data */
						status = EEPROM_Write(SRData, EEData, 1u);  /* Write 1 byte to EEPROM */
					}
					LCD_Position(0,0);
					LCD_PrintString("FAIL");
					putI2Cdata(FAIL);	/* Send fail notification to slave */
					gameOn = IDLE; /* Reset state machine back to waiting for a new speed or game start */
				}
				
				if(count == maxCount) /* Max sequence length passed */
				{
					if(count > SRData[0])
					{
						SRData[0] = count; /* Save new high score to array with write data */
						status = EEPROM_Write(SRData, EEData, 1u);  /* Write 1 byte to EEPROM */
					}					
					LCD_Position(0,0);
					LCD_PrintString("PASS");
					putI2Cdata(PASS);	/* Send pass notification to slave and stop game */
					gameOn = IDLE; /* Reset state machine back to waiting for a new speed or game start */
				}
				
				break; /* End of game running case in top level state machine */
			
			default:
				break;
		}
    }
}

/* Get three bytes from slave */
/* These are stored in the rdData array */
void getI2Cdata(void)
{	
	status = I2C_I2CMasterReadBuf(SLAVE_ADDRESS,rdData, 3, I2C_I2C_MODE_COMPLETE_XFER);
	while (status != I2C_I2C_MSTR_NO_ERROR); /* Wait for transfer to start */
	while(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_XFER_INP); /* Wait for transfer to complete */
	status = I2C_I2CMasterClearStatus(); /* Clear status for next time */
}

/* Send one byte of data to slave */
void  putI2Cdata(uint8 I2Cdata)
{
	wrData[1] = I2Cdata; /* put byte to send into I2C send buffer */
	/* wrData[0] is the offset which is always left as 0 */
	status = I2C_I2CMasterWriteBuf(SLAVE_ADDRESS, wrData, 2, I2C_I2C_MODE_COMPLETE_XFER); /* send 2 bytes - offset and data */
	while (status != I2C_I2C_MSTR_NO_ERROR); /* Wait for transfer to start */
	while(I2C_I2CMasterStatus() & I2C_I2C_MSTAT_XFER_INP); /* Wait for transfer to complete */
	status = I2C_I2CMasterClearStatus(); /* Clear status for next time */
	CyDelay(100); /* Not sure why this is needed */
}

uint16 checkSpeed(void)
{
    uint16 blinkDelay;
	
	/* Check for new speed */
	LCD_Position(1,0);
    switch(rdData[SPEED])
	{
		case SLOW:
			blinkDelay = SLOW_DELAY;
			LCD_PrintString("SLOW");
			break;			
		case MEDIUM:
			blinkDelay = MEDIUM_DELAY;
			LCD_PrintString("MED ");
			break;
		case FAST:
			blinkDelay = FAST_DELAY;
			LCD_PrintString("FAST");
			break;
		default:
			blinkDelay = SLOW;
			break;
	}
	
	return blinkDelay;
}

/* [] END OF FILE */
