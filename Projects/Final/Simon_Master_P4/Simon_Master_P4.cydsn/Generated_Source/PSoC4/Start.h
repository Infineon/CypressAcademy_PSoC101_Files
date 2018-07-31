/*******************************************************************************
* File Name: Start.h  
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

#if !defined(CY_PINS_Start_H) /* Pins Start_H */
#define CY_PINS_Start_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Start_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Start_Write(uint8 value) ;
void    Start_SetDriveMode(uint8 mode) ;
uint8   Start_ReadDataReg(void) ;
uint8   Start_Read(void) ;
uint8   Start_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Start_DRIVE_MODE_BITS        (3)
#define Start_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Start_DRIVE_MODE_BITS))
#define Start_DRIVE_MODE_SHIFT       (0x00u)
#define Start_DRIVE_MODE_MASK        (0x07u << Start_DRIVE_MODE_SHIFT)

#define Start_DM_ALG_HIZ         (0x00u << Start_DRIVE_MODE_SHIFT)
#define Start_DM_DIG_HIZ         (0x01u << Start_DRIVE_MODE_SHIFT)
#define Start_DM_RES_UP          (0x02u << Start_DRIVE_MODE_SHIFT)
#define Start_DM_RES_DWN         (0x03u << Start_DRIVE_MODE_SHIFT)
#define Start_DM_OD_LO           (0x04u << Start_DRIVE_MODE_SHIFT)
#define Start_DM_OD_HI           (0x05u << Start_DRIVE_MODE_SHIFT)
#define Start_DM_STRONG          (0x06u << Start_DRIVE_MODE_SHIFT)
#define Start_DM_RES_UPDWN       (0x07u << Start_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Start_MASK               Start__MASK
#define Start_SHIFT              Start__SHIFT
#define Start_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Start_PS                     (* (reg32 *) Start__PS)
/* Port Configuration */
#define Start_PC                     (* (reg32 *) Start__PC)
/* Data Register */
#define Start_DR                     (* (reg32 *) Start__DR)
/* Input Buffer Disable Override */
#define Start_INP_DIS                (* (reg32 *) Start__PC2)


#if defined(Start__INTSTAT)  /* Interrupt Registers */

    #define Start_INTSTAT                (* (reg32 *) Start__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Start_H */


/* [] END OF FILE */
