/*******************************************************************************
* File Name: TCPWM_PM.c
* Version 2.0
*
* Description:
*  This file contains the setup, control, and status commands to support
*  the component operations in the low power mode.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "TCPWM.h"

static TCPWM_BACKUP_STRUCT TCPWM_backup;


/*******************************************************************************
* Function Name: TCPWM_SaveConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to save here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM_SaveConfig(void)
{

}


/*******************************************************************************
* Function Name: TCPWM_Sleep
********************************************************************************
*
* Summary:
*  Stops the component operation and saves the user configuration.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM_Sleep(void)
{
    if(0u != (TCPWM_BLOCK_CONTROL_REG & TCPWM_MASK))
    {
        TCPWM_backup.enableState = 1u;
    }
    else
    {
        TCPWM_backup.enableState = 0u;
    }

    TCPWM_Stop();
    TCPWM_SaveConfig();
}


/*******************************************************************************
* Function Name: TCPWM_RestoreConfig
********************************************************************************
*
* Summary:
*  All configuration registers are retention. Nothing to restore here.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM_RestoreConfig(void)
{

}


/*******************************************************************************
* Function Name: TCPWM_Wakeup
********************************************************************************
*
* Summary:
*  Restores the user configuration and restores the enable state.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void TCPWM_Wakeup(void)
{
    TCPWM_RestoreConfig();

    if(0u != TCPWM_backup.enableState)
    {
        TCPWM_Enable();
    }
}


/* [] END OF FILE */
