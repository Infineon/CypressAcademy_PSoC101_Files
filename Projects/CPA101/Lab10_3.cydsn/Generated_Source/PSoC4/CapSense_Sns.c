/*******************************************************************************
* File Name: CapSense_Sns.c  
* Version 2.10
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "CapSense_Sns.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        CapSense_Sns_PC =   (CapSense_Sns_PC & \
                                (uint32)(~(uint32)(CapSense_Sns_DRIVE_MODE_IND_MASK << (CapSense_Sns_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (CapSense_Sns_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: CapSense_Sns_Write
********************************************************************************
*
* Summary:
*  Assign a new value to the digital port's data output register.  
*
* Parameters:  
*  prtValue:  The value to be assigned to the Digital Port. 
*
* Return: 
*  None 
*  
*******************************************************************************/
void CapSense_Sns_Write(uint8 value) 
{
    uint8 drVal = (uint8)(CapSense_Sns_DR & (uint8)(~CapSense_Sns_MASK));
    drVal = (drVal | ((uint8)(value << CapSense_Sns_SHIFT) & CapSense_Sns_MASK));
    CapSense_Sns_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: CapSense_Sns_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  CapSense_Sns_DM_STRONG     Strong Drive 
*  CapSense_Sns_DM_OD_HI      Open Drain, Drives High 
*  CapSense_Sns_DM_OD_LO      Open Drain, Drives Low 
*  CapSense_Sns_DM_RES_UP     Resistive Pull Up 
*  CapSense_Sns_DM_RES_DWN    Resistive Pull Down 
*  CapSense_Sns_DM_RES_UPDWN  Resistive Pull Up/Down 
*  CapSense_Sns_DM_DIG_HIZ    High Impedance Digital 
*  CapSense_Sns_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void CapSense_Sns_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(CapSense_Sns__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: CapSense_Sns_Read
********************************************************************************
*
* Summary:
*  Read the current value on the pins of the Digital Port in right justified 
*  form.
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value of the Digital Port as a right justified number
*  
* Note:
*  Macro CapSense_Sns_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 CapSense_Sns_Read(void) 
{
    return (uint8)((CapSense_Sns_PS & CapSense_Sns_MASK) >> CapSense_Sns_SHIFT);
}


/*******************************************************************************
* Function Name: CapSense_Sns_ReadDataReg
********************************************************************************
*
* Summary:
*  Read the current value assigned to a Digital Port's data output register
*
* Parameters:  
*  None 
*
* Return: 
*  Returns the current value assigned to the Digital Port's data output register
*  
*******************************************************************************/
uint8 CapSense_Sns_ReadDataReg(void) 
{
    return (uint8)((CapSense_Sns_DR & CapSense_Sns_MASK) >> CapSense_Sns_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(CapSense_Sns_INTSTAT) 

    /*******************************************************************************
    * Function Name: CapSense_Sns_ClearInterrupt
    ********************************************************************************
    *
    * Summary:
    *  Clears any active interrupts attached to port and returns the value of the 
    *  interrupt status register.
    *
    * Parameters:  
    *  None 
    *
    * Return: 
    *  Returns the value of the interrupt status register
    *  
    *******************************************************************************/
    uint8 CapSense_Sns_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(CapSense_Sns_INTSTAT & CapSense_Sns_MASK);
		CapSense_Sns_INTSTAT = maskedStatus;
        return maskedStatus >> CapSense_Sns_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
