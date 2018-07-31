/*******************************************************************************
* File Name: ResetHS.h  
* Version 1.90
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_ResetHS_H) /* Pins ResetHS_H */
#define CY_PINS_ResetHS_H

#include "cytypes.h"
#include "cyfitter.h"
#include "ResetHS_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    ResetHS_Write(uint8 value) ;
void    ResetHS_SetDriveMode(uint8 mode) ;
uint8   ResetHS_ReadDataReg(void) ;
uint8   ResetHS_Read(void) ;
uint8   ResetHS_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define ResetHS_DRIVE_MODE_BITS        (3)
#define ResetHS_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - ResetHS_DRIVE_MODE_BITS))
#define ResetHS_DRIVE_MODE_SHIFT       (0x00u)
#define ResetHS_DRIVE_MODE_MASK        (0x07u << ResetHS_DRIVE_MODE_SHIFT)

#define ResetHS_DM_ALG_HIZ         (0x00u << ResetHS_DRIVE_MODE_SHIFT)
#define ResetHS_DM_DIG_HIZ         (0x01u << ResetHS_DRIVE_MODE_SHIFT)
#define ResetHS_DM_RES_UP          (0x02u << ResetHS_DRIVE_MODE_SHIFT)
#define ResetHS_DM_RES_DWN         (0x03u << ResetHS_DRIVE_MODE_SHIFT)
#define ResetHS_DM_OD_LO           (0x04u << ResetHS_DRIVE_MODE_SHIFT)
#define ResetHS_DM_OD_HI           (0x05u << ResetHS_DRIVE_MODE_SHIFT)
#define ResetHS_DM_STRONG          (0x06u << ResetHS_DRIVE_MODE_SHIFT)
#define ResetHS_DM_RES_UPDWN       (0x07u << ResetHS_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define ResetHS_MASK               ResetHS__MASK
#define ResetHS_SHIFT              ResetHS__SHIFT
#define ResetHS_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define ResetHS_PS                     (* (reg32 *) ResetHS__PS)
/* Port Configuration */
#define ResetHS_PC                     (* (reg32 *) ResetHS__PC)
/* Data Register */
#define ResetHS_DR                     (* (reg32 *) ResetHS__DR)
/* Input Buffer Disable Override */
#define ResetHS_INP_DIS                (* (reg32 *) ResetHS__PC2)


#if defined(ResetHS__INTSTAT)  /* Interrupt Registers */

    #define ResetHS_INTSTAT                (* (reg32 *) ResetHS__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins ResetHS_H */


/* [] END OF FILE */
