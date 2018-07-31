/*******************************************************************************
* File Name: I2C_PM.c
* Version 1.10
*
* Description:
*  This file provides the source code to the Power Management support for
*  the SCB Component.
*
* Note:
*
********************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "I2C.h"
#include "I2C_PVT.h"

#if(I2C_SCB_MODE_I2C_INC)
    #include "I2C_I2C_PVT.h"
#endif /* (I2C_SCB_MODE_I2C_INC) */

#if(I2C_SCB_MODE_EZI2C_INC)
    #include "I2C_EZI2C_PVT.h"
#endif /* (I2C_SCB_MODE_EZI2C_INC) */

#if(I2C_SCB_MODE_SPI_INC || I2C_SCB_MODE_UART_INC)
    #include "I2C_SPI_UART_PVT.h"
#endif /* (I2C_SCB_MODE_SPI_INC || I2C_SCB_MODE_UART_INC) */


/***************************************
*   Backup Structure declaration
***************************************/

I2C_BACKUP_STRUCT I2C_backup =
{
    0u, /* enableState */
};


/*******************************************************************************
* Function Name: I2C_Sleep
********************************************************************************
*
* Summary:
*  Calls SaveConfig function fucntion for selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_Sleep(void)
{
#if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)

    if(0u != I2C_scbEnableWake)
    {
        if(I2C_SCB_MODE_I2C_RUNTM_CFG)
        {
            I2C_I2CSaveConfig();
        }
        else if(I2C_SCB_MODE_SPI_RUNTM_CFG)
        {
            I2C_SpiSaveConfig();
        }
        else if(I2C_SCB_MODE_UART_RUNTM_CFG)
        {
            I2C_UartSaveConfig();
        }
        else if(I2C_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            I2C_EzI2CSaveConfig();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    }
    else
    {
        I2C_backup.enableState = (uint8) I2C_GET_CTRL_ENABLED;
        
        if(0u != I2C_backup.enableState)
        {
            I2C_Stop();
        }
    }
    
    I2C_DisableTxPinsInputBuffer();
    
#else
    
    #if defined (I2C_I2C_WAKE_ENABLE_CONST) && (I2C_I2C_WAKE_ENABLE_CONST)
        I2C_I2CSaveConfig();
        
    #elif defined (I2C_SPI_WAKE_ENABLE_CONST) && (I2C_SPI_WAKE_ENABLE_CONST)
        I2C_SpiSaveConfig();
        
    #elif defined (I2C_UART_WAKE_ENABLE_CONST) && (I2C_UART_WAKE_ENABLE_CONST)
        I2C_UartSaveConfig();
        
    #elif defined (I2C_EZI2C_WAKE_ENABLE_CONST) && (I2C_EZI2C_WAKE_ENABLE_CONST)
        I2C_EzI2CSaveConfig();
    
    #else
        
        I2C_backup.enableState = (uint8) I2C_GET_CTRL_ENABLED;
        
        /* Check enable state */
        if(0u != I2C_backup.enableState)
        {
            I2C_Stop();
        }
        
    #endif /* defined (I2C_SCB_MODE_I2C_CONST_CFG) && (I2C_I2C_WAKE_ENABLE_CONST) */
    
    I2C_DisableTxPinsInputBuffer();
    
#endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: I2C_Wakeup
********************************************************************************
*
* Summary:
*  Calls RestoreConfig function fucntion for selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_Wakeup(void)
{
#if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)

    I2C_EnableTxPinsInputBuffer();
        
    if(0u != I2C_scbEnableWake)
    {
        if(I2C_SCB_MODE_I2C_RUNTM_CFG)
        {
            I2C_I2CRestoreConfig();
        }
        else if(I2C_SCB_MODE_SPI_RUNTM_CFG)
        {
            I2C_SpiRestoreConfig();
        }
        else if(I2C_SCB_MODE_UART_RUNTM_CFG)
        {
            I2C_UartRestoreConfig();
        }
        else if(I2C_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            I2C_EzI2CRestoreConfig();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    }
    else
    {    
        /* Restore enable state */
        if(0u != I2C_backup.enableState)
        {
            I2C_Enable();
        }
    }

#else
    
    I2C_EnableTxPinsInputBuffer();
        
    #if defined (I2C_I2C_WAKE_ENABLE_CONST) && (I2C_I2C_WAKE_ENABLE_CONST)
        I2C_I2CRestoreConfig();
        
    #elif defined (I2C_SPI_WAKE_ENABLE_CONST) && (I2C_SPI_WAKE_ENABLE_CONST)
        I2C_SpiRestoreConfig();
        
    #elif defined (I2C_UART_WAKE_ENABLE_CONST) && (I2C_UART_WAKE_ENABLE_CONST)
        I2C_UartRestoreConfig();
        
    #elif defined (I2C_EZI2C_WAKE_ENABLE_CONST) && (I2C_EZI2C_WAKE_ENABLE_CONST)
        I2C_EzI2CRestoreConfig();
    
    #else
        /* Check enable state */
        if(0u != I2C_backup.enableState)
        {
            I2C_Enable();
        }
        
    #endif /* (I2C_I2C_WAKE_ENABLE_CONST) */

#endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: I2C_DisableTxPinsInputBuffer
********************************************************************************
*
* Summary:
*  Disables input buffers for TX pins. This action removes leakage current while
*  low power mode (Cypress ID 149635).
*   SCB mode is I2C and EZI2C: bus is pulled-up. Leave pins as it is.
*   SCB mode SPI:
*     Slave  - disable input buffer for MISO pin.
*     Master - disable input buffer for all pins.
*   SCB mode SmartCard: 
*     Standard and IrDA - disable input buffer for TX pin.
*     SmartCard - RX_TX pin is pulled-up. Leave pin as it is.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_DisableTxPinsInputBuffer(void)
{
#if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
    
    /* SCB mode is I2C and EZI2C: bus is pulled-up. Does nothing */
       
    if(I2C_SCB_MODE_SPI_RUNTM_CFG)
    {
        if(0u != (I2C_SPI_CTRL_REG & I2C_SPI_CTRL_MASTER))
        /* SPI Master */
        {
        #if(I2C_MOSI_SCL_RX_WAKE_PIN)
            I2C_spi_mosi_i2c_scl_uart_rx_wake_INP_DIS |= \
                                                                I2C_spi_mosi_i2c_scl_uart_rx_wake_MASK;
        #endif /* (I2C_MOSI_SCL_RX_WAKE_PIN) */

        #if(I2C_MOSI_SCL_RX_PIN)
            I2C_spi_mosi_i2c_scl_uart_rx_INP_DIS |= I2C_spi_mosi_i2c_scl_uart_rx_MASK;
        #endif /* (I2C_MOSI_SCL_RX_PIN) */

        #if(I2C_MISO_SDA_TX_PIN)
            I2C_spi_miso_i2c_sda_uart_tx_INP_DIS |= I2C_spi_miso_i2c_sda_uart_tx_MASK;
        #endif /* (I2C_MISO_SDA_TX_PIN_PIN) */

        #if(I2C_SCLK_PIN)
            I2C_spi_sclk_INP_DIS |= I2C_spi_sclk_MASK;
        #endif /* (I2C_SCLK_PIN) */

        #if(I2C_SS0_PIN)
            I2C_spi_ss0_INP_DIS |= I2C_spi_ss0_MASK;
        #endif /* (I2C_SS1_PIN) */

        #if(I2C_SS1_PIN)
            I2C_spi_ss1_INP_DIS |= I2C_spi_ss1_MASK;
        #endif /* (I2C_SS1_PIN) */

        #if(I2C_SS2_PIN)
            I2C_spi_ss2_INP_DIS |= I2C_spi_ss2_MASK;
        #endif /* (I2C_SS2_PIN) */

        #if(I2C_SS3_PIN)
            I2C_spi_ss3_INP_DIS |= I2C_spi_ss3_MASK;
        #endif /* (I2C_SS3_PIN) */
        }
        else
        /* SPI Slave */
        {
        #if(I2C_MISO_SDA_TX_PIN)
            I2C_spi_miso_i2c_sda_uart_tx_INP_DIS |= I2C_spi_miso_i2c_sda_uart_tx_MASK;
        #endif /* (I2C_MISO_SDA_TX_PIN_PIN) */
        }
    }
    else if (I2C_SCB_MODE_UART_RUNTM_CFG)
    {
        if(I2C_UART_CTRL_MODE_UART_SMARTCARD != 
            (I2C_UART_CTRL_REG & I2C_UART_CTRL_MODE_MASK))
        /* UART Standard or IrDA */
        {
        #if(I2C_MISO_SDA_TX_PIN)
            I2C_spi_miso_i2c_sda_uart_tx_INP_DIS |= I2C_spi_miso_i2c_sda_uart_tx_MASK;
        #endif /* (I2C_MISO_SDA_TX_PIN_PIN) */
        }
    }
    else
    {
        /* Does nothing */
    }
    
#else
    
    /* SCB mode is I2C and EZI2C: bus is pulled-up. Does nothing */
        
    /* SCB mode is SPI Master */
    #if(I2C_SPI_MASTER_PINS)
        I2C_sclk_m_INP_DIS |= I2C_sclk_m_MASK;
        I2C_mosi_m_INP_DIS |= I2C_mosi_m_MASK;
        I2C_miso_m_INP_DIS |= I2C_miso_m_MASK;
    #endif /* (I2C_SPI_MASTER_PINS) */

    #if(I2C_SPI_MASTER_SS0_PIN)
        I2C_ss0_m_INP_DIS |= I2C_ss0_m_MASK;
    #endif /* (I2C_SPI_MASTER_SS0_PIN) */

    #if(I2C_SPI_MASTER_SS1_PIN)
        I2C_ss1_m_INP_DIS |= I2C_ss1_m_MASK;
    #endif /* (I2C_SPI_MASTER_SS1_PIN) */

    #if(I2C_SPI_MASTER_SS2_PIN)
        I2C_ss2_m_INP_DIS |= I2C_ss2_m_MASK;
    #endif /* (I2C_SPI_MASTER_SS2_PIN) */

    #if(I2C_SPI_MASTER_SS3_PIN)
        I2C_ss3_m_INP_DIS |= I2C_ss3_m_MASK;
    #endif /* (I2C_SPI_MASTER_SS3_PIN) */
    
    /* SCB mode is SPI Slave */
    #if(I2C_SPI_SLAVE_PINS)
        I2C_miso_s_INP_DIS |= I2C_miso_s_MASK;
    #endif /* (I2C_SPI_SLAVE_PINS) */

    /* SCB mode is UART */
    #if(I2C_UART_TX_PIN)
        I2C_tx_INP_DIS |= I2C_tx_MASK;
    #endif /* (I2C_UART_TX_PIN) */

#endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: I2C_EnableTxPinsInputBuffer
********************************************************************************
*
* Summary:
*  Enables input buffers for TX pins. Restore changes done byte
*I2C_DisableTxPinsInputBuffer.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_EnableTxPinsInputBuffer(void)
{
#if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
    if(I2C_SCB_MODE_SPI_RUNTM_CFG)
    {
        if(0u != (I2C_SPI_CTRL_REG & I2C_SPI_CTRL_MASTER))
        /* SPI Master */
        {
        #if(I2C_MOSI_SCL_RX_WAKE_PIN)
            I2C_spi_mosi_i2c_scl_uart_rx_wake_INP_DIS &= \
                                            (uint32) ~((uint32) I2C_spi_mosi_i2c_scl_uart_rx_wake_MASK);
        #endif /* (I2C_MOSI_SCL_RX_WAKE_PIN) */

        #if(I2C_MOSI_SCL_RX_PIN)
            I2C_spi_mosi_i2c_scl_uart_rx_INP_DIS &= \
                                            (uint32) ~((uint32) I2C_spi_mosi_i2c_scl_uart_rx_MASK);
        #endif /* (I2C_MOSI_SCL_RX_PIN) */

        #if(I2C_MISO_SDA_TX_PIN)
            I2C_spi_miso_i2c_sda_uart_tx_INP_DIS &= \
                                            (uint32) ~((uint32) I2C_spi_miso_i2c_sda_uart_tx_MASK);
        #endif /* (I2C_MISO_SDA_TX_PIN_PIN) */

        #if(I2C_SCLK_PIN)
            I2C_spi_sclk_INP_DIS &= (uint32) ~((uint32) I2C_spi_sclk_MASK);
        #endif /* (I2C_SCLK_PIN) */

        #if(I2C_SS0_PIN)
            I2C_spi_ss0_INP_DIS &= (uint32) ~((uint32) I2C_spi_ss0_MASK);
        #endif /* (I2C_SS1_PIN) */

        #if(I2C_SS1_PIN)
            I2C_spi_ss1_INP_DIS &= (uint32) ~((uint32) I2C_spi_ss1_MASK);
        #endif /* (I2C_SS1_PIN) */

        #if(I2C_SS2_PIN)
            I2C_spi_ss2_INP_DIS &= (uint32) ~((uint32) I2C_spi_ss2_MASK);
        #endif /* (I2C_SS2_PIN) */

        #if(I2C_SS3_PIN)
            I2C_spi_ss3_INP_DIS &= (uint32) ~((uint32) I2C_spi_ss3_MASK);
        #endif /* (I2C_SS3_PIN) */
        }
        else
        /* SPI Slave */
        {
        #if(I2C_MISO_SDA_TX_PIN)
            I2C_spi_miso_i2c_sda_uart_tx_INP_DIS &= \
                                                (uint32) ~((uint32) I2C_spi_miso_i2c_sda_uart_tx_MASK);
        #endif /* (I2C_MISO_SDA_TX_PIN_PIN) */
        }
    }
    else if (I2C_SCB_MODE_UART_RUNTM_CFG)
    {
        if(I2C_UART_CTRL_MODE_UART_SMARTCARD != 
                (I2C_UART_CTRL_REG & I2C_UART_CTRL_MODE_MASK))
        /* UART Standard or IrDA */
        {
        #if(I2C_MISO_SDA_TX_PIN)
            I2C_spi_miso_i2c_sda_uart_tx_INP_DIS &= \
                                                (uint32) ~((uint32) I2C_spi_miso_i2c_sda_uart_tx_MASK);
        #endif /* (I2C_MISO_SDA_TX_PIN_PIN) */
        }
    }
    else
    {
        /* Does nothing */
    }
    
#else
        
    /* SCB mode is SPI Master */
    #if(I2C_SPI_MASTER_PINS)
        I2C_sclk_m_INP_DIS &= (uint32) ~((uint32) I2C_sclk_m_MASK);
        I2C_mosi_m_INP_DIS &= (uint32) ~((uint32) I2C_mosi_m_MASK);
        I2C_miso_m_INP_DIS &= (uint32) ~((uint32) I2C_miso_m_MASK);
    #endif /* (I2C_SPI_MASTER_PINS) */

    #if(I2C_SPI_MASTER_SS0_PIN)
        I2C_ss0_m_INP_DIS &= (uint32) ~((uint32) I2C_ss0_m_MASK);
    #endif /* (I2C_SPI_MASTER_SS0_PIN) */

    #if(I2C_SPI_MASTER_SS1_PIN)
        I2C_ss1_m_INP_DIS &= (uint32) ~((uint32) I2C_ss1_m_MASK);
    #endif /* (I2C_SPI_MASTER_SS1_PIN) */

    #if(I2C_SPI_MASTER_SS2_PIN)
        I2C_ss2_m_INP_DIS &= (uint32) ~((uint32) I2C_ss2_m_MASK);
    #endif /* (I2C_SPI_MASTER_SS2_PIN) */

    #if(I2C_SPI_MASTER_SS3_PIN)
        I2C_ss3_m_INP_DIS &= (uint32) ~((uint32) I2C_ss3_m_MASK);
    #endif /* (I2C_SPI_MASTER_SS3_PIN) */
    
    /* SCB mode is SPI Slave */
    #if(I2C_SPI_SLAVE_PINS)
        I2C_miso_s_INP_DIS &= (uint32) ~((uint32) I2C_miso_s_MASK);
    #endif /* (I2C_SPI_SLAVE_PINS) */

    /* SCB mode is UART */
    #if(I2C_UART_TX_PIN)
        I2C_tx_INP_DIS &= (uint32) ~((uint32) I2C_tx_MASK);
    #endif /* (I2C_UART_TX_PIN) */

#endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/* [] END OF FILE */
