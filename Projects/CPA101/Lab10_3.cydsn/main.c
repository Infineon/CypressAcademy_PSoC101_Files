/* ========================================
 *
 * Copyright Cypress Semiconductor 2014
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Cypress Semiconductor.
 *
 * ========================================
*/
#include <project.h>

int main()
{	
 	uint8 button1=0;

       	/* Must enable interrupts before starting CapSense */
       	CyGlobalIntEnable;

        EZI2C_Start();
        
        /* Set up I2C data buffer to point to the CapSense data structure */ 
        EZI2C_EzI2CSetBuffer1(sizeof(CapSense_dsRam), sizeof(CapSense_dsRam),
                              (uint8 *)&CapSense_dsRam);
    
       	CapSense_Start();
       	CapSense_SetupWidget(CapSense_BUTTON0_WDGT_ID);
       	CapSense_Scan(); /* Do initial scan */
	
       	for(;;)
      	{
      	    if(!CapSense_IsBusy())
            {
			    CapSense_ProcessWidget(CapSense_BUTTON0_WDGT_ID);
                CapSense_RunTuner();
                button1 = CapSense_IsWidgetActive(CapSense_BUTTON0_WDGT_ID);
    			CapSense_Scan();
         	}		
         	led_Write(button1);	/* Turn on LED if the button is being pressed */		
      	}
} 



/* [] END OF FILE */
