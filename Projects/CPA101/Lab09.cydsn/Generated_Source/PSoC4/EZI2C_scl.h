/*******************************************************************************
* File Name: EZI2C_scl.h  
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

#if !defined(CY_PINS_EZI2C_scl_H) /* Pins EZI2C_scl_H */
#define CY_PINS_EZI2C_scl_H

#include "cytypes.h"
#include "cyfitter.h"
#include "EZI2C_scl_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    EZI2C_scl_Write(uint8 value) ;
void    EZI2C_scl_SetDriveMode(uint8 mode) ;
uint8   EZI2C_scl_ReadDataReg(void) ;
uint8   EZI2C_scl_Read(void) ;
uint8   EZI2C_scl_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define EZI2C_scl_DRIVE_MODE_BITS        (3)
#define EZI2C_scl_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - EZI2C_scl_DRIVE_MODE_BITS))

#define EZI2C_scl_DM_ALG_HIZ         (0x00u)
#define EZI2C_scl_DM_DIG_HIZ         (0x01u)
#define EZI2C_scl_DM_RES_UP          (0x02u)
#define EZI2C_scl_DM_RES_DWN         (0x03u)
#define EZI2C_scl_DM_OD_LO           (0x04u)
#define EZI2C_scl_DM_OD_HI           (0x05u)
#define EZI2C_scl_DM_STRONG          (0x06u)
#define EZI2C_scl_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define EZI2C_scl_MASK               EZI2C_scl__MASK
#define EZI2C_scl_SHIFT              EZI2C_scl__SHIFT
#define EZI2C_scl_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define EZI2C_scl_PS                     (* (reg32 *) EZI2C_scl__PS)
/* Port Configuration */
#define EZI2C_scl_PC                     (* (reg32 *) EZI2C_scl__PC)
/* Data Register */
#define EZI2C_scl_DR                     (* (reg32 *) EZI2C_scl__DR)
/* Input Buffer Disable Override */
#define EZI2C_scl_INP_DIS                (* (reg32 *) EZI2C_scl__PC2)


#if defined(EZI2C_scl__INTSTAT)  /* Interrupt Registers */

    #define EZI2C_scl_INTSTAT                (* (reg32 *) EZI2C_scl__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define EZI2C_scl_DRIVE_MODE_SHIFT       (0x00u)
#define EZI2C_scl_DRIVE_MODE_MASK        (0x07u << EZI2C_scl_DRIVE_MODE_SHIFT)


#endif /* End Pins EZI2C_scl_H */


/* [] END OF FILE */
