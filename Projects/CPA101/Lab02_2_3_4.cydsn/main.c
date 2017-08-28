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

#define DELAY (100)

int main()
{
    uint8 loop;
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        /* The period is broken into 12 slices each of 100ms */
        /* The LED for each time slice are: */
        /* Slice   0    1    2    3    4    5    6    7    8    9   10   11 */
        /* LED1    1    1    1    0    0    0    1    1    1    0   0    0  */
        /* LED2    0    1    0    0    0    1    0    0    0    1   0    0  */
        /* The result is: */
        /* LED1: frequency = 1.667Hz, duty cycle = 50% */
        /* LED2: frequency = 2.5Hz,   duty cycle = 25% */     
        for(loop=0; loop<12; loop++)
        {
            switch(loop)
            {
                case 0:
                    LED1_Write(ON);
                    LED2_Write(OFF);
                    break;
                case 1:
                    LED1_Write(ON);
                    LED2_Write(ON);
                    break;
                case 2:
                    LED1_Write(ON);
                    LED2_Write(OFF);
                    break;
                case 3:
                case 4:
                    LED1_Write(OFF);
                    LED2_Write(OFF);
                    break;
                case 5:
                    LED1_Write(OFF);
                    LED2_Write(ON);
                    break;                        
                case 6:
                case 7:
                case 8:
                    LED1_Write(ON);
                    LED2_Write(OFF);
                    break; 
                case 9:
                    LED1_Write(OFF);
                    LED2_Write(ON);
                    break;
                case 10:
                case 11:
                    LED1_Write(OFF);
                    LED2_Write(OFF);
                    break;
                default:
                    break;
            }
            CyDelay(DELAY);
        }
    }
}

/* [] END OF FILE */
