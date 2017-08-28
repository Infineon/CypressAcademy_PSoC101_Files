/*******************************************************************************
* File Name: Vin.c  
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
#include "Vin.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Vin_PC =   (Vin_PC & \
                                (uint32)(~(uint32)(Vin_DRIVE_MODE_IND_MASK << (Vin_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Vin_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Vin_Write
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
void Vin_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Vin_DR & (uint8)(~Vin_MASK));
    drVal = (drVal | ((uint8)(value << Vin_SHIFT) & Vin_MASK));
    Vin_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Vin_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  Vin_DM_STRONG     Strong Drive 
*  Vin_DM_OD_HI      Open Drain, Drives High 
*  Vin_DM_OD_LO      Open Drain, Drives Low 
*  Vin_DM_RES_UP     Resistive Pull Up 
*  Vin_DM_RES_DWN    Resistive Pull Down 
*  Vin_DM_RES_UPDWN  Resistive Pull Up/Down 
*  Vin_DM_DIG_HIZ    High Impedance Digital 
*  Vin_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void Vin_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Vin__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Vin_Read
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
*  Macro Vin_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Vin_Read(void) 
{
    return (uint8)((Vin_PS & Vin_MASK) >> Vin_SHIFT);
}


/*******************************************************************************
* Function Name: Vin_ReadDataReg
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
uint8 Vin_ReadDataReg(void) 
{
    return (uint8)((Vin_DR & Vin_MASK) >> Vin_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Vin_INTSTAT) 

    /*******************************************************************************
    * Function Name: Vin_ClearInterrupt
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
    uint8 Vin_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Vin_INTSTAT & Vin_MASK);
		Vin_INTSTAT = maskedStatus;
        return maskedStatus >> Vin_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
