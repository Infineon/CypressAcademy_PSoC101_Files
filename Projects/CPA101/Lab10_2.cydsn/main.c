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
       
    /* Must enable interrupts before starting CapSense */
    CyGlobalIntEnable;
	
    PWM_Start();	
    CapSense_Start();
   	CapSense_SetupWidget(CapSense_LINEARSLIDER0_WDGT_ID);
    CapSense_Scan(); /* Do initial scan */
	
    for(;;)
   	{
        if (!CapSense_IsBusy())
        {
            CapSense_ProcessWidget(CapSense_LINEARSLIDER0_WDGT_ID);
            position = CapSense_GetCentroidPos(CapSense_LINEARSLIDER0_WDGT_ID);   
            CapSense_Scan();			
        }
		
        if (position != 0xFFFF) /* CapSense returns 0xFFFF for no touch */
    	{
   			PWM_WriteCompare(position);
 		}			
 		else
		{
       		PWM_WriteCompare(0);
		}
    }
}

