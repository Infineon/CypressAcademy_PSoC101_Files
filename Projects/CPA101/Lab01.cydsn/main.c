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

int main()
{
    uint16 ADCResult;   /* ADC result */
    
    ADC_Start();
    ADC_StartConvert();
    LCD_Start();

    CyGlobalIntEnable;

    for(;;)
    {
        /* Get ADC result  in mV */
        ADCResult = ADC_CountsTo_mVolts(POT_CHAN,ADC_GetResult16(POT_CHAN));
        
        /* Display value to LCD */
        LCD_Position(0,0);
        LCD_PrintNumber(ADCResult);
        LCD_PrintString("mV   ");
    }
}


/* [] END OF FILE */
