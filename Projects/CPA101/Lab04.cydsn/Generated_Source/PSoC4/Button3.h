/*******************************************************************************
* File Name: Button3.h  
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

#if !defined(CY_PINS_Button3_H) /* Pins Button3_H */
#define CY_PINS_Button3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Button3_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Button3_Write(uint8 value) ;
void    Button3_SetDriveMode(uint8 mode) ;
uint8   Button3_ReadDataReg(void) ;
uint8   Button3_Read(void) ;
uint8   Button3_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Button3_DRIVE_MODE_BITS        (3)
#define Button3_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Button3_DRIVE_MODE_BITS))

#define Button3_DM_ALG_HIZ         (0x00u)
#define Button3_DM_DIG_HIZ         (0x01u)
#define Button3_DM_RES_UP          (0x02u)
#define Button3_DM_RES_DWN         (0x03u)
#define Button3_DM_OD_LO           (0x04u)
#define Button3_DM_OD_HI           (0x05u)
#define Button3_DM_STRONG          (0x06u)
#define Button3_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Button3_MASK               Button3__MASK
#define Button3_SHIFT              Button3__SHIFT
#define Button3_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Button3_PS                     (* (reg32 *) Button3__PS)
/* Port Configuration */
#define Button3_PC                     (* (reg32 *) Button3__PC)
/* Data Register */
#define Button3_DR                     (* (reg32 *) Button3__DR)
/* Input Buffer Disable Override */
#define Button3_INP_DIS                (* (reg32 *) Button3__PC2)


#if defined(Button3__INTSTAT)  /* Interrupt Registers */

    #define Button3_INTSTAT                (* (reg32 *) Button3__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Button3_DRIVE_MODE_SHIFT       (0x00u)
#define Button3_DRIVE_MODE_MASK        (0x07u << Button3_DRIVE_MODE_SHIFT)


#endif /* End Pins Button3_H */


/* [] END OF FILE */
