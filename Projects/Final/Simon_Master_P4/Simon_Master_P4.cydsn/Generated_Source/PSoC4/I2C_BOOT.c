/*******************************************************************************
* File Name: I2C_BOOT.c
* Version 1.10
*
* Description:
*  This file provides the source code to the API for the bootloader
*  communication support in SCB Component.
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

#if(I2C_SCB_MODE_I2C_INC)
    #include "I2C_I2C.h"
#endif /* (I2C_SCB_MODE_I2C_INC) */

#if(I2C_SCB_MODE_EZI2C_INC)
    #include "I2C_EZI2C.h"
#endif /* (I2C_SCB_MODE_EZI2C_INC) */

#if(I2C_SCB_MODE_SPI_INC || I2C_SCB_MODE_UART_INC)
    #include "I2C_SPI_UART.h"
#endif /* (I2C_SCB_MODE_SPI_INC || I2C_SCB_MODE_UART_INC) */


#if defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_I2C) || \
                                          (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface))

/*******************************************************************************
* Function Name: I2C_CyBtldrCommStart
********************************************************************************
*
* Summary:
*  Calls Start function fucntion of the bootloader communication component for
*  selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_CyBtldrCommStart(void)
{
    #if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
        if(I2C_SCB_MODE_I2C_RUNTM_CFG)
        {
            I2C_I2CCyBtldrCommStart();
        }
        else if(I2C_SCB_MODE_SPI_RUNTM_CFG)
        {
            I2C_SpiCyBtldrCommStart();
        }
        else if(I2C_SCB_MODE_UART_RUNTM_CFG)
        {
            I2C_UartCyBtldrCommStart();
        }
        else if(I2C_SCB_MODE_EZI2C_RUNTM_CFG)
        {
             I2C_EzI2CCyBtldrCommStart();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(I2C_SCB_MODE_I2C_CONST_CFG)
        I2C_I2CCyBtldrCommStart();

    #elif(I2C_SCB_MODE_SPI_CONST_CFG)
        I2C_SpiCyBtldrCommStart();

    #elif(I2C_SCB_MODE_UART_CONST_CFG)
        I2C_UartCyBtldrCommStart();

    #elif(I2C_SCB_MODE_EZI2C_CONST_CFG)
        I2C_EzI2CCyBtldrCommStart();

    #else
        /* Do nothing */

    #endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: I2C_CyBtldrCommStop
********************************************************************************
*
* Summary:
*  Calls Stop function fucntion of the bootloader communication component for
*  selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_CyBtldrCommStop(void)
{
    #if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
        if(I2C_SCB_MODE_I2C_RUNTM_CFG)
        {
            I2C_I2CCyBtldrCommStop();
        }
        else if(I2C_SCB_MODE_SPI_RUNTM_CFG)
        {
            I2C_SpiCyBtldrCommStop();
        }
        else if(I2C_SCB_MODE_UART_RUNTM_CFG)
        {
            I2C_UartCyBtldrCommStop();
        }
        else if(I2C_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            I2C_EzI2CCyBtldrCommStop();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(I2C_SCB_MODE_I2C_CONST_CFG)
        I2C_I2CCyBtldrCommStop();

    #elif(I2C_SCB_MODE_SPI_CONST_CFG)
        I2C_SpiCyBtldrCommStop();

    #elif(I2C_SCB_MODE_UART_CONST_CFG)
        I2C_UartCyBtldrCommStop();

    #elif(I2C_SCB_MODE_EZI2C_CONST_CFG)
        I2C_EzI2CCyBtldrCommStop();

    #else
        /* Do nothing */

    #endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: I2C_CyBtldrCommReset
********************************************************************************
*
* Summary:
*  Calls reset function fucntion of the bootloader communication component for
*  selected mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void I2C_CyBtldrCommReset(void)
{
    #if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
        if(I2C_SCB_MODE_I2C_RUNTM_CFG)
        {
            I2C_I2CCyBtldrCommReset();
        }
        else if(I2C_SCB_MODE_SPI_RUNTM_CFG)
        {
            I2C_SpiCyBtldrCommReset();
        }
        else if(I2C_SCB_MODE_UART_RUNTM_CFG)
        {
            I2C_UartCyBtldrCommReset();
        }
        else if(I2C_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            I2C_EzI2CCyBtldrCommReset();
        }
        else
        {
            /* Unknown mode: do nothing */
        }
    #elif(I2C_SCB_MODE_I2C_CONST_CFG)
        I2C_I2CCyBtldrCommReset();

    #elif(I2C_SCB_MODE_SPI_CONST_CFG)
        I2C_SpiCyBtldrCommReset();

    #elif(I2C_SCB_MODE_UART_CONST_CFG)
        I2C_UartCyBtldrCommReset();

    #elif(I2C_SCB_MODE_EZI2C_CONST_CFG)
        I2C_EzI2CCyBtldrCommReset();

    #else
        /* Do nothing */

    #endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */
}


/*******************************************************************************
* Function Name: I2C_CyBtldrCommRead
********************************************************************************
*
* Summary:
*  Calls read fucntion of the bootloader communication component for selected
*  mode.
*
* Parameters:
*  pData:    Pointer to storage for the block of data to be read from the
*            bootloader host
*  size:     Number of bytes to be read.
*  count:    Pointer to the variable to write the number of bytes actually
*            read.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus I2C_CyBtldrCommRead(uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
        if(I2C_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = I2C_I2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(I2C_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = I2C_SpiCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(I2C_SCB_MODE_UART_RUNTM_CFG)
        {
            status = I2C_UartCyBtldrCommRead(pData, size, count, timeOut);
        }
        else if(I2C_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = I2C_EzI2CCyBtldrCommRead(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode: return status */
        }

    #elif(I2C_SCB_MODE_I2C_CONST_CFG)
        status = I2C_I2CCyBtldrCommRead(pData, size, count, timeOut);

    #elif(I2C_SCB_MODE_SPI_CONST_CFG)
        status = I2C_SpiCyBtldrCommRead(pData, size, count, timeOut);

    #elif(I2C_SCB_MODE_UART_CONST_CFG)
        status = I2C_UartCyBtldrCommRead(pData, size, count, timeOut);

    #elif(I2C_SCB_MODE_EZI2C_CONST_CFG)
        status = I2C_EzI2CCyBtldrCommRead(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode: return status */

    #endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}


/*******************************************************************************
* Function Name: I2C_CyBtldrCommWrite
********************************************************************************
*
* Summary:
*  Calls write fucntion of the bootloader communication component for selected
*  mode.
*
* Parameters:
*  pData:    Pointer to the block of data to be written to the bootloader host.
*  size:     Number of bytes to be written.
*  count:    Pointer to the variable to write the number of bytes actually
*            written.
*  timeOut:  Number of units in 10 ms to wait before returning because of a
*            timeout.
*
* Return:
*  Returns CYRET_SUCCESS if no problem was encountered or returns the value
*  that best describes the problem.
*
*******************************************************************************/
cystatus I2C_CyBtldrCommWrite(const uint8 pData[], uint16 size, uint16 * count, uint8 timeOut)
{
    cystatus status;

    #if(I2C_SCB_MODE_UNCONFIG_CONST_CFG)
        if(I2C_SCB_MODE_I2C_RUNTM_CFG)
        {
            status = I2C_I2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(I2C_SCB_MODE_SPI_RUNTM_CFG)
        {
            status = I2C_SpiCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(I2C_SCB_MODE_UART_RUNTM_CFG)
        {
            status = I2C_UartCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else if(I2C_SCB_MODE_EZI2C_RUNTM_CFG)
        {
            status = I2C_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);
        }
        else
        {
            status = CYRET_INVALID_STATE; /* Unknown mode: return status */
        }
    #elif(I2C_SCB_MODE_I2C_CONST_CFG)
        status = I2C_I2CCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(I2C_SCB_MODE_SPI_CONST_CFG)
        status = I2C_SpiCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(I2C_SCB_MODE_UART_CONST_CFG)
        status = I2C_UartCyBtldrCommWrite(pData, size, count, timeOut);

    #elif(I2C_SCB_MODE_EZI2C_CONST_CFG)
        status = I2C_EzI2CCyBtldrCommWrite(pData, size, count, timeOut);

    #else
        status = CYRET_INVALID_STATE; /* Unknown mode: return status */

    #endif /* (I2C_SCB_MODE_UNCONFIG_CONST_CFG) */

    return(status);
}

#endif /* defined(CYDEV_BOOTLOADER_IO_COMP) && ((CYDEV_BOOTLOADER_IO_COMP == CyBtldr_I2C) || \
                                                    (CYDEV_BOOTLOADER_IO_COMP == CyBtldr_Custom_Interface)) */


/* [] END OF FILE */
