/*******************************************************************************
* File Name: HW_LED_CTL.h  
* Version 1.80
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CONTROL_REG_HW_LED_CTL_H) /* CY_CONTROL_REG_HW_LED_CTL_H */
#define CY_CONTROL_REG_HW_LED_CTL_H

#include "cytypes.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 controlState;

} HW_LED_CTL_BACKUP_STRUCT;


/***************************************
*         Function Prototypes 
***************************************/

void    HW_LED_CTL_Write(uint8 control) ;
uint8   HW_LED_CTL_Read(void) ;

void HW_LED_CTL_SaveConfig(void) ;
void HW_LED_CTL_RestoreConfig(void) ;
void HW_LED_CTL_Sleep(void) ; 
void HW_LED_CTL_Wakeup(void) ;


/***************************************
*            Registers        
***************************************/

/* Control Register */
#define HW_LED_CTL_Control        (* (reg8 *) HW_LED_CTL_Sync_ctrl_reg__CONTROL_REG )
#define HW_LED_CTL_Control_PTR    (  (reg8 *) HW_LED_CTL_Sync_ctrl_reg__CONTROL_REG )

#endif /* End CY_CONTROL_REG_HW_LED_CTL_H */


/* [] END OF FILE */
