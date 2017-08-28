/*******************************************************************************
* File Name: ClockEx2.h
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

#if !defined(CY_CLOCK_ClockEx2_H)
#define CY_CLOCK_ClockEx2_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void ClockEx2_StartEx(uint32 alignClkDiv);
#define ClockEx2_Start() \
    ClockEx2_StartEx(ClockEx2__PA_DIV_ID)

#else

void ClockEx2_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void ClockEx2_Stop(void);

void ClockEx2_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 ClockEx2_GetDividerRegister(void);
uint8  ClockEx2_GetFractionalDividerRegister(void);

#define ClockEx2_Enable()                         ClockEx2_Start()
#define ClockEx2_Disable()                        ClockEx2_Stop()
#define ClockEx2_SetDividerRegister(clkDivider, reset)  \
    ClockEx2_SetFractionalDividerRegister((clkDivider), 0u)
#define ClockEx2_SetDivider(clkDivider)           ClockEx2_SetDividerRegister((clkDivider), 1u)
#define ClockEx2_SetDividerValue(clkDivider)      ClockEx2_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define ClockEx2_DIV_ID     ClockEx2__DIV_ID

#define ClockEx2_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define ClockEx2_CTRL_REG   (*(reg32 *)ClockEx2__CTRL_REGISTER)
#define ClockEx2_DIV_REG    (*(reg32 *)ClockEx2__DIV_REGISTER)

#define ClockEx2_CMD_DIV_SHIFT          (0u)
#define ClockEx2_CMD_PA_DIV_SHIFT       (8u)
#define ClockEx2_CMD_DISABLE_SHIFT      (30u)
#define ClockEx2_CMD_ENABLE_SHIFT       (31u)

#define ClockEx2_CMD_DISABLE_MASK       ((uint32)((uint32)1u << ClockEx2_CMD_DISABLE_SHIFT))
#define ClockEx2_CMD_ENABLE_MASK        ((uint32)((uint32)1u << ClockEx2_CMD_ENABLE_SHIFT))

#define ClockEx2_DIV_FRAC_MASK  (0x000000F8u)
#define ClockEx2_DIV_FRAC_SHIFT (3u)
#define ClockEx2_DIV_INT_MASK   (0xFFFFFF00u)
#define ClockEx2_DIV_INT_SHIFT  (8u)

#else 

#define ClockEx2_DIV_REG        (*(reg32 *)ClockEx2__REGISTER)
#define ClockEx2_ENABLE_REG     ClockEx2_DIV_REG
#define ClockEx2_DIV_FRAC_MASK  ClockEx2__FRAC_MASK
#define ClockEx2_DIV_FRAC_SHIFT (16u)
#define ClockEx2_DIV_INT_MASK   ClockEx2__DIVIDER_MASK
#define ClockEx2_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_ClockEx2_H) */

/* [] END OF FILE */
