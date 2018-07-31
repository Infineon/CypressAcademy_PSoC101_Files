/*******************************************************************************
* File Name: .h
* Version 1.10
*
* Description:
*  This private file provides constants and parameter values for the
*  SCB Component in I2C mode.
*  Please do not use this file or its content in your project.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation. All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_SCB_PVT_I2C_H)
#define CY_SCB_PVT_I2C_H

#include "I2C.h"


/***************************************
*     Private Function Prototypes
***************************************/

/* APIs to service INTR_I2C_EC register */
#define I2C_SetI2CExtClkInterruptMode(interruptMask) I2C_WRITE_INTR_I2C_EC_MASK(interruptMask)
#define I2C_ClearI2CExtClkInterruptSource(interruptMask) I2C_CLEAR_INTR_I2C_EC(interruptMask)
#define I2C_GetI2CExtClkInterruptSource()                (I2C_INTR_I2C_EC_REG)
#define I2C_GetI2CExtClkInterruptMode()                  (I2C_INTR_I2C_EC_MASK_REG)
#define I2C_GetI2CExtClkInterruptSourceMasked()          (I2C_INTR_I2C_EC_MASKED_REG)

/* APIs to service INTR_SPI_EC register */
#define I2C_SetSpiExtClkInterruptMode(interruptMask) I2C_WRITE_INTR_SPI_EC_MASK(interruptMask)
#define I2C_ClearSpiExtClkInterruptSource(interruptMask) I2C_CLEAR_INTR_SPI_EC(interruptMask)
#define I2C_GetExtSpiClkInterruptSource()                 (I2C_INTR_SPI_EC_REG)
#define I2C_GetExtSpiClkInterruptMode()                   (I2C_INTR_SPI_EC_MASK_REG)
#define I2C_GetExtSpiClkInterruptSourceMasked()           (I2C_INTR_SPI_EC_MASKED_REG)

#if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
    extern void I2C_SetPins(uint32 mode, uint32 subMode, uint32 uartTxRx);
#endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */

void I2C_DisableTxPinsInputBuffer(void);
void I2C_EnableTxPinsInputBuffer(void);


/**********************************
*     Vars with External Linkage
**********************************/

extern cyisraddress I2C_customIntrHandler;
extern I2C_BACKUP_STRUCT I2C_backup;

#if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common config vars */
    extern uint8 I2C_scbMode;
    extern uint8 I2C_scbEnableWake;
    extern uint8 I2C_scbEnableIntr;

    /* I2C config vars */
    extern uint8 I2C_mode;
    extern uint8 I2C_acceptAddr;

    /* SPI/UART config vars */
    extern volatile uint8 * I2C_rxBuffer;
    extern uint8   I2C_rxDataBits;
    extern uint32  I2C_rxBufferSize;

    extern volatile uint8 * I2C_txBuffer;
    extern uint8   I2C_txDataBits;
    extern uint32  I2C_txBufferSize;

    /* EZI2C config vars */
    extern uint8 I2C_numberOfAddr;
    extern uint8 I2C_subAddrSize;
#endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */

#endif /* (CY_SCB_PVT_I2C_H) */


/* [] END OF FILE */
