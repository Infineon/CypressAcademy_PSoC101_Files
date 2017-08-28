/*******************************************************************************
* File Name: Button1.h  
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

#if !defined(CY_PINS_Button1_H) /* Pins Button1_H */
#define CY_PINS_Button1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Button1_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Button1_Write(uint8 value) ;
void    Button1_SetDriveMode(uint8 mode) ;
uint8   Button1_ReadDataReg(void) ;
uint8   Button1_Read(void) ;
uint8   Button1_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Button1_DRIVE_MODE_BITS        (3)
#define Button1_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Button1_DRIVE_MODE_BITS))

#define Button1_DM_ALG_HIZ         (0x00u)
#define Button1_DM_DIG_HIZ         (0x01u)
#define Button1_DM_RES_UP          (0x02u)
#define Button1_DM_RES_DWN         (0x03u)
#define Button1_DM_OD_LO           (0x04u)
#define Button1_DM_OD_HI           (0x05u)
#define Button1_DM_STRONG          (0x06u)
#define Button1_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Button1_MASK               Button1__MASK
#define Button1_SHIFT              Button1__SHIFT
#define Button1_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Button1_PS                     (* (reg32 *) Button1__PS)
/* Port Configuration */
#define Button1_PC                     (* (reg32 *) Button1__PC)
/* Data Register */
#define Button1_DR                     (* (reg32 *) Button1__DR)
/* Input Buffer Disable Override */
#define Button1_INP_DIS                (* (reg32 *) Button1__PC2)


#if defined(Button1__INTSTAT)  /* Interrupt Registers */

    #define Button1_INTSTAT                (* (reg32 *) Button1__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Button1_DRIVE_MODE_SHIFT       (0x00u)
#define Button1_DRIVE_MODE_MASK        (0x07u << Button1_DRIVE_MODE_SHIFT)


#endif /* End Pins Button1_H */


/* [] END OF FILE */
