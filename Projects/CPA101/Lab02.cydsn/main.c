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

#define ON  (1)
#define OFF (0)

#define DELAY (500)

int main()
{

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        LED_Write(ON);
        CyDelay(DELAY);
        LED_Write(OFF);
        CyDelay(DELAY);
    }
}

/* [] END OF FILE */
