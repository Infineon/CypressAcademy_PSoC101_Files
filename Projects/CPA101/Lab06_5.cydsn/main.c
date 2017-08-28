/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

int main()
{
    uint16 position=0;
    uint16 lastPosition = 0xFFFF;
   
    /* Must enable interrupts before starting Capsense */
    CyGlobalIntEnable;
	
    PWM_Start();
	CapSense_Start();
	CapSense_InitializeAllBaselines();
    CapSense_ScanEnabledWidgets(); /* Do initial scan */
	LCD_Start();
    
    for(;;)
    {
     	if(!CapSense_IsBusy())
		{
            position = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0__LS);
		    CapSense_UpdateEnabledBaselines();
		    CapSense_ScanEnabledWidgets();	
		    LCD_Position(0,0);
            LCD_PrintInt16(position);
            if(position == 0xFFFF) /* Capsense returns 0xFFFF for no touch */
            {
                PWM_Stop();   
            }
            else
		    {
			    if(position != lastPosition)
                {
                    PWM_Stop();
                    PWM_WritePeriod(position);      /* Update PWM based on finger position */
                    PWM_WriteCompare(position>>1);  /* Set duty cycle to 50% */
                    PWM_WriteCounter(0);            /* Need to make sure count is less than period value to avoid overflow */
                    PWM_Start();
                    lastPosition = position;
                }
		    }    
            
		}
    }
}
