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
    LCD_Start();

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        LCD_Position(0,0);
        LCD_PrintInt8(ButtonStatus_Read());
    }
}

/* [] END OF FILE */
