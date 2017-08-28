/*******************************************************************************
* File Name: ClockGx2.h
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

#if !defined(CY_CLOCK_ClockGx2_H)
#define CY_CLOCK_ClockGx2_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void ClockGx2_StartEx(uint32 alignClkDiv);
#define ClockGx2_Start() \
    ClockGx2_StartEx(ClockGx2__PA_DIV_ID)

#else

void ClockGx2_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void ClockGx2_Stop(void);

void ClockGx2_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 ClockGx2_GetDividerRegister(void);
uint8  ClockGx2_GetFractionalDividerRegister(void);

#define ClockGx2_Enable()                         ClockGx2_Start()
#define ClockGx2_Disable()                        ClockGx2_Stop()
#define ClockGx2_SetDividerRegister(clkDivider, reset)  \
    ClockGx2_SetFractionalDividerRegister((clkDivider), 0u)
#define ClockGx2_SetDivider(clkDivider)           ClockGx2_SetDividerRegister((clkDivider), 1u)
#define ClockGx2_SetDividerValue(clkDivider)      ClockGx2_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define ClockGx2_DIV_ID     ClockGx2__DIV_ID

#define ClockGx2_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define ClockGx2_CTRL_REG   (*(reg32 *)ClockGx2__CTRL_REGISTER)
#define ClockGx2_DIV_REG    (*(reg32 *)ClockGx2__DIV_REGISTER)

#define ClockGx2_CMD_DIV_SHIFT          (0u)
#define ClockGx2_CMD_PA_DIV_SHIFT       (8u)
#define ClockGx2_CMD_DISABLE_SHIFT      (30u)
#define ClockGx2_CMD_ENABLE_SHIFT       (31u)

#define ClockGx2_CMD_DISABLE_MASK       ((uint32)((uint32)1u << ClockGx2_CMD_DISABLE_SHIFT))
#define ClockGx2_CMD_ENABLE_MASK        ((uint32)((uint32)1u << ClockGx2_CMD_ENABLE_SHIFT))

#define ClockGx2_DIV_FRAC_MASK  (0x000000F8u)
#define ClockGx2_DIV_FRAC_SHIFT (3u)
#define ClockGx2_DIV_INT_MASK   (0xFFFFFF00u)
#define ClockGx2_DIV_INT_SHIFT  (8u)

#else 

#define ClockGx2_DIV_REG        (*(reg32 *)ClockGx2__REGISTER)
#define ClockGx2_ENABLE_REG     ClockGx2_DIV_REG
#define ClockGx2_DIV_FRAC_MASK  ClockGx2__FRAC_MASK
#define ClockGx2_DIV_FRAC_SHIFT (16u)
#define ClockGx2_DIV_INT_MASK   ClockGx2__DIVIDER_MASK
#define ClockGx2_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_ClockGx2_H) */

/* [] END OF FILE */
