/*******************************************************************************
* File Name: Button2.h  
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

#if !defined(CY_PINS_Button2_H) /* Pins Button2_H */
#define CY_PINS_Button2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Button2_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    Button2_Write(uint8 value) ;
void    Button2_SetDriveMode(uint8 mode) ;
uint8   Button2_ReadDataReg(void) ;
uint8   Button2_Read(void) ;
uint8   Button2_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define Button2_DRIVE_MODE_BITS        (3)
#define Button2_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Button2_DRIVE_MODE_BITS))

#define Button2_DM_ALG_HIZ         (0x00u)
#define Button2_DM_DIG_HIZ         (0x01u)
#define Button2_DM_RES_UP          (0x02u)
#define Button2_DM_RES_DWN         (0x03u)
#define Button2_DM_OD_LO           (0x04u)
#define Button2_DM_OD_HI           (0x05u)
#define Button2_DM_STRONG          (0x06u)
#define Button2_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define Button2_MASK               Button2__MASK
#define Button2_SHIFT              Button2__SHIFT
#define Button2_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Button2_PS                     (* (reg32 *) Button2__PS)
/* Port Configuration */
#define Button2_PC                     (* (reg32 *) Button2__PC)
/* Data Register */
#define Button2_DR                     (* (reg32 *) Button2__DR)
/* Input Buffer Disable Override */
#define Button2_INP_DIS                (* (reg32 *) Button2__PC2)


#if defined(Button2__INTSTAT)  /* Interrupt Registers */

    #define Button2_INTSTAT                (* (reg32 *) Button2__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define Button2_DRIVE_MODE_SHIFT       (0x00u)
#define Button2_DRIVE_MODE_MASK        (0x07u << Button2_DRIVE_MODE_SHIFT)


#endif /* End Pins Button2_H */


/* [] END OF FILE */
