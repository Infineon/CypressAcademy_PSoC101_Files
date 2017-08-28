/*******************************************************************************
* File Name: LCD_LCDPort.h  
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

#if !defined(CY_PINS_LCD_LCDPort_H) /* Pins LCD_LCDPort_H */
#define CY_PINS_LCD_LCDPort_H

#include "cytypes.h"
#include "cyfitter.h"
#include "LCD_LCDPort_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    LCD_LCDPort_Write(uint8 value) ;
void    LCD_LCDPort_SetDriveMode(uint8 mode) ;
uint8   LCD_LCDPort_ReadDataReg(void) ;
uint8   LCD_LCDPort_Read(void) ;
uint8   LCD_LCDPort_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define LCD_LCDPort_DRIVE_MODE_BITS        (3)
#define LCD_LCDPort_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - LCD_LCDPort_DRIVE_MODE_BITS))

#define LCD_LCDPort_DM_ALG_HIZ         (0x00u)
#define LCD_LCDPort_DM_DIG_HIZ         (0x01u)
#define LCD_LCDPort_DM_RES_UP          (0x02u)
#define LCD_LCDPort_DM_RES_DWN         (0x03u)
#define LCD_LCDPort_DM_OD_LO           (0x04u)
#define LCD_LCDPort_DM_OD_HI           (0x05u)
#define LCD_LCDPort_DM_STRONG          (0x06u)
#define LCD_LCDPort_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define LCD_LCDPort_MASK               LCD_LCDPort__MASK
#define LCD_LCDPort_SHIFT              LCD_LCDPort__SHIFT
#define LCD_LCDPort_WIDTH              7u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define LCD_LCDPort_PS                     (* (reg32 *) LCD_LCDPort__PS)
/* Port Configuration */
#define LCD_LCDPort_PC                     (* (reg32 *) LCD_LCDPort__PC)
/* Data Register */
#define LCD_LCDPort_DR                     (* (reg32 *) LCD_LCDPort__DR)
/* Input Buffer Disable Override */
#define LCD_LCDPort_INP_DIS                (* (reg32 *) LCD_LCDPort__PC2)


#if defined(LCD_LCDPort__INTSTAT)  /* Interrupt Registers */

    #define LCD_LCDPort_INTSTAT                (* (reg32 *) LCD_LCDPort__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define LCD_LCDPort_DRIVE_MODE_SHIFT       (0x00u)
#define LCD_LCDPort_DRIVE_MODE_MASK        (0x07u << LCD_LCDPort_DRIVE_MODE_SHIFT)


#endif /* End Pins LCD_LCDPort_H */


/* [] END OF FILE */
