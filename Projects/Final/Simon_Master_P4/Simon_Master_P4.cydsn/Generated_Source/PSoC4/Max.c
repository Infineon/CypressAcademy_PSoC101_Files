/*******************************************************************************
* File Name: Max.c  
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
#include "Max.h"

#define SetP4PinDriveMode(shift, mode)  \
    do { \
        Max_PC =   (Max_PC & \
                                (uint32)(~(uint32)(Max_DRIVE_MODE_IND_MASK << (Max_DRIVE_MODE_BITS * (shift))))) | \
                                (uint32)((uint32)(mode) << (Max_DRIVE_MODE_BITS * (shift))); \
    } while (0)


/*******************************************************************************
* Function Name: Max_Write
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
void Max_Write(uint8 value) 
{
    uint8 drVal = (uint8)(Max_DR & (uint8)(~Max_MASK));
    drVal = (drVal | ((uint8)(value << Max_SHIFT) & Max_MASK));
    Max_DR = (uint32)drVal;
}


/*******************************************************************************
* Function Name: Max_SetDriveMode
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
void Max_SetDriveMode(uint8 mode) 
{
	SetP4PinDriveMode(Max__0__SHIFT, mode);
}


/*******************************************************************************
* Function Name: Max_Read
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
*  Macro Max_ReadPS calls this function. 
*  
*******************************************************************************/
uint8 Max_Read(void) 
{
    return (uint8)((Max_PS & Max_MASK) >> Max_SHIFT);
}


/*******************************************************************************
* Function Name: Max_ReadDataReg
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
uint8 Max_ReadDataReg(void) 
{
    return (uint8)((Max_DR & Max_MASK) >> Max_SHIFT);
}


/* If Interrupts Are Enabled for this Pins component */ 
#if defined(Max_INTSTAT) 

    /*******************************************************************************
    * Function Name: Max_ClearInterrupt
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
    uint8 Max_ClearInterrupt(void) 
    {
		uint8 maskedStatus = (uint8)(Max_INTSTAT & Max_MASK);
		Max_INTSTAT = maskedStatus;
        return maskedStatus >> Max_SHIFT;
    }

#endif /* If Interrupts Are Enabled for this Pins component */ 


/* [] END OF FILE */
