/*******************************************************************************
* File Name: ButtonStatus.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware to read the value of a Status 
*  Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "ButtonStatus.h"

#if !defined(ButtonStatus_sts_sts_reg__REMOVED) /* Check for removal by optimization */


/*******************************************************************************
* Function Name: ButtonStatus_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The current value in the Status Register.
*
*******************************************************************************/
uint8 ButtonStatus_Read(void) 
{ 
    return ButtonStatus_Status;
}


/*******************************************************************************
* Function Name: ButtonStatus_InterruptEnable
********************************************************************************
*
* Summary:
*  Enables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ButtonStatus_InterruptEnable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    ButtonStatus_Status_Aux_Ctrl |= ButtonStatus_STATUS_INTR_ENBL;
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ButtonStatus_InterruptDisable
********************************************************************************
*
* Summary:
*  Disables the Status Register interrupt.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void ButtonStatus_InterruptDisable(void) 
{
    uint8 interruptState;
    interruptState = CyEnterCriticalSection();
    ButtonStatus_Status_Aux_Ctrl &= (uint8)(~ButtonStatus_STATUS_INTR_ENBL);
    CyExitCriticalSection(interruptState);
}


/*******************************************************************************
* Function Name: ButtonStatus_WriteMask
********************************************************************************
*
* Summary:
*  Writes the current mask value assigned to the Status Register.
*
* Parameters:
*  mask:  Value to write into the mask register.
*
* Return:
*  None.
*
*******************************************************************************/
void ButtonStatus_WriteMask(uint8 mask) 
{
    #if(ButtonStatus_INPUTS < 8u)
    	mask &= ((uint8)(1u << ButtonStatus_INPUTS) - 1u);
	#endif /* End ButtonStatus_INPUTS < 8u */
    ButtonStatus_Status_Mask = mask;
}


/*******************************************************************************
* Function Name: ButtonStatus_ReadMask
********************************************************************************
*
* Summary:
*  Reads the current interrupt mask assigned to the Status Register.
*
* Parameters:
*  None.
*
* Return:
*  The value of the interrupt mask of the Status Register.
*
*******************************************************************************/
uint8 ButtonStatus_ReadMask(void) 
{
    return ButtonStatus_Status_Mask;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
