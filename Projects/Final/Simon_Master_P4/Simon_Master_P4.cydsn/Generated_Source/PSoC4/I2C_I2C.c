/*******************************************************************************
* File Name: I2C_I2C.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the SCB Component in
*  I2C mode.
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
#include "I2C_I2C_PVT.h"


/***************************************
*      I2C Private Vars
***************************************/

volatile uint8 I2C_state;  /* Current state of I2C FSM */


#if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)

    /***************************************
    *  Config Structure Initialization
    ***************************************/

    /* Constant configuration of I2C */
    const I2C_I2C_INIT_STRUCT I2C_configI2C =
    {
        I2C_I2C_MODE,
        I2C_I2C_OVS_FACTOR_LOW,
        I2C_I2C_OVS_FACTOR_HIGH,
        I2C_I2C_MEDIAN_FILTER_ENABLE,
        I2C_I2C_SLAVE_ADDRESS,
        I2C_I2C_SLAVE_ADDRESS_MASK,
        I2C_I2C_ACCEPT_ADDRESS,
        I2C_I2C_WAKE_ENABLE
    };

    /*******************************************************************************
    * Function Name: I2C_I2CInit
    ********************************************************************************
    *
    * Summary:
    *  Configures the SCB for I2C operation.
    *
    * Parameters:
    *  config:  Pointer to a structure that contains the following ordered list of
    *           fields. These fields match the selections available in the
    *           customizer.
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void I2C_I2CInit(const I2C_I2C_INIT_STRUCT *config)
    {
        if(NULL == config)
        {
            CYASSERT(0u != 0u); /* Halt execution due bad fucntion parameter */
        }
        else
        {
            /* Configure pins */
            I2C_SetPins(I2C_SCB_MODE_I2C, I2C_DUMMY_PARAM,
                                                                    I2C_DUMMY_PARAM);

            /* Store internal configuration */
            I2C_scbMode       = (uint8) I2C_SCB_MODE_I2C;
            I2C_scbEnableWake = (uint8) config->enableWake;
            I2C_scbEnableIntr = (uint8) I2C_SCB_IRQ_INTERNAL;

            I2C_mode          = (uint8) config->mode;
            I2C_acceptAddr    = (uint8) config->acceptAddr;

            /* Configure I2C interface */
            I2C_CTRL_REG     = I2C_GET_CTRL_ADDR_ACCEPT(config->acceptAddr) |
                                            I2C_GET_CTRL_EC_AM_MODE (config->enableWake);

            I2C_I2C_CTRL_REG = I2C_GET_I2C_CTRL_HIGH_PHASE_OVS(config->oversampleHigh) |
                                            I2C_GET_I2C_CTRL_LOW_PHASE_OVS (config->oversampleLow)  |
                                            I2C_GET_I2C_CTRL_SL_MSTR_MODE  (config->mode)           |
                                            I2C_I2C_CTRL;

            /* Adjust SDA filter settigns */
            I2C_SET_I2C_CFG_SDA_FILT_TRIM(I2C_EC_AM_I2C_CFG_SDA_FILT_TRIM);


            /* Configure RX direction */
            I2C_RX_CTRL_REG      = I2C_GET_RX_CTRL_MEDIAN(config->enableMedianFilter) |
                                                I2C_I2C_RX_CTRL;
            I2C_RX_FIFO_CTRL_REG = I2C_CLEAR_REG;

            /* Set default address and mask */
            I2C_RX_MATCH_REG    = ((I2C_I2C_SLAVE) ?
                                                (I2C_GET_I2C_8BIT_ADDRESS(config->slaveAddr) |
                                                 I2C_GET_RX_MATCH_MASK(config->slaveAddrMask)) :
                                                (I2C_CLEAR_REG));


            /* Configure TX direction */
            I2C_TX_CTRL_REG      = I2C_I2C_TX_CTRL;
            I2C_TX_FIFO_CTRL_REG = I2C_CLEAR_REG;

            /* Configure interrupt with I2C handler */
            I2C_SCB_IRQ_Disable();
            I2C_SCB_IRQ_SetVector(&I2C_I2C_ISR);
            I2C_SCB_IRQ_SetPriority((uint8)I2C_SCB_IRQ_INTC_PRIOR_NUMBER);

            
            /* Configure interrupt sources */
            I2C_INTR_I2C_EC_MASK_REG = I2C_NO_INTR_SOURCES;
            I2C_INTR_SPI_EC_MASK_REG = I2C_NO_INTR_SOURCES;
            I2C_INTR_RX_MASK_REG     = I2C_NO_INTR_SOURCES;
            I2C_INTR_TX_MASK_REG     = I2C_NO_INTR_SOURCES;

            I2C_INTR_SLAVE_MASK_REG  = ((I2C_I2C_SLAVE) ?
                                                     (I2C_I2C_INTR_SLAVE_MASK) :
                                                     (I2C_CLEAR_REG));

            I2C_INTR_MASTER_MASK_REG = ((I2C_I2C_MASTER) ?
                                                     (I2C_I2C_INTR_MASTER_MASK) :
                                                     (I2C_CLEAR_REG));

            /* Configure global variables */
            I2C_state = I2C_I2C_FSM_IDLE;

            /* Internal slave variable */
            I2C_slStatus        = 0u;
            I2C_slRdBufIndex    = 0u;
            I2C_slWrBufIndex    = 0u;
            I2C_slOverFlowCount = 0u;

            /* Internal master variable */
            I2C_mstrStatus     = 0u;
            I2C_mstrRdBufIndex = 0u;
            I2C_mstrWrBufIndex = 0u;
        }
    }

#else

    /*******************************************************************************
    * Function Name: I2C_I2CInit
    ********************************************************************************
    *
    * Summary:
    *  Configures the SCB for I2C operation.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void I2C_I2CInit(void)
    {
        /* Configure I2C interface */
        I2C_CTRL_REG     = I2C_I2C_DEFAULT_CTRL;
        I2C_I2C_CTRL_REG = I2C_I2C_DEFAULT_I2C_CTRL;

        /* Adjust SDA filter settigns */
        I2C_SET_I2C_CFG_SDA_FILT_TRIM(I2C_EC_AM_I2C_CFG_SDA_FILT_TRIM);

        /* Configure RX direction */
        I2C_RX_CTRL_REG      = I2C_I2C_DEFAULT_RX_CTRL;
        I2C_RX_FIFO_CTRL_REG = I2C_I2C_DEFAULT_RX_FIFO_CTRL;

        /* Set default address and mask */
        I2C_RX_MATCH_REG     = I2C_I2C_DEFAULT_RX_MATCH;

        /* Configure TX direction */
        I2C_TX_CTRL_REG      = I2C_I2C_DEFAULT_TX_CTRL;
        I2C_TX_FIFO_CTRL_REG = I2C_I2C_DEFAULT_TX_FIFO_CTRL;

        /* Configure interrupt with I2C handler */
        I2C_SCB_IRQ_Disable();
        I2C_SCB_IRQ_SetVector(&I2C_I2C_ISR);
        I2C_SCB_IRQ_SetPriority((uint8)I2C_SCB_IRQ_INTC_PRIOR_NUMBER);
        
        /* Configure interrupt sources */
        I2C_INTR_I2C_EC_MASK_REG = I2C_I2C_DEFAULT_INTR_I2C_EC_MASK;
        I2C_INTR_SPI_EC_MASK_REG = I2C_I2C_DEFAULT_INTR_SPI_EC_MASK;
        I2C_INTR_SLAVE_MASK_REG  = I2C_I2C_DEFAULT_INTR_SLAVE_MASK;
        I2C_INTR_MASTER_MASK_REG = I2C_I2C_DEFAULT_INTR_MASTER_MASK;
        I2C_INTR_RX_MASK_REG     = I2C_I2C_DEFAULT_INTR_RX_MASK;
        I2C_INTR_TX_MASK_REG     = I2C_I2C_DEFAULT_INTR_TX_MASK;

        /* Configure global variables */
        I2C_state = I2C_I2C_FSM_IDLE;

        #if(I2C_I2C_SLAVE)
            /* Internal slave variable */
            I2C_slStatus        = 0u;
            I2C_slRdBufIndex    = 0u;
            I2C_slWrBufIndex    = 0u;
            I2C_slOverFlowCount = 0u;
        #endif /* (I2C_I2C_SLAVE) */

        #if(I2C_I2C_MASTER)
        /* Internal master variable */
            I2C_mstrStatus     = 0u;
            I2C_mstrRdBufIndex = 0u;
            I2C_mstrWrBufIndex = 0u;
        #endif /* (I2C_I2C_MASTER) */
    }
#endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */


/*******************************************************************************
* Function Name: I2C_I2CStop
********************************************************************************
*
* Summary:
*  Initializes I2C registers with initial values provided from customizer.
*
* Parameters:
*  None
*
* Return:
*  None
*
* Global variables:
*
*
*******************************************************************************/
void I2C_I2CStop(void)
{
    I2C_state = I2C_I2C_FSM_IDLE;
}


#if(I2C_I2C_WAKE_ENABLE_CONST)
    /*******************************************************************************
    * Function Name: I2C_I2CSaveConfig
    ********************************************************************************
    *
    * Summary:
    *  Wakeup disabled: does nothing.
    *  Wakeup  enabled: clears SCB_backup.enableState and enables
    *  SCB_INTR_I2C_EC_WAKE_UP interrupt used for wakeup. This interrupt source
    *  tracks in active mode therefore it does not require to be cleared.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void I2C_I2CSaveConfig(void)
    {
        /* Enable interrupt to wakeup the device */
        I2C_SetI2CExtClkInterruptMode(I2C_INTR_I2C_EC_WAKE_UP);
    }


    /*******************************************************************************
    * Function Name: I2C_I2CRestoreConfig
    ********************************************************************************
    *
    * Summary:
    *  Does nothing.
    *
    * Parameters:
    *  None
    *
    * Return:
    *  None
    *
    *******************************************************************************/
    void I2C_I2CRestoreConfig(void)
    {
        /* Does nothing: as wake is masked-off in the interrupt */
    }
#endif /* (I2C_I2C_WAKE_ENABLE_CONST) */


/* [] END OF FILE */
