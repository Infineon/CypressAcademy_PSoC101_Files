/*******************************************************************************
* File Name: Buzz.c  
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
#include "Buzz.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Buzz_PC =   (Buzz_PC & \
                                (uint32)(~(uint32)(Buzz_DRIVE_MODE_IND_MASK << (Buzz_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Buzz_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Buzz_Write
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
void Buzz_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Buzz_DR & (uint8)(~Buzz_MASK));
    drVal = (drVal | ((uint8)(value << Buzz_SHIFT) & Buzz_MASK));
    Buzz_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Buzz_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Buzz_DM_STRONG     Strong Drive 
*  Buzz_DM_OD_HI      Open Drain, Drives High 
*  Buzz_DM_OD_LO      Open Drain, Drives Low 
*  Buzz_DM_RES_UP     Resistive Pull Up 
*  Buzz_DM_RES_DWN    Resistive Pull Down 
*  Buzz_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Buzz_DM_DIG_HIZ    High Impedance Digital 
*  Buzz_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Buzz_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Buzz__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Buzz_Read
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
*  Macro Buzz_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Buzz_Read(void) 
{
    return (uint8)((Buzz_PS & Buzz_MASK) >> Buzz_SHIFT);
}


/*******************************************************************************
* Function Name: Buzz_ReadDataReg
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
uint8 Buzz_ReadDataReg(void) 
{
    return (uint8)((Buzz_DR & Buzz_MASK) >> Buzz_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Buzz_INTSTAT) 

    /*******************************************************************************
    * Function Name: Buzz_ClearInterrupt
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
    uint8 Buzz_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Buzz_INTSTAT & Buzz_MASK);
		Buzz_INTSTAT = maskedStatus;
        return maskedStatus >> Buzz_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
