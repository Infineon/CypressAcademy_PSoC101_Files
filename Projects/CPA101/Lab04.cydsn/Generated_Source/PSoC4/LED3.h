/*******************************************************************************
* File Name: LED3.h  
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

#if !defined(CY_PINS_LED3_H) /* Pins LED3_H */
#define CY_PINS_LED3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LED3_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LED3_Write(uint8 value) ;
void    LED3_SetDriveMode(uint8 mode) ;
uint8   LED3_ReadDataReg(void) ;
uint8   LED3_Read(void) ;
uint8   LED3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LED3_DRIVE_MODE_BITS        (3)
#define LED3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LED3_DRIVE_MODE_BITS))

#define LED3_DM_ALG_HIZ         (0x00u)
#define LED3_DM_DIG_HIZ         (0x01u)
#define LED3_DM_RES_UP          (0x02u)
#define LED3_DM_RES_DWN         (0x03u)
#define LED3_DM_OD_LO           (0x04u)
#define LED3_DM_OD_HI           (0x05u)
#define LED3_DM_STRONG          (0x06u)
#define LED3_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define LED3_MASK               LED3__MASK
#define LED3_SHIFT              LED3__SHIFT
#define LED3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LED3_PS                     (* (reg32 *) LED3__PS)
/* Port Configuration */
#define LED3_PC                     (* (reg32 *) LED3__PC)
/* Data Register */
#define LED3_DR                     (* (reg32 *) LED3__DR)
/* Input Buffer Disable Override */
#define LED3_INP_DIS                (* (reg32 *) LED3__PC2)


#if defined(LED3__INTSTAT)  /* Interrupt Registers */

    #define LED3_INTSTAT                (* (reg32 *) LED3__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define LED3_DRIVE_MODE_SHIFT       (0x00u)
#define LED3_DRIVE_MODE_MASK        (0x07u << LED3_DRIVE_MODE_SHIFT)


#endif /* End Pins LED3_H */


/* [] END OF FILE */
