/* ========================================
 *
 * Copyright Cypress Semiconductor, 2014
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
    uint8 button;
    
    CyGlobalIntEnable;
    
    CapSense_Start();
    CapSense_InitializeAllBaselines();
    CapSense_ScanEnabledWidgets(); /* Do initial scan */
	
    for(;;)
    {
     	if(!CapSense_IsBusy())
	    {
		    button = CapSense_CheckIsWidgetActive(CapSense_BUTTON0__BTN);
		    CapSense_UpdateEnabledBaselines();
		    CapSense_ScanEnabledWidgets();
            BuzzEnable_Write(button);
	    }	
    }
}

/* [] END OF FILE */
