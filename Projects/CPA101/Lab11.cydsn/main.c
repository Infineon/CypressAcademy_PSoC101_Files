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

CY_ISR_PROTO(ISR1);
CY_ISR_PROTO(ISR2);

int main()
{
    PWM_Start();
	int1_StartEx(ISR1);
	int2_StartEx(ISR2);
	
    CyGlobalIntEnable; 
    for(;;)
    {
        CySysPmSleep(); /* Go to sleep until an interrupt occurs */
    }
}

CY_ISR(ISR1)
{
	
	LED1_Write(!LED1_Read());	/* Invert LED state */
	PWM_ReadStatusRegister();	/* Clear PWM interrupt */
}

CY_ISR(ISR2)
{
	LED2_Write(!LED2_Read());	/* Toggle the LED */
	Button_ClearInterrupt();	/* Clear pin interrupt */
}

/* [] END OF FILE */
