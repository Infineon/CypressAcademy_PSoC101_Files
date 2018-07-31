/*******************************************************************************
* File Name: BUZZER.h  
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

#if !defined(CY_PINS_BUZZER_H) /* Pins BUZZER_H */
#define CY_PINS_BUZZER_H

#include "cytypes.h"
#include "cyfitter.h"
#include "BUZZER_aliases.h"


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
} BUZZER_BACKUP_STRUCT;

/** @} structures */


/***************************************
*        Function Prototypes             
***************************************/
/**
* \addtogroup group_general
* @{
*/
uint8   BUZZER_Read(void);
void    BUZZER_Write(uint8 value);
uint8   BUZZER_ReadDataReg(void);
#if defined(BUZZER__PC) || (CY_PSOC4_4200L) 
    void    BUZZER_SetDriveMode(uint8 mode);
#endif
void    BUZZER_SetInterruptMode(uint16 position, uint16 mode);
uint8   BUZZER_ClearInterrupt(void);
/** @} general */

/**
* \addtogroup group_power
* @{
*/
void BUZZER_Sleep(void); 
void BUZZER_Wakeup(void);
/** @} power */


/***************************************
*           API Constants        
***************************************/
#if defined(BUZZER__PC) || (CY_PSOC4_4200L) 
    /* Drive Modes */
    #define BUZZER_DRIVE_MODE_BITS        (3)
    #define BUZZER_DRIVE_MODE_IND_MASK    (0xFFFFFFFFu >> (32 - BUZZER_DRIVE_MODE_BITS))

    /**
    * \addtogroup group_constants
    * @{
    */
        /** \addtogroup driveMode Drive mode constants
         * \brief Constants to be passed as "mode" parameter in the BUZZER_SetDriveMode() function.
         *  @{
         */
        #define BUZZER_DM_ALG_HIZ         (0x00u) /**< \brief High Impedance Analog   */
        #define BUZZER_DM_DIG_HIZ         (0x01u) /**< \brief High Impedance Digital  */
        #define BUZZER_DM_RES_UP          (0x02u) /**< \brief Resistive Pull Up       */
        #define BUZZER_DM_RES_DWN         (0x03u) /**< \brief Resistive Pull Down     */
        #define BUZZER_DM_OD_LO           (0x04u) /**< \brief Open Drain, Drives Low  */
        #define BUZZER_DM_OD_HI           (0x05u) /**< \brief Open Drain, Drives High */
        #define BUZZER_DM_STRONG          (0x06u) /**< \brief Strong Drive            */
        #define BUZZER_DM_RES_UPDWN       (0x07u) /**< \brief Resistive Pull Up/Down  */
        /** @} driveMode */
    /** @} group_constants */
#endif

/* Digital Port Constants */
#define BUZZER_MASK               BUZZER__MASK
#define BUZZER_SHIFT              BUZZER__SHIFT
#define BUZZER_WIDTH              1u

/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BUZZER_SetInterruptMode() function.
     *  @{
     */
        #define BUZZER_INTR_NONE      ((uint16)(0x0000u)) /**< \brief Disabled             */
        #define BUZZER_INTR_RISING    ((uint16)(0x5555u)) /**< \brief Rising edge trigger  */
        #define BUZZER_INTR_FALLING   ((uint16)(0xaaaau)) /**< \brief Falling edge trigger */
        #define BUZZER_INTR_BOTH      ((uint16)(0xffffu)) /**< \brief Both edge trigger    */
    /** @} intrMode */
/** @} group_constants */

/* SIO LPM definition */
#if defined(BUZZER__SIO)
    #define BUZZER_SIO_LPM_MASK       (0x03u)
#endif

/* USBIO definitions */
#if !defined(BUZZER__PC) && (CY_PSOC4_4200L)
    #define BUZZER_USBIO_ENABLE               ((uint32)0x80000000u)
    #define BUZZER_USBIO_DISABLE              ((uint32)(~BUZZER_USBIO_ENABLE))
    #define BUZZER_USBIO_SUSPEND_SHIFT        CYFLD_USBDEVv2_USB_SUSPEND__OFFSET
    #define BUZZER_USBIO_SUSPEND_DEL_SHIFT    CYFLD_USBDEVv2_USB_SUSPEND_DEL__OFFSET
    #define BUZZER_USBIO_ENTER_SLEEP          ((uint32)((1u << BUZZER_USBIO_SUSPEND_SHIFT) \
                                                        | (1u << BUZZER_USBIO_SUSPEND_DEL_SHIFT)))
    #define BUZZER_USBIO_EXIT_SLEEP_PH1       ((uint32)~((uint32)(1u << BUZZER_USBIO_SUSPEND_SHIFT)))
    #define BUZZER_USBIO_EXIT_SLEEP_PH2       ((uint32)~((uint32)(1u << BUZZER_USBIO_SUSPEND_DEL_SHIFT)))
    #define BUZZER_USBIO_CR1_OFF              ((uint32)0xfffffffeu)
#endif


/***************************************
*             Registers        
***************************************/
/* Main Port Registers */
#if defined(BUZZER__PC)
    /* Port Configuration */
    #define BUZZER_PC                 (* (reg32 *) BUZZER__PC)
#endif
/* Pin State */
#define BUZZER_PS                     (* (reg32 *) BUZZER__PS)
/* Data Register */
#define BUZZER_DR                     (* (reg32 *) BUZZER__DR)
/* Input Buffer Disable Override */
#define BUZZER_INP_DIS                (* (reg32 *) BUZZER__PC2)

/* Interrupt configuration Registers */
#define BUZZER_INTCFG                 (* (reg32 *) BUZZER__INTCFG)
#define BUZZER_INTSTAT                (* (reg32 *) BUZZER__INTSTAT)

/* "Interrupt cause" register for Combined Port Interrupt (AllPortInt) in GSRef component */
#if defined (CYREG_GPIO_INTR_CAUSE)
    #define BUZZER_INTR_CAUSE         (* (reg32 *) CYREG_GPIO_INTR_CAUSE)
#endif

/* SIO register */
#if defined(BUZZER__SIO)
    #define BUZZER_SIO_REG            (* (reg32 *) BUZZER__SIO)
#endif /* (BUZZER__SIO_CFG) */

/* USBIO registers */
#if !defined(BUZZER__PC) && (CY_PSOC4_4200L)
    #define BUZZER_USB_POWER_REG       (* (reg32 *) CYREG_USBDEVv2_USB_POWER_CTRL)
    #define BUZZER_CR1_REG             (* (reg32 *) CYREG_USBDEVv2_CR1)
    #define BUZZER_USBIO_CTRL_REG      (* (reg32 *) CYREG_USBDEVv2_USB_USBIO_CTRL)
#endif    
    
    
/***************************************
* The following code is DEPRECATED and 
* must not be used in new designs.
***************************************/
/**
* \addtogroup group_deprecated
* @{
*/
#define BUZZER_DRIVE_MODE_SHIFT       (0x00u)
#define BUZZER_DRIVE_MODE_MASK        (0x07u << BUZZER_DRIVE_MODE_SHIFT)
/** @} deprecated */

#endif /* End Pins BUZZER_H */


/* [] END OF FILE */
