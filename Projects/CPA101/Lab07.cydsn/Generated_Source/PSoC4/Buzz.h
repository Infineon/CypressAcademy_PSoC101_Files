/*******************************************************************************
* File Name: Buzz.h  
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

#if !defined(CY_PINS_Buzz_H) /* Pins Buzz_H */
#define CY_PINS_Buzz_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Buzz_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Buzz_Write(uint8 value) ;
void    Buzz_SetDriveMode(uint8 mode) ;
uint8   Buzz_ReadDataReg(void) ;
uint8   Buzz_Read(void) ;
uint8   Buzz_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Buzz_DRIVE_MODE_BITS        (3)
#define Buzz_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Buzz_DRIVE_MODE_BITS))

#define Buzz_DM_ALG_HIZ         (0x00u)
#define Buzz_DM_DIG_HIZ         (0x01u)
#define Buzz_DM_RES_UP          (0x02u)
#define Buzz_DM_RES_DWN         (0x03u)
#define Buzz_DM_OD_LO           (0x04u)
#define Buzz_DM_OD_HI           (0x05u)
#define Buzz_DM_STRONG          (0x06u)
#define Buzz_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Buzz_MASK               Buzz__MASK
#define Buzz_SHIFT              Buzz__SHIFT
#define Buzz_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Buzz_PS                     (* (reg32 *) Buzz__PS)
/* Port Configuration */
#define Buzz_PC                     (* (reg32 *) Buzz__PC)
/* Data Register */
#define Buzz_DR                     (* (reg32 *) Buzz__DR)
/* Input Buffer Disable Override */
#define Buzz_INP_DIS                (* (reg32 *) Buzz__PC2)


#if defined(Buzz__INTSTAT)  /* Interrupt Registers */

    #define Buzz_INTSTAT                (* (reg32 *) Buzz__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Buzz_DRIVE_MODE_SHIFT       (0x00u)
#define Buzz_DRIVE_MODE_MASK        (0x07u << Buzz_DRIVE_MODE_SHIFT)


#endif /* End Pins Buzz_H */


/* [] END OF FILE */
