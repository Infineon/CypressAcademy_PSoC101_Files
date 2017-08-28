/*******************************************************************************
* File Name: Vin.h  
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

#if !defined(CY_PINS_Vin_H) /* Pins Vin_H */
#define CY_PINS_Vin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Vin_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Vin_Write(uint8 value) ;
void    Vin_SetDriveMode(uint8 mode) ;
uint8   Vin_ReadDataReg(void) ;
uint8   Vin_Read(void) ;
uint8   Vin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Vin_DRIVE_MODE_BITS        (3)
#define Vin_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Vin_DRIVE_MODE_BITS))

#define Vin_DM_ALG_HIZ         (0x00u)
#define Vin_DM_DIG_HIZ         (0x01u)
#define Vin_DM_RES_UP          (0x02u)
#define Vin_DM_RES_DWN         (0x03u)
#define Vin_DM_OD_LO           (0x04u)
#define Vin_DM_OD_HI           (0x05u)
#define Vin_DM_STRONG          (0x06u)
#define Vin_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Vin_MASK               Vin__MASK
#define Vin_SHIFT              Vin__SHIFT
#define Vin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Vin_PS                     (* (reg32 *) Vin__PS)
/* Port Configuration */
#define Vin_PC                     (* (reg32 *) Vin__PC)
/* Data Register */
#define Vin_DR                     (* (reg32 *) Vin__DR)
/* Input Buffer Disable Override */
#define Vin_INP_DIS                (* (reg32 *) Vin__PC2)


#if defined(Vin__INTSTAT)  /* Interrupt Registers */

    #define Vin_INTSTAT                (* (reg32 *) Vin__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Vin_DRIVE_MODE_SHIFT       (0x00u)
#define Vin_DRIVE_MODE_MASK        (0x07u << Vin_DRIVE_MODE_SHIFT)


#endif /* End Pins Vin_H */


/* [] END OF FILE */
