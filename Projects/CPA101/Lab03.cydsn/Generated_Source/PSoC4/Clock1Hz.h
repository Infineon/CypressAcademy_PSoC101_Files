/*******************************************************************************
* File Name: Clock1Hz.h
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

#if !defined(CY_CLOCK_Clock1Hz_H)
#define CY_CLOCK_Clock1Hz_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void Clock1Hz_StartEx(uint32 alignClkDiv);
#define Clock1Hz_Start() \
    Clock1Hz_StartEx(Clock1Hz__PA_DIV_ID)

#else

void Clock1Hz_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void Clock1Hz_Stop(void);

void Clock1Hz_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 Clock1Hz_GetDividerRegister(void);
uint8  Clock1Hz_GetFractionalDividerRegister(void);

#define Clock1Hz_Enable()                         Clock1Hz_Start()
#define Clock1Hz_Disable()                        Clock1Hz_Stop()
#define Clock1Hz_SetDividerRegister(clkDivider, reset)  \
    Clock1Hz_SetFractionalDividerRegister((clkDivider), 0u)
#define Clock1Hz_SetDivider(clkDivider)           Clock1Hz_SetDividerRegister((clkDivider), 1u)
#define Clock1Hz_SetDividerValue(clkDivider)      Clock1Hz_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define Clock1Hz_DIV_ID     Clock1Hz__DIV_ID

#define Clock1Hz_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define Clock1Hz_CTRL_REG   (*(reg32 *)Clock1Hz__CTRL_REGISTER)
#define Clock1Hz_DIV_REG    (*(reg32 *)Clock1Hz__DIV_REGISTER)

#define Clock1Hz_CMD_DIV_SHIFT          (0u)
#define Clock1Hz_CMD_PA_DIV_SHIFT       (8u)
#define Clock1Hz_CMD_DISABLE_SHIFT      (30u)
#define Clock1Hz_CMD_ENABLE_SHIFT       (31u)

#define Clock1Hz_CMD_DISABLE_MASK       ((uint32)((uint32)1u << Clock1Hz_CMD_DISABLE_SHIFT))
#define Clock1Hz_CMD_ENABLE_MASK        ((uint32)((uint32)1u << Clock1Hz_CMD_ENABLE_SHIFT))

#define Clock1Hz_DIV_FRAC_MASK  (0x000000F8u)
#define Clock1Hz_DIV_FRAC_SHIFT (3u)
#define Clock1Hz_DIV_INT_MASK   (0xFFFFFF00u)
#define Clock1Hz_DIV_INT_SHIFT  (8u)

#else 

#define Clock1Hz_DIV_REG        (*(reg32 *)Clock1Hz__REGISTER)
#define Clock1Hz_ENABLE_REG     Clock1Hz_DIV_REG
#define Clock1Hz_DIV_FRAC_MASK  Clock1Hz__FRAC_MASK
#define Clock1Hz_DIV_FRAC_SHIFT (16u)
#define Clock1Hz_DIV_INT_MASK   Clock1Hz__DIVIDER_MASK
#define Clock1Hz_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_Clock1Hz_H) */

/* [] END OF FILE */
