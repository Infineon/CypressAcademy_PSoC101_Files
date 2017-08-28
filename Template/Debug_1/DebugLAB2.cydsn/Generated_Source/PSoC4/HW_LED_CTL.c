/*******************************************************************************
* File Name: HW_LED_CTL.c  
* Version 1.80
*
* Description:
*  This file contains API to enable firmware control of a Control Register.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "HW_LED_CTL.h"

/* Check for removal by optimization */
#if !defined(HW_LED_CTL_Sync_ctrl_reg__REMOVED)

    
/*******************************************************************************
* Function Name: HW_LED_CTL_Write
********************************************************************************
*
* Summary:
*  Write a byte to the Control Register.
*
* Parameters:
*  control:  The value to be assigned to the Control Register.
*
* Return:
*  None.
*
*******************************************************************************/
void HW_LED_CTL_Write(uint8 control) 
{
    HW_LED_CTL_Control = control;
}


/*******************************************************************************
* Function Name: HW_LED_CTL_Read
********************************************************************************
*
* Summary:
*  Reads the current value assigned to the Control Register.
*
* Parameters:
*  None.
*
* Return:
*  Returns the current value in the Control Register.
*
*******************************************************************************/
uint8 HW_LED_CTL_Read(void) 
{
    return HW_LED_CTL_Control;
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
