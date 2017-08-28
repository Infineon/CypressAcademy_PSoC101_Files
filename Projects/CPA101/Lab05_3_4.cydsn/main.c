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

/* ADC channel 0 */
#define POT_CHAN (0)

/* Bargraph constants */
#define ROW (0)
#define COL (0)
#define MAX (16*5)

int main()
{
    uint16 result;
    
    PWM_UDB_Start();
    TCPWM_Start();
    LCD_Start();
    ADC_Start();
    ADC_StartConvert();

    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* Get ADC result */
        result = ADC_GetResult16(POT_CHAN);
        result = (result*100)/4095; /* Convert ADC result to a percentage */
        
        /* Set PWM compare value based on ADC result */
        TCPWM_WriteCompare(result);
        PWM_UDB_WriteCompare(result); 
        
        /* Plot duty cycle on the bar-graph */
        result = (result*MAX)/100; /* Convert percentage to a bargraph value */
        LCD_DrawHorizontalBG(ROW, COL, MAX, result);
        
    }
}

/* [] END OF FILE */
