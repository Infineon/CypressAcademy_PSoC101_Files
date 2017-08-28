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

#define OFF 0
#define ON  1

int main()
{
	uint8 LED_state = OFF;
	
    for(;;)
    {        
		/* Turn an LED on or off depending on  LED_state */
		if(LED_state)
		{
			Software_LED_Write(ON);	
		}
		else
		{
			Software_LED_Write(OFF);
		}
    }
}

/* [] END OF FILE */
