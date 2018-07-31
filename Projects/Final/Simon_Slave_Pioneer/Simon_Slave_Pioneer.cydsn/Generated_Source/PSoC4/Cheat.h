/*******************************************************************************
* File Name: Cheat.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Cheat_H) /* Pins Cheat_H */
#define CY_PINS_Cheat_H

#include "cytypes.h"
#include "cyfitter.h"
#include "Cheat_aliases.h"


/***************************************
*     Data Struct Definitions
***************************************/

/**
* \addtogroup group_structures
* @{
*/
    
/* Structure for sleep mode support */
typedef struct
{
    uint32 pcState; /**< State of the port control register */
    uint32 sioState; /**< State of the SIO configuration */
    uint32 usbState; /**< State of the USBIO regulator */
} Cheat_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   Cheat_Read(void);
void    Cheat_Write(uint8 value);
uint8   Cheat_ReadDataReg(void);
#if defined(Cheat__PC) || (CY_PSOC4_4200L) 
    void    Cheat_SetDriveMode(uint8 mode);
#endif
void    Cheat_SetInterruptMode(uint16 position, uint16 mode);
uint8   Cheat_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void Cheat_Sleep(void); 
void Cheat_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(Cheat__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define Cheat_DRIVE_MODE_BITS        (3)
    #define Cheat_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - Cheat_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the Cheat_SetDriveMode() function.
         *  @{
         */
        #define Cheat_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define Cheat_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define Cheat_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define Cheat_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define Cheat_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define Cheat_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define Cheat_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define Cheat_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define Cheat_MASK               Cheat__MASK
#define Cheat_SHIFT              Cheat__SHIFT
#define Cheat_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Cheat_SetInterruptMode() function.
     *  @{
     */
        #define Cheat_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define Cheat_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define Cheat_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define Cheat_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(Cheat__SIO)
    #define Cheat_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(Cheat__PC) && (CY_PSOC4_4200L)
    #define Cheat_USBIO_ENABLE               ((uint32)0x80000000u)
    #define Cheat_USBIO_DISABLE              ((uint32)(~Cheat_USBIO_ENABLE))
    #define Cheat_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define Cheat_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define Cheat_USBIO_ENTER_SLEEP          ((uint32)((1u << Cheat_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << Cheat_USBIO_SUSPEND_DEL_SHIFT)))
    #define Cheat_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << Cheat_USBIO_SUSPEND_SHIFT)))
    #define Cheat_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << Cheat_USBIO_SUSPEND_DEL_SHIFT)))
    #define Cheat_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(Cheat__PC)
    /* Port Configuration */
    #define Cheat_PC                 (* (reg32 *) Cheat__PC)
#endif
/* Pin State */
#define Cheat_PS                     (* (reg32 *) Cheat__PS)
/* Data Register */
#define Cheat_DR                     (* (reg32 *) Cheat__DR)
/* Input Buffer Disable Override */
#define Cheat_INP_DIS                (* (reg32 *) Cheat__PC2)

/* Interrupt configuration Registers */
#define Cheat_INTCFG                 (* (reg32 *) Cheat__INTCFG)
#define Cheat_INTSTAT                (* (reg32 *) Cheat__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define Cheat_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(Cheat__SIO)
    #define Cheat_SIO_REG            (* (reg32 *) Cheat__SIO)
#endif /* (Cheat__SIO_CFG) */

/* USBIO registers */
#if !defined(Cheat__PC) && (CY_PSOC4_4200L)
    #define Cheat_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define Cheat_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define Cheat_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define Cheat_DRIVE_MODE_SHIFT       (0x00u)
#define Cheat_DRIVE_MODE_MASK        (0x07u << Cheat_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins Cheat_H */


/* [] END OF FILE */
