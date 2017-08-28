/*******************************************************************************
* File Name: ButtonStatus.h  
* Version 1.90
*
* Description:
*  This file containts Status Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_STATUS_REG_ButtonStatus_H) /* CY_STATUS_REG_ButtonStatus_H */
#define CY_STATUS_REG_ButtonStatus_H

#include "cytypes.h"
#include "CyLib.h"

    
/***************************************
*     Data Struct Definitions
***************************************/

/* Sleep Mode API Support */
typedef struct
{
    uint8 statusState;

} ButtonStatus_BACKUP_STRUCT;


/***************************************
*        Function Prototypes
***************************************/

uint8 ButtonStatus_Read(void) ;
void ButtonStatus_InterruptEnable(void) ;
void ButtonStatus_InterruptDisable(void) ;
void ButtonStatus_WriteMask(uint8 mask) ;
uint8 ButtonStatus_ReadMask(void) ;


/***************************************
*           API Constants
***************************************/

#define ButtonStatus_STATUS_INTR_ENBL    0x10u


/***************************************
*         Parameter Constants
***************************************/

/* Status Register Inputs */
#define ButtonStatus_INPUTS              4


/***************************************
*             Registers
***************************************/

/* Status Register */
#define ButtonStatus_Status             (* (reg8 *) ButtonStatus_sts_sts_reg__STATUS_REG )
#define ButtonStatus_Status_PTR         (  (reg8 *) ButtonStatus_sts_sts_reg__STATUS_REG )
#define ButtonStatus_Status_Mask        (* (reg8 *) ButtonStatus_sts_sts_reg__MASK_REG )
#define ButtonStatus_Status_Aux_Ctrl    (* (reg8 *) ButtonStatus_sts_sts_reg__STATUS_AUX_CTL_REG )

#endif /* End CY_STATUS_REG_ButtonStatus_H */


/* [] END OF FILE */
