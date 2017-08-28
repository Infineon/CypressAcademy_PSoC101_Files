/*******************************************************************************
* File Name: Clock2Hz.h
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

#if !defined(CY_CLOCK_Clock2Hz_H)
#define CY_CLOCK_Clock2Hz_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Clock2Hz_StartEx(uint32 alignClkDiv);
#define Clock2Hz_Start() \
    Clock2Hz_StartEx(Clock2Hz__PA_DIV_ID)

#else

void Clock2Hz_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Clock2Hz_Stop(void);

void Clock2Hz_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Clock2Hz_GetDividerRegister(void);
uint8  Clock2Hz_GetFractionalDividerRegister(void);

#define Clock2Hz_Enable()                         Clock2Hz_Start()
#define Clock2Hz_Disable()                        Clock2Hz_Stop()
#define Clock2Hz_SetDividerRegister(clkDivider, reset)  \
    Clock2Hz_SetFractionalDividerRegister((clkDivider), 0u)
#define Clock2Hz_SetDivider(clkDivider)           Clock2Hz_SetDividerRegister((clkDivider), 1u)
#define Clock2Hz_SetDividerValue(clkDivider)      Clock2Hz_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Clock2Hz_DIV_ID     Clock2Hz__DIV_ID

#define Clock2Hz_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Clock2Hz_CTRL_REG   (*(reg32 *)Clock2Hz__CTRL_REGISTER)
#define Clock2Hz_DIV_REG    (*(reg32 *)Clock2Hz__DIV_REGISTER)

#define Clock2Hz_CMD_DIV_SHIFT          (0u)
#define Clock2Hz_CMD_PA_DIV_SHIFT       (8u)
#define Clock2Hz_CMD_DISABLE_SHIFT      (30u)
#define Clock2Hz_CMD_ENABLE_SHIFT       (31u)

#define Clock2Hz_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Clock2Hz_CMD_DISABLE_SHIFT))
#define Clock2Hz_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Clock2Hz_CMD_ENABLE_SHIFT))

#define Clock2Hz_DIV_FRAC_MASK  (0x000000F8u)
#define Clock2Hz_DIV_FRAC_SHIFT (3u)
#define Clock2Hz_DIV_INT_MASK   (0xFFFFFF00u)
#define Clock2Hz_DIV_INT_SHIFT  (8u)

#else 

#define Clock2Hz_DIV_REG        (*(reg32 *)Clock2Hz__REGISTER)
#define Clock2Hz_ENABLE_REG     Clock2Hz_DIV_REG
#define Clock2Hz_DIV_FRAC_MASK  Clock2Hz__FRAC_MASK
#define Clock2Hz_DIV_FRAC_SHIFT (16u)
#define Clock2Hz_DIV_INT_MASK   Clock2Hz__DIVIDER_MASK
#define Clock2Hz_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Clock2Hz_H) */

/* [] END OF FILE */
