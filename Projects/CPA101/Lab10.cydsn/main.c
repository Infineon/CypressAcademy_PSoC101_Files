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
   
       	CapSense_Start();
       	CapSense_SetupWidget(CapSense_BUTTON0_WDGT_ID);
       	CapSense_Scan(); /* Do initial scan */
	
       	for(;;)
      	{
      	    if(!CapSense_IsBusy())
            {
			    CapSense_ProcessWidget(CapSense_BUTTON0_WDGT_ID);
                button1 = CapSense_IsWidgetActive(CapSense_BUTTON0_WDGT_ID);
    			CapSense_Scan();
         	}		
         	led_Write(button1);	/* Turn on LED if the button is being pressed */		
      	}
} 



/* [] END OF FILE */
