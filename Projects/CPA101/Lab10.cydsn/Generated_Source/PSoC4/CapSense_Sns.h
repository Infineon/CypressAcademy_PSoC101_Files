/*******************************************************************************
* File Name: CapSense_Sns.h  
* Version 2.10
*
* Description:
*  This file containts Control Register function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2014, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_CapSense_Sns_H) /* Pins CapSense_Sns_H */
#define CY_PINS_CapSense_Sns_H

#include "cytypes.h"
#include "cyfitter.h"
#include "CapSense_Sns_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    CapSense_Sns_Write(uint8 value) ;
void    CapSense_Sns_SetDriveMode(uint8 mode) ;
uint8   CapSense_Sns_ReadDataReg(void) ;
uint8   CapSense_Sns_Read(void) ;
uint8   CapSense_Sns_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define CapSense_Sns_DRIVE_MODE_BITS        (3)
#define CapSense_Sns_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - CapSense_Sns_DRIVE_MODE_BITS))

#define CapSense_Sns_DM_ALG_HIZ         (0x00u)
#define CapSense_Sns_DM_DIG_HIZ         (0x01u)
#define CapSense_Sns_DM_RES_UP          (0x02u)
#define CapSense_Sns_DM_RES_DWN         (0x03u)
#define CapSense_Sns_DM_OD_LO           (0x04u)
#define CapSense_Sns_DM_OD_HI           (0x05u)
#define CapSense_Sns_DM_STRONG          (0x06u)
#define CapSense_Sns_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define CapSense_Sns_MASK               CapSense_Sns__MASK
#define CapSense_Sns_SHIFT              CapSense_Sns__SHIFT
#define CapSense_Sns_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CapSense_Sns_PS                     (* (reg32 *) CapSense_Sns__PS)
/* Port Configuration */
#define CapSense_Sns_PC                     (* (reg32 *) CapSense_Sns__PC)
/* Data Register */
#define CapSense_Sns_DR                     (* (reg32 *) CapSense_Sns__DR)
/* Input Buffer Disable Override */
#define CapSense_Sns_INP_DIS                (* (reg32 *) CapSense_Sns__PC2)


#if defined(CapSense_Sns__INTSTAT)  /* Interrupt Registers */

    #define CapSense_Sns_INTSTAT                (* (reg32 *) CapSense_Sns__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define CapSense_Sns_DRIVE_MODE_SHIFT       (0x00u)
#define CapSense_Sns_DRIVE_MODE_MASK        (0x07u << CapSense_Sns_DRIVE_MODE_SHIFT)


#endif /* End Pins CapSense_Sns_H */


/* [] END OF FILE */
