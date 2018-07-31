/*******************************************************************************
* File Name: LEDreg_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "LEDreg.h"

/* Check for removal by optimization */
#if !defined(LEDreg_Sync_ctrl_reg__REMOVED)

static LEDreg_BACKUP_STRUCT  LEDreg_backup = {0u};

    
/*******************************************************************************
* Function Name: LEDreg_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LEDreg_SaveConfig(void) 
{
    LEDreg_backup.controlState = LEDreg_Control;
}


/*******************************************************************************
* Function Name: LEDreg_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void LEDreg_RestoreConfig(void) 
{
     LEDreg_Control = LEDreg_backup.controlState;
}


/*******************************************************************************
* Function Name: LEDreg_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LEDreg_Sleep(void) 
{
    LEDreg_SaveConfig();
}


/*******************************************************************************
* Function Name: LEDreg_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void LEDreg_Wakeup(void)  
{
    LEDreg_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
