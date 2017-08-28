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
    uint16 ADCResult;           /* ADC result */
    uint8 I2CReg[2] = {0,0};    /* I2C register is 2 bytes */
    
    ADC_Start();
    ADC_StartConvert();
    LCD_Start();
    EZI2C_Start();
    /* 2 byte I2C buffer, o bytes writeable by the host, name is I2CReg */
    EZI2C_EzI2CSetBuffer1(sizeof(I2CReg), 0, I2CReg);
    
    CyGlobalIntEnable;

    for(;;)
    {
        /* Get ADC result  in mV */
        ADCResult = ADC_CountsTo_mVolts(POT_CHAN,ADC_GetResult16(POT_CHAN));
        
        /* Display value to LCD */
        LCD_Position(0,0);
        LCD_PrintNumber(ADCResult);
        LCD_PrintString("mV   ");
        
        /* Store ADC value in I2C buffer */
        I2CReg[0] = HI8(ADCResult); /* upper byte of result */
        I2CReg[1] = LO8(ADCResult); /* lower byte of result */
    }
}


/* [] END OF FILE */
