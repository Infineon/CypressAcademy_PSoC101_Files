/*******************************************************************************
* File Name: LED3.c  
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
#include "LED3.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        LED3_PC =   (LED3_PC & \
                                (uint32)(~(uint32)(LED3_DRIVE_MODE_IND_MASK << (LED3_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (LED3_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: LED3_Write
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
void LED3_Write(uint8 value) 
{
    uint8 drVal = (uint8)(LED3_DR & (uint8)(~LED3_MASK));
    drVal = (drVal | ((uint8)(value << LED3_SHIFT) & LED3_MASK));
    LED3_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: LED3_SetDriveMode
********************************************************************************
*
* Summary:
*  Change the drive mode on the pins of the port.
* 
* Parameters:  
*  mode:  Change the pins to one of the following drive modes.
*
*  LED3_DM_STRONG     Strong Drive 
*  LED3_DM_OD_HI      Open Drain, Drives High 
*  LED3_DM_OD_LO      Open Drain, Drives Low 
*  LED3_DM_RES_UP     Resistive Pull Up 
*  LED3_DM_RES_DWN    Resistive Pull Down 
*  LED3_DM_RES_UPDWN  Resistive Pull Up/Down 
*  LED3_DM_DIG_HIZ    High Impedance Digital 
*  LED3_DM_ALG_HIZ    High Impedance Analog 
*
* Return: 
*  None
*
*******************************************************************************/
void LED3_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(LED3__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: LED3_Read
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
*  Macro LED3_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 LED3_Read(void) 
{
    return (uint8)((LED3_PS & LED3_MASK) >> LED3_SHIFT);
}


/*******************************************************************************
* Function Name: LED3_ReadDataReg
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
uint8 LED3_ReadDataReg(void) 
{
    return (uint8)((LED3_DR & LED3_MASK) >> LED3_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(LED3_INTSTAT) 

    /*******************************************************************************
    * Function Name: LED3_ClearInterrupt
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
    uint8 LED3_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(LED3_INTSTAT & LED3_MASK);
		LED3_INTSTAT = maskedStatus;
        return maskedStatus >> LED3_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
