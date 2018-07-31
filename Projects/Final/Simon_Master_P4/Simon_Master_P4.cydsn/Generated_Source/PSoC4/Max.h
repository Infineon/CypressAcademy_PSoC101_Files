/*******************************************************************************
* File Name: Max.h  
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

#if !defined(CY_PINS_Max_H) /* Pins Max_H */
#define CY_PINS_Max_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Max_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Max_Write(uint8 value) ;
void    Max_SetDriveMode(uint8 mode) ;
uint8   Max_ReadDataReg(void) ;
uint8   Max_Read(void) ;
uint8   Max_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Max_DRIVE_MODE_BITS        (3)
#define Max_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Max_DRIVE_MODE_BITS))
#define Max_DRIVE_MODE_SHIFT       (0x00u)
#define Max_DRIVE_MODE_MASK        (0x07u << Max_DRIVE_MODE_SHIFT)

#define Max_DM_ALG_HIZ         (0x00u << Max_DRIVE_MODE_SHIFT)
#define Max_DM_DIG_HIZ         (0x01u << Max_DRIVE_MODE_SHIFT)
#define Max_DM_RES_UP          (0x02u << Max_DRIVE_MODE_SHIFT)
#define Max_DM_RES_DWN         (0x03u << Max_DRIVE_MODE_SHIFT)
#define Max_DM_OD_LO           (0x04u << Max_DRIVE_MODE_SHIFT)
#define Max_DM_OD_HI           (0x05u << Max_DRIVE_MODE_SHIFT)
#define Max_DM_STRONG          (0x06u << Max_DRIVE_MODE_SHIFT)
#define Max_DM_RES_UPDWN       (0x07u << Max_DRIVE_MODE_SHIFT)

/* Digital Port Constants */
#define Max_MASK               Max__MASK
#define Max_SHIFT              Max__SHIFT
#define Max_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Max_PS                     (* (reg32 *) Max__PS)
/* Port Configuration */
#define Max_PC                     (* (reg32 *) Max__PC)
/* Data Register */
#define Max_DR                     (* (reg32 *) Max__DR)
/* Input Buffer Disable Override */
#define Max_INP_DIS                (* (reg32 *) Max__PC2)


#if defined(Max__INTSTAT)  /* Interrupt Registers */

    #define Max_INTSTAT                (* (reg32 *) Max__INTSTAT)

#endif /* Interrupt Registers */

#endif /* End Pins Max_H */


/* [] END OF FILE */
