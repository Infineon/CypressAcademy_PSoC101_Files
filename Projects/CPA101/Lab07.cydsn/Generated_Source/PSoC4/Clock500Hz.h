/*******************************************************************************
* File Name: Clock500Hz.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_Clock500Hz_H)
#define CY_CLOCK_Clock500Hz_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Clock500Hz_StartEx(uint32 alignClkDiv);
#define Clock500Hz_Start() \
    Clock500Hz_StartEx(Clock500Hz__PA_DIV_ID)

#else

void Clock500Hz_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Clock500Hz_Stop(void);

void Clock500Hz_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Clock500Hz_GetDividerRegister(void);
uint8  Clock500Hz_GetFractionalDividerRegister(void);

#define Clock500Hz_Enable()                         Clock500Hz_Start()
#define Clock500Hz_Disable()                        Clock500Hz_Stop()
#define Clock500Hz_SetDividerRegister(clkDivider, reset)  \
    Clock500Hz_SetFractionalDividerRegister((clkDivider), 0u)
#define Clock500Hz_SetDivider(clkDivider)           Clock500Hz_SetDividerRegister((clkDivider), 1u)
#define Clock500Hz_SetDividerValue(clkDivider)      Clock500Hz_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Clock500Hz_DIV_ID     Clock500Hz__DIV_ID

#define Clock500Hz_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Clock500Hz_CTRL_REG   (*(reg32 *)Clock500Hz__CTRL_REGISTER)
#define Clock500Hz_DIV_REG    (*(reg32 *)Clock500Hz__DIV_REGISTER)

#define Clock500Hz_CMD_DIV_SHIFT          (0u)
#define Clock500Hz_CMD_PA_DIV_SHIFT       (8u)
#define Clock500Hz_CMD_DISABLE_SHIFT      (30u)
#define Clock500Hz_CMD_ENABLE_SHIFT       (31u)

#define Clock500Hz_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Clock500Hz_CMD_DISABLE_SHIFT))
#define Clock500Hz_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Clock500Hz_CMD_ENABLE_SHIFT))

#define Clock500Hz_DIV_FRAC_MASK  (0x000000F8u)
#define Clock500Hz_DIV_FRAC_SHIFT (3u)
#define Clock500Hz_DIV_INT_MASK   (0xFFFFFF00u)
#define Clock500Hz_DIV_INT_SHIFT  (8u)

#else 

#define Clock500Hz_DIV_REG        (*(reg32 *)Clock500Hz__REGISTER)
#define Clock500Hz_ENABLE_REG     Clock500Hz_DIV_REG
#define Clock500Hz_DIV_FRAC_MASK  Clock500Hz__FRAC_MASK
#define Clock500Hz_DIV_FRAC_SHIFT (16u)
#define Clock500Hz_DIV_INT_MASK   Clock500Hz__DIVIDER_MASK
#define Clock500Hz_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Clock500Hz_H) */

/* [] END OF FILE */
