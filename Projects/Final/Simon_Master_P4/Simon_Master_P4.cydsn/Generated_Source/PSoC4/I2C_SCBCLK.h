/*******************************************************************************
* File Name: I2C_SCBCLK.h
* Version 2.0
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

#if !defined(CY_CLOCK_I2C_SCBCLK_H)
#define CY_CLOCK_I2C_SCBCLK_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
*        Function Prototypes
***************************************/

void I2C_SCBCLK_Start(void);
void I2C_SCBCLK_Stop(void);

void I2C_SCBCLK_SetFractionalDividerRegister(uint16 clkDivider, uint8 clkFractional);

uint16 I2C_SCBCLK_GetDividerRegister(void);
uint8  I2C_SCBCLK_GetFractionalDividerRegister(void);

#define I2C_SCBCLK_Enable()                         I2C_SCBCLK_Start()
#define I2C_SCBCLK_Disable()                        I2C_SCBCLK_Stop()
#define I2C_SCBCLK_SetDividerRegister(clkDivider, reset)  \
                        I2C_SCBCLK_SetFractionalDividerRegister((clkDivider), 0)
#define I2C_SCBCLK_SetDivider(clkDivider)           I2C_SCBCLK_SetDividerRegister((clkDivider), 1)
#define I2C_SCBCLK_SetDividerValue(clkDivider)      I2C_SCBCLK_SetDividerRegister((clkDivider) - 1, 1)


/***************************************
*             Registers
***************************************/

#define I2C_SCBCLK_DIV_REG    (*(reg32 *)I2C_SCBCLK__REGISTER)
#define I2C_SCBCLK_ENABLE_REG I2C_SCBCLK_DIV_REG

#endif /* !defined(CY_CLOCK_I2C_SCBCLK_H) */

/* [] END OF FILE */
