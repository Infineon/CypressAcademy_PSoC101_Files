/*******************************************************************************
* File Name: Red.h  
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

#if !defined(CY_PINS_Red_H) /* Pins Red_H */
#define CY_PINS_Red_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Red_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Red_Write(uint8 value) ;
void    Red_SetDriveMode(uint8 mode) ;
uint8   Red_ReadDataReg(void) ;
uint8   Red_Read(void) ;
uint8   Red_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Red_DRIVE_MODE_BITS        (3)
#define Red_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Red_DRIVE_MODE_BITS))

#define Red_DM_ALG_HIZ         (0x00u)
#define Red_DM_DIG_HIZ         (0x01u)
#define Red_DM_RES_UP          (0x02u)
#define Red_DM_RES_DWN         (0x03u)
#define Red_DM_OD_LO           (0x04u)
#define Red_DM_OD_HI           (0x05u)
#define Red_DM_STRONG          (0x06u)
#define Red_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Red_MASK               Red__MASK
#define Red_SHIFT              Red__SHIFT
#define Red_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Red_PS                     (* (reg32 *) Red__PS)
/* Port Configuration */
#define Red_PC                     (* (reg32 *) Red__PC)
/* Data Register */
#define Red_DR                     (* (reg32 *) Red__DR)
/* Input Buffer Disable Override */
#define Red_INP_DIS                (* (reg32 *) Red__PC2)


#if defined(Red__INTSTAT)  /* Interrupt Registers */

    #define Red_INTSTAT                (* (reg32 *) Red__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Red_DRIVE_MODE_SHIFT       (0x00u)
#define Red_DRIVE_MODE_MASK        (0x07u << Red_DRIVE_MODE_SHIFT)


#endif /* End Pins Red_H */


/* [] END OF FILE */
