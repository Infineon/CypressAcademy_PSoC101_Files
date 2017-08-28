/*******************************************************************************
* File Name: LED4.h  
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

#if !defined(CY_PINS_LED4_H) /* Pins LED4_H */
#define CY_PINS_LED4_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LED4_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED4_Write(uint8 value) ;
void    LED4_SetDriveMode(uint8 mode) ;
uint8   LED4_ReadDataReg(void) ;
uint8   LED4_Read(void) ;
uint8   LED4_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED4_DRIVE_MODE_BITS        (3)
#define LED4_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LED4_DRIVE_MODE_BITS))

#define LED4_DM_ALG_HIZ         (0x00u)
#define LED4_DM_DIG_HIZ         (0x01u)
#define LED4_DM_RES_UP          (0x02u)
#define LED4_DM_RES_DWN         (0x03u)
#define LED4_DM_OD_LO           (0x04u)
#define LED4_DM_OD_HI           (0x05u)
#define LED4_DM_STRONG          (0x06u)
#define LED4_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define LED4_MASK               LED4__MASK
#define LED4_SHIFT              LED4__SHIFT
#define LED4_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED4_PS                     (* (reg32 *) LED4__PS)
/* Port Configuration */
#define LED4_PC                     (* (reg32 *) LED4__PC)
/* Data Register */
#define LED4_DR                     (* (reg32 *) LED4__DR)
/* Input Buffer Disable Override */
#define LED4_INP_DIS                (* (reg32 *) LED4__PC2)


#if defined(LED4__INTSTAT)  /* Interrupt Registers */

    #define LED4_INTSTAT                (* (reg32 *) LED4__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define LED4_DRIVE_MODE_SHIFT       (0x00u)
#define LED4_DRIVE_MODE_MASK        (0x07u << LED4_DRIVE_MODE_SHIFT)


#endif /* End Pins LED4_H */


/* [] END OF FILE */
