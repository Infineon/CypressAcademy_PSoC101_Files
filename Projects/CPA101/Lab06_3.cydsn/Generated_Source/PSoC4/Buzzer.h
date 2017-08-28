/*******************************************************************************
* File Name: Buzzer.h  
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

#if !defined(CY_PINS_Buzzer_H) /* Pins Buzzer_H */
#define CY_PINS_Buzzer_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Buzzer_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Buzzer_Write(uint8 value) ;
void    Buzzer_SetDriveMode(uint8 mode) ;
uint8   Buzzer_ReadDataReg(void) ;
uint8   Buzzer_Read(void) ;
uint8   Buzzer_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Buzzer_DRIVE_MODE_BITS        (3)
#define Buzzer_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Buzzer_DRIVE_MODE_BITS))

#define Buzzer_DM_ALG_HIZ         (0x00u)
#define Buzzer_DM_DIG_HIZ         (0x01u)
#define Buzzer_DM_RES_UP          (0x02u)
#define Buzzer_DM_RES_DWN         (0x03u)
#define Buzzer_DM_OD_LO           (0x04u)
#define Buzzer_DM_OD_HI           (0x05u)
#define Buzzer_DM_STRONG          (0x06u)
#define Buzzer_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Buzzer_MASK               Buzzer__MASK
#define Buzzer_SHIFT              Buzzer__SHIFT
#define Buzzer_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Buzzer_PS                     (* (reg32 *) Buzzer__PS)
/* Port Configuration */
#define Buzzer_PC                     (* (reg32 *) Buzzer__PC)
/* Data Register */
#define Buzzer_DR                     (* (reg32 *) Buzzer__DR)
/* Input Buffer Disable Override */
#define Buzzer_INP_DIS                (* (reg32 *) Buzzer__PC2)


#if defined(Buzzer__INTSTAT)  /* Interrupt Registers */

    #define Buzzer_INTSTAT                (* (reg32 *) Buzzer__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Buzzer_DRIVE_MODE_SHIFT       (0x00u)
#define Buzzer_DRIVE_MODE_MASK        (0x07u << Buzzer_DRIVE_MODE_SHIFT)


#endif /* End Pins Buzzer_H */


/* [] END OF FILE */
