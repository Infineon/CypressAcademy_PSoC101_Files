/*******************************************************************************
* File Name: I2C.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the SCB Component.
*
* Note:
*
*******************************************************************************
* Copyright 2013, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

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


/**********************************
*    Run Time Configuration Vars
**********************************/

/* Stores internal component configuration for unconfigured mode */
#if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
    /* Common config vars */
    uint8 I2C_scbMode = I2C_SCB_MODE_UNCONFIG;
    uint8 I2C_scbEnableWake;
    uint8 I2C_scbEnableIntr;

    /* I2C config vars */
    uint8 I2C_mode;
    uint8 I2C_acceptAddr;

    /* SPI/UART config vars */
    volatile uint8 * I2C_rxBuffer;
    uint8  I2C_rxDataBits;
    uint32 I2C_rxBufferSize;

    volatile uint8 * I2C_txBuffer;
    uint8  I2C_txDataBits;
    uint32 I2C_txBufferSize;

    /* EZI2C config vars */
    uint8 I2C_numberOfAddr;
    uint8 I2C_subAddrSize;
#endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */


/**********************************
*     Common SCB Vars
**********************************/

uint8 I2C_initVar = 0u;
cyisraddress I2C_customIntrHandler = NULL;


/***************************************
*    Private Function Prototypes
***************************************/

static void I2C_ScbEnableIntr(void);
static void I2C_ScbModeStop(void);


/*******************************************************************************
* Function Name: I2C_Init
********************************************************************************
*
* Summary:
*  Initializes SCB component to operate in one of selected configurations:
*  I2C, SPI, UART, EZI2C or EZSPI.
*  This function does not do any initialization when configuration is set to
*  Unconfigured SCB.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_Init(void)
{
#if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
    if(I2C_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        I2C_initVar = 0u; /* Clear init var */
    }
    else
    {
        /* Initialization was done before call */
    }

#elif(I2C_SCB_MODE_I2C_CONST_CFG)
    I2C_I2CInit();

#elif(I2C_SCB_MODE_SPI_CONST_CFG)
    I2C_SpiInit();

#elif(I2C_SCB_MODE_UART_CONST_CFG)
    I2C_UartInit();

#elif(I2C_SCB_MODE_EZI2C_CONST_CFG)
    I2C_EzI2CInit();

#endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: I2C_Enable
********************************************************************************
*
* Summary:
*  Enables SCB component operation.
*  The SCB configuration should be not changed when the component is enabled.
*  Any configuration changes should be made after disabling the component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_Enable(void)
{
#if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
    if(!I2C_SCB_MODE_UNCONFIG_RUNTM_CFG)
    {
        /* Enable SCB block, only if already configured */
        I2C_CTRL_REG |= I2C_CTRL_ENABLED;
        
        /* Enable interrupt */
        I2C_ScbEnableIntr();
    }
#else
    I2C_CTRL_REG |= I2C_CTRL_ENABLED; /* Enable SCB block */
    
    I2C_ScbEnableIntr();
#endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: I2C_Start
********************************************************************************
*
* Summary:
*  Invokes SCB_Init() and SCB_Enable().
*  After this function call the component is enabled and ready for operation.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*  I2C_initVar - used to check initial configuration, modified
*  on first function call.
*
*******************************************************************************/
void I2C_Start(void)
{
    if(0u == I2C_initVar)
    {
        I2C_initVar = 1u; /* Component was initialized */
        I2C_Init();       /* Initialize component      */
    }

    I2C_Enable();
}


/*******************************************************************************
* Function Name: I2C_Stop
********************************************************************************
*
* Summary:
*  Disables the SCB component.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_Stop(void)
{
#if(I2C_SCB_IRQ_INTERNAL)
    I2C_SCB_IRQ_Disable();     /* Disable interrupt before block */
#endif /* (I2C_SCB_IRQ_INTERNAL) */

    I2C_CTRL_REG &= (uint32) ~I2C_CTRL_ENABLED;  /* Disable SCB block */

#if(I2C_SCB_IRQ_INTERNAL)
    I2C_SCB_IRQ_ClearPending(); /* Clear pending interrupt */
#endif /* (I2C_SCB_IRQ_INTERNAL) */
    
    I2C_ScbModeStop(); /* Calls scbMode specific Stop function */
}


/*******************************************************************************
* Function Name: I2C_SetCustomInterruptHandler
********************************************************************************
*
* Summary:
*  Registers a function to be called by the internal interrupt handler.
*  First the function that is registered is called, then the internal interrupt
*  handler performs any operations such as software buffer management functions
*  before the interrupt returns.  It is user's responsibility to not break the
*  software buffer operations. Only one custom handler is supported, which is
*  the function provided by the most recent call.
*  At initialization time no custom handler is registered.
*
* Parameters:
*  func: Pointer to the function to register.
*        The value NULL indicates to remove the current custom interrupt
*        handler.
*
* Return:
*  None
*
*******************************************************************************/
void I2C_SetCustomInterruptHandler(cyisraddress func)
{
    I2C_customIntrHandler = func; /* Register interrupt handler */
}


/*******************************************************************************
* Function Name: I2C_ScbModeEnableIntr
********************************************************************************
*
* Summary:
*  Enables interrupt for specific mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void I2C_ScbEnableIntr(void)
{
#if(I2C_SCB_IRQ_INTERNAL)
    #if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
        /* Enable interrupt source */
        if(0u != I2C_scbEnableIntr)
        {
            I2C_SCB_IRQ_Enable();
        }
    #else
        I2C_SCB_IRQ_Enable();
        
    #endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */
#endif /* (I2C_SCB_IRQ_INTERNAL) */
}


/*******************************************************************************
* Function Name: I2C_ScbModeEnableIntr
********************************************************************************
*
* Summary:
*  Calls Stop function for specific operation mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
static void I2C_ScbModeStop(void)
{
#if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
    if(I2C_SCB_MODE_I2C_RUNTM_CFG)
    {
        I2C_I2CStop();
    }
    else if(I2C_SCB_MODE_EZI2C_RUNTM_CFG)
    {
        I2C_EzI2CStop();
    }
    else
    {
        /* None of modes above */
    }
#elif(I2C_SCB_MODE_I2C_CONST_CFG)
    I2C_I2CStop();

#elif(I2C_SCB_MODE_EZI2C_CONST_CFG)
    I2C_EzI2CStop();

#endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */
}


#if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
    /*******************************************************************************
    * Function Name: I2C_SetPins
    ********************************************************************************
    *
    * Summary:
    *  Sets pins settings accordingly to selected operation mode.
    *  Only available in Unconfigured operation mode. The mode specific
    *  initialization function calls it.
    *  Pins configuration is set by PSoC Creator when specific mode of operation
    *  selected in design time.
    *
    * Parameters:
    *  mode:      Mode of SCB operation.
    *  subMode:   Submode of SCB operation. It is only required for SPI and UART
    *             modes.
    *  uartTxRx:  Direction for UART.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void I2C_SetPins(uint32 mode, uint32 subMode, uint32 uartTxRx)
    {
        uint32 hsiomSel[I2C_SCB_PINS_NUMBER];
        uint32 pinsDm  [I2C_SCB_PINS_NUMBER];
        uint32 i;

        /* Make all unused */
        for(i = 0u; i < I2C_SCB_PINS_NUMBER; i++)
        {
            hsiomSel[i] = I2C_HSIOM_DEF_SEL;
            pinsDm[i]   = I2C_PIN_DM_ALG_HIZ;
        }

        /* Choice the Dm and HSIOM */
        if((I2C_SCB_MODE_I2C   == mode) ||
           (I2C_SCB_MODE_EZI2C == mode))
        {
            hsiomSel[I2C_MOSI_SCL_RX_PIN_INDEX] = I2C_HSIOM_I2C_SEL;
            hsiomSel[I2C_MISO_SDA_TX_PIN_INDEX] = I2C_HSIOM_I2C_SEL;

            pinsDm[I2C_MOSI_SCL_RX_PIN_INDEX] = I2C_PIN_DM_OD_LO;
            pinsDm[I2C_MISO_SDA_TX_PIN_INDEX] = I2C_PIN_DM_OD_LO;
        }
        else if(I2C_SCB_MODE_SPI == mode)
        {
            hsiomSel[I2C_MOSI_SCL_RX_PIN_INDEX] = I2C_HSIOM_SPI_SEL;
            hsiomSel[I2C_MISO_SDA_TX_PIN_INDEX] = I2C_HSIOM_SPI_SEL;
            hsiomSel[I2C_SCLK_PIN_INDEX]        = I2C_HSIOM_SPI_SEL;

            if(I2C_SPI_SLAVE == subMode)
            {
                /* Slave */
                pinsDm[I2C_MOSI_SCL_RX_PIN_INDEX] = I2C_PIN_DM_DIG_HIZ;
                pinsDm[I2C_MISO_SDA_TX_PIN_INDEX] = I2C_PIN_DM_STRONG;
                pinsDm[I2C_SCLK_PIN_INDEX]        = I2C_PIN_DM_DIG_HIZ;

            #if(I2C_SS0_PIN)
                /* Only SS0 is valid choice for Slave */
                hsiomSel[I2C_SS0_PIN_INDEX] = I2C_HSIOM_SPI_SEL;
                pinsDm  [I2C_SS0_PIN_INDEX] = I2C_PIN_DM_DIG_HIZ;
            #endif /* (I2C_SS1_PIN) */
            }
            else /* (Master) */
            {
                pinsDm[I2C_MOSI_SCL_RX_PIN_INDEX] = I2C_PIN_DM_STRONG;
                pinsDm[I2C_MISO_SDA_TX_PIN_INDEX] = I2C_PIN_DM_DIG_HIZ;
                pinsDm[I2C_SCLK_PIN_INDEX]        = I2C_PIN_DM_STRONG;

            #if(I2C_SS0_PIN)
                hsiomSel[I2C_SS0_PIN_INDEX] = I2C_HSIOM_SPI_SEL;
                pinsDm  [I2C_SS0_PIN_INDEX] = I2C_PIN_DM_STRONG;
            #endif /* (I2C_SS0_PIN) */

            #if(I2C_SS1_PIN)
                hsiomSel[I2C_SS1_PIN_INDEX] = I2C_HSIOM_SPI_SEL;
                pinsDm  [I2C_SS1_PIN_INDEX] = I2C_PIN_DM_STRONG;
            #endif /* (I2C_SS1_PIN) */

            #if(I2C_SS2_PIN)
                hsiomSel[I2C_SS2_PIN_INDEX] = I2C_HSIOM_SPI_SEL;
                pinsDm  [I2C_SS2_PIN_INDEX] = I2C_PIN_DM_STRONG;
            #endif /* (I2C_SS2_PIN) */

            #if(I2C_SS3_PIN)
                hsiomSel[I2C_SS3_PIN_INDEX] = I2C_HSIOM_SPI_SEL;
                pinsDm  [I2C_SS3_PIN_INDEX] = I2C_PIN_DM_STRONG;
            #endif /* (I2C_SS2_PIN) */
            }
        }
        else /* UART */
        {
            if(I2C_UART_MODE_SMARTCARD == subMode)
            {
                /* SmartCard */
                hsiomSel[I2C_MISO_SDA_TX_PIN_INDEX] = I2C_HSIOM_UART_SEL;
                pinsDm  [I2C_MISO_SDA_TX_PIN_INDEX] = I2C_PIN_DM_OD_LO;
            }
            else /* Standard or IrDA */
            {
                if(0u != (I2C_UART_RX & uartTxRx))
                {
                    hsiomSel[I2C_MOSI_SCL_RX_PIN_INDEX] = I2C_HSIOM_UART_SEL;
                    pinsDm  [I2C_MOSI_SCL_RX_PIN_INDEX] = I2C_PIN_DM_DIG_HIZ;
                }

                if(0u != (I2C_UART_TX & uartTxRx))
                {
                    hsiomSel[I2C_MISO_SDA_TX_PIN_INDEX] = I2C_HSIOM_UART_SEL;
                    pinsDm  [I2C_MISO_SDA_TX_PIN_INDEX] = I2C_PIN_DM_STRONG;
                }
            }
        }

        /* Condfigure pins: set HSIOM and DM */
        /* Condfigure pins: DR registers configuration remains unchanged for cyfitter_cfg() */

    #if(I2C_MOSI_SCL_RX_PIN)
        I2C_SET_HSIOM_SEL(I2C_MOSI_SCL_RX_HSIOM_REG,
                                       I2C_MOSI_SCL_RX_HSIOM_MASK,
                                       I2C_MOSI_SCL_RX_HSIOM_POS,
                                       hsiomSel[I2C_MOSI_SCL_RX_PIN_INDEX]);
    #endif /* (I2C_MOSI_SCL_RX_PIN) */

    #if(I2C_MOSI_SCL_RX_WAKE_PIN)
        I2C_SET_HSIOM_SEL(I2C_MOSI_SCL_RX_WAKE_HSIOM_REG,
                                       I2C_MOSI_SCL_RX_WAKE_HSIOM_MASK,
                                       I2C_MOSI_SCL_RX_WAKE_HSIOM_POS,
                                       hsiomSel[I2C_MOSI_SCL_RX_WAKE_PIN_INDEX]);
    #endif /* (I2C_MOSI_SCL_RX_WAKE_PIN) */

    #if(I2C_MISO_SDA_TX_PIN)
        I2C_SET_HSIOM_SEL(I2C_MISO_SDA_TX_HSIOM_REG,
                                       I2C_MISO_SDA_TX_HSIOM_MASK,
                                       I2C_MISO_SDA_TX_HSIOM_POS,
                                       hsiomSel[I2C_MISO_SDA_TX_PIN_INDEX]);
    #endif /* (I2C_MOSI_SCL_RX_PIN) */

    #if(I2C_SCLK_PIN)
        I2C_SET_HSIOM_SEL(I2C_SCLK_HSIOM_REG, I2C_SCLK_HSIOM_MASK,
                                       I2C_SCLK_HSIOM_POS, hsiomSel[I2C_SCLK_PIN_INDEX]);
    #endif /* (I2C_SCLK_PIN) */

    #if(I2C_SS0_PIN)
        I2C_SET_HSIOM_SEL(I2C_SS0_HSIOM_REG, I2C_SS0_HSIOM_MASK,
                                       I2C_SS0_HSIOM_POS, hsiomSel[I2C_SS0_PIN_INDEX]);
    #endif /* (I2C_SS1_PIN) */

    #if(I2C_SS1_PIN)
        I2C_SET_HSIOM_SEL(I2C_SS1_HSIOM_REG, I2C_SS1_HSIOM_MASK,
                                       I2C_SS1_HSIOM_POS, hsiomSel[I2C_SS1_PIN_INDEX]);
    #endif /* (I2C_SS1_PIN) */

    #if(I2C_SS2_PIN)
        I2C_SET_HSIOM_SEL(I2C_SS2_HSIOM_REG, I2C_SS2_HSIOM_MASK,
                                       I2C_SS2_HSIOM_POS, hsiomSel[I2C_SS2_PIN_INDEX]);
    #endif /* (I2C_SS2_PIN) */

    #if(I2C_SS3_PIN)
        I2C_SET_HSIOM_SEL(I2C_SS3_HSIOM_REG,  I2C_SS3_HSIOM_MASK,
                                       I2C_SS3_HSIOM_POS, hsiomSel[I2C_SS3_PIN_INDEX]);
    #endif /* (I2C_SS3_PIN) */



    #if(I2C_MOSI_SCL_RX_PIN)
        I2C_spi_mosi_i2c_scl_uart_rx_SetDriveMode((uint8)
                                                               pinsDm[I2C_MOSI_SCL_RX_PIN_INDEX]);
    #endif /* (I2C_MOSI_SCL_RX_PIN) */

    #if(I2C_MOSI_SCL_RX_WAKE_PIN)
    I2C_spi_mosi_i2c_scl_uart_rx_wake_SetDriveMode((uint8)
                                                               pinsDm[I2C_MOSI_SCL_RX_WAKE_PIN_INDEX]);

    /* Set interrupt on rising edge */
    I2C_SET_INCFG_TYPE(I2C_MOSI_SCL_RX_WAKE_INTCFG_REG,
                                    I2C_MOSI_SCL_RX_WAKE_INTCFG_TYPE_MASK,
                                    I2C_MOSI_SCL_RX_WAKE_INTCFG_TYPE_POS,
                                    I2C_INTCFG_TYPE_FALLING_EDGE);

    #endif /* (I2C_MOSI_SCL_RX_WAKE_PIN) */

    #if(I2C_MISO_SDA_TX_PIN)
        I2C_spi_miso_i2c_sda_uart_tx_SetDriveMode((uint8)
                                                                    pinsDm[I2C_MISO_SDA_TX_PIN_INDEX]);
    #endif /* (I2C_MOSI_SCL_RX_PIN) */

    #if(I2C_SCLK_PIN)
        I2C_spi_sclk_SetDriveMode((uint8) pinsDm[I2C_SCLK_PIN_INDEX]);
    #endif /* (I2C_SCLK_PIN) */

    #if(I2C_SS0_PIN)
        I2C_spi_ss0_SetDriveMode((uint8) pinsDm[I2C_SS0_PIN_INDEX]);
    #endif /* (I2C_SS0_PIN) */

    #if(I2C_SS1_PIN)
        I2C_spi_ss1_SetDriveMode((uint8) pinsDm[I2C_SS1_PIN_INDEX]);
    #endif /* (I2C_SS1_PIN) */

    #if(I2C_SS2_PIN)
        I2C_spi_ss2_SetDriveMode((uint8) pinsDm[I2C_SS2_PIN_INDEX]);
    #endif /* (I2C_SS2_PIN) */

    #if(I2C_SS3_PIN)
        I2C_spi_ss3_SetDriveMode((uint8) pinsDm[I2C_SS3_PIN_INDEX]);
    #endif /* (I2C_SS3_PIN) */
    }

#endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */


/* [] END OF FILE */
