/*******************************************************************************
* File Name: ClockCx2.h
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

#if !defined(CY_CLOCK_ClockCx2_H)
#define CY_CLOCK_ClockCx2_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void ClockCx2_StartEx(uint32 alignClkDiv);
#define ClockCx2_Start() \
    ClockCx2_StartEx(ClockCx2__PA_DIV_ID)

#else

void ClockCx2_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void ClockCx2_Stop(void);

void ClockCx2_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 ClockCx2_GetDividerRegister(void);
uint8  ClockCx2_GetFractionalDividerRegister(void);

#define ClockCx2_Enable()                         ClockCx2_Start()
#define ClockCx2_Disable()                        ClockCx2_Stop()
#define ClockCx2_SetDividerRegister(clkDivider, reset)  \
    ClockCx2_SetFractionalDividerRegister((clkDivider), 0u)
#define ClockCx2_SetDivider(clkDivider)           ClockCx2_SetDividerRegister((clkDivider), 1u)
#define ClockCx2_SetDividerValue(clkDivider)      ClockCx2_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define ClockCx2_DIV_ID     ClockCx2__DIV_ID

#define ClockCx2_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define ClockCx2_CTRL_REG   (*(reg32 *)ClockCx2__CTRL_REGISTER)
#define ClockCx2_DIV_REG    (*(reg32 *)ClockCx2__DIV_REGISTER)

#define ClockCx2_CMD_DIV_SHIFT          (0u)
#define ClockCx2_CMD_PA_DIV_SHIFT       (8u)
#define ClockCx2_CMD_DISABLE_SHIFT      (30u)
#define ClockCx2_CMD_ENABLE_SHIFT       (31u)

#define ClockCx2_CMD_DISABLE_MASK       ((uint32)((uint32)1u << ClockCx2_CMD_DISABLE_SHIFT))
#define ClockCx2_CMD_ENABLE_MASK        ((uint32)((uint32)1u << ClockCx2_CMD_ENABLE_SHIFT))

#define ClockCx2_DIV_FRAC_MASK  (0x000000F8u)
#define ClockCx2_DIV_FRAC_SHIFT (3u)
#define ClockCx2_DIV_INT_MASK   (0xFFFFFF00u)
#define ClockCx2_DIV_INT_SHIFT  (8u)

#else 

#define ClockCx2_DIV_REG        (*(reg32 *)ClockCx2__REGISTER)
#define ClockCx2_ENABLE_REG     ClockCx2_DIV_REG
#define ClockCx2_DIV_FRAC_MASK  ClockCx2__FRAC_MASK
#define ClockCx2_DIV_FRAC_SHIFT (16u)
#define ClockCx2_DIV_INT_MASK   ClockCx2__DIVIDER_MASK
#define ClockCx2_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_ClockCx2_H) */

/* [] END OF FILE */
