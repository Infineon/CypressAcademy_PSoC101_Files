/*******************************************************************************
* File Name: HostInt_Pin.h  
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

#if !defined(CY_PINS_HostInt_Pin_H) /* Pins HostInt_Pin_H */
#define CY_PINS_HostInt_Pin_H

#include "cytypes.h"
#include "cyfitter.h"
#include "HostInt_Pin_aliases.h"


/***************************************
*        Function Prototypes             
***************************************/    

void    HostInt_Pin_Write(uint8 value) ;
void    HostInt_Pin_SetDriveMode(uint8 mode) ;
uint8   HostInt_Pin_ReadDataReg(void) ;
uint8   HostInt_Pin_Read(void) ;
uint8   HostInt_Pin_ClearInterrupt(void) ;


/***************************************
*           API Constants        
***************************************/

/* Drive Modes */
#define HostInt_Pin_DRIVE_MODE_BITS        (3)
#define HostInt_Pin_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - HostInt_Pin_DRIVE_MODE_BITS))

#define HostInt_Pin_DM_ALG_HIZ         (0x00u)
#define HostInt_Pin_DM_DIG_HIZ         (0x01u)
#define HostInt_Pin_DM_RES_UP          (0x02u)
#define HostInt_Pin_DM_RES_DWN         (0x03u)
#define HostInt_Pin_DM_OD_LO           (0x04u)
#define HostInt_Pin_DM_OD_HI           (0x05u)
#define HostInt_Pin_DM_STRONG          (0x06u)
#define HostInt_Pin_DM_RES_UPDWN       (0x07u)

/* Digital Port Constants */
#define HostInt_Pin_MASK               HostInt_Pin__MASK
#define HostInt_Pin_SHIFT              HostInt_Pin__SHIFT
#define HostInt_Pin_WIDTH              1u


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define HostInt_Pin_PS                     (* (reg32 *) HostInt_Pin__PS)
/* Port Configuration */
#define HostInt_Pin_PC                     (* (reg32 *) HostInt_Pin__PC)
/* Data Register */
#define HostInt_Pin_DR                     (* (reg32 *) HostInt_Pin__DR)
/* Input Buffer Disable Override */
#define HostInt_Pin_INP_DIS                (* (reg32 *) HostInt_Pin__PC2)


#if defined(HostInt_Pin__INTSTAT)  /* Interrupt Registers */

    #define HostInt_Pin_INTSTAT                (* (reg32 *) HostInt_Pin__INTSTAT)

#endif /* Interrupt Registers */


/***************************************
* The following code is DEPRECATED and 
* must not be used.
***************************************/

#define HostInt_Pin_DRIVE_MODE_SHIFT       (0x00u)
#define HostInt_Pin_DRIVE_MODE_MASK        (0x07u << HostInt_Pin_DRIVE_MODE_SHIFT)


#endif /* End Pins HostInt_Pin_H */


/* [] END OF FILE */
