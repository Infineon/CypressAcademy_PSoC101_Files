/*******************************************************************************
* File Name: LED2.h  
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

#if !defined(CY_PINS_LED2_H) /* Pins LED2_H */
#define CY_PINS_LED2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LED2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED2_Write(uint8 value) ;
void    LED2_SetDriveMode(uint8 mode) ;
uint8   LED2_ReadDataReg(void) ;
uint8   LED2_Read(void) ;
uint8   LED2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED2_DRIVE_MODE_BITS        (3)
#define LED2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LED2_DRIVE_MODE_BITS))

#define LED2_DM_ALG_HIZ         (0x00u)
#define LED2_DM_DIG_HIZ         (0x01u)
#define LED2_DM_RES_UP          (0x02u)
#define LED2_DM_RES_DWN         (0x03u)
#define LED2_DM_OD_LO           (0x04u)
#define LED2_DM_OD_HI           (0x05u)
#define LED2_DM_STRONG          (0x06u)
#define LED2_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define LED2_MASK               LED2__MASK
#define LED2_SHIFT              LED2__SHIFT
#define LED2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED2_PS                     (* (reg32 *) LED2__PS)
/* Port Configuration */
#define LED2_PC                     (* (reg32 *) LED2__PC)
/* Data Register */
#define LED2_DR                     (* (reg32 *) LED2__DR)
/* Input Buffer Disable Override */
#define LED2_INP_DIS                (* (reg32 *) LED2__PC2)


#if defined(LED2__INTSTAT)  /* Interrupt Registers */

    #define LED2_INTSTAT                (* (reg32 *) LED2__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define LED2_DRIVE_MODE_SHIFT       (0x00u)
#define LED2_DRIVE_MODE_MASK        (0x07u << LED2_DRIVE_MODE_SHIFT)


#endif /* End Pins LED2_H */


/* [] END OF FILE */
