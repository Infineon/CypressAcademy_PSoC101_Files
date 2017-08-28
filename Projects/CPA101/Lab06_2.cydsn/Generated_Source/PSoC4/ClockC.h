/*******************************************************************************
* File Name: ClockC.h
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

#if !defined(CY_CLOCK_ClockC_H)
#define CY_CLOCK_ClockC_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/
#if defined CYREG_PERI_DIV_CMD

void ClockC_StartEx(uint32 alignClkDiv);
#define ClockC_Start() \
    ClockC_StartEx(ClockC__PA_DIV_ID)

#else

void ClockC_Start(void);

#endif/* CYREG_PERI_DIV_CMD */

void ClockC_Stop(void);

void ClockC_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 ClockC_GetDividerRegister(void);
uint8  ClockC_GetFractionalDividerRegister(void);

#define ClockC_Enable()                         ClockC_Start()
#define ClockC_Disable()                        ClockC_Stop()
#define ClockC_SetDividerRegister(clkDivider, reset)  \
    ClockC_SetFractionalDividerRegister((clkDivider), 0u)
#define ClockC_SetDivider(clkDivider)           ClockC_SetDividerRegister((clkDivider), 1u)
#define ClockC_SetDividerValue(clkDivider)      ClockC_SetDividerRegister((clkDivider) - 1u, 1u)


/***************************************
*             Registers
***************************************/
#if defined CYREG_PERI_DIV_CMD

#define ClockC_DIV_ID     ClockC__DIV_ID

#define ClockC_CMD_REG    (*(reg32 *)CYREG_PERI_DIV_CMD)
#define ClockC_CTRL_REG   (*(reg32 *)ClockC__CTRL_REGISTER)
#define ClockC_DIV_REG    (*(reg32 *)ClockC__DIV_REGISTER)

#define ClockC_CMD_DIV_SHIFT          (0u)
#define ClockC_CMD_PA_DIV_SHIFT       (8u)
#define ClockC_CMD_DISABLE_SHIFT      (30u)
#define ClockC_CMD_ENABLE_SHIFT       (31u)

#define ClockC_CMD_DISABLE_MASK       ((uint32)((uint32)1u << ClockC_CMD_DISABLE_SHIFT))
#define ClockC_CMD_ENABLE_MASK        ((uint32)((uint32)1u << ClockC_CMD_ENABLE_SHIFT))

#define ClockC_DIV_FRAC_MASK  (0x000000F8u)
#define ClockC_DIV_FRAC_SHIFT (3u)
#define ClockC_DIV_INT_MASK   (0xFFFFFF00u)
#define ClockC_DIV_INT_SHIFT  (8u)

#else 

#define ClockC_DIV_REG        (*(reg32 *)ClockC__REGISTER)
#define ClockC_ENABLE_REG     ClockC_DIV_REG
#define ClockC_DIV_FRAC_MASK  ClockC__FRAC_MASK
#define ClockC_DIV_FRAC_SHIFT (16u)
#define ClockC_DIV_INT_MASK   ClockC__DIVIDER_MASK
#define ClockC_DIV_INT_SHIFT  (0u)

#endif/* CYREG_PERI_DIV_CMD */

#endif /* !defined(CY_CLOCK_ClockC_H) */

/* [] END OF FILE */
