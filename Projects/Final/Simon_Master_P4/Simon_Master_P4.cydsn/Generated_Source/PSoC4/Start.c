/*******************************************************************************
* File Name: Start.c  
* Version 1.90
*
* Description:
*  This file contains API to enable firmware control of a Pins component.
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Start.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Start_PC =   (Start_PC & \
                                (uint32)(~(uint32)(Start_DRIVE_MODE_IND_MASK << (Start_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Start_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Start_Write
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
void Start_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Start_DR & (uint8)(~Start_MASK));
    drVal = (drVal | ((uint8)(value << Start_SHIFT) & Start_MASK));
    Start_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Start_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to this drive mode.
*
* Return: 
*  None
*
*******************************************************************************/
void Start_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Start__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Start_Read
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
*  Macro Start_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Start_Read(void) 
{
    return (uint8)((Start_PS & Start_MASK) >> Start_SHIFT);
}


/*******************************************************************************
* Function Name: Start_ReadDataReg
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
uint8 Start_ReadDataReg(void) 
{
    return (uint8)((Start_DR & Start_MASK) >> Start_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Start_INTSTAT) 

    /*******************************************************************************
    * Function Name: Start_ClearInterrupt
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
    uint8 Start_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Start_INTSTAT & Start_MASK);
		Start_INTSTAT = maskedStatus;
        return maskedStatus >> Start_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
