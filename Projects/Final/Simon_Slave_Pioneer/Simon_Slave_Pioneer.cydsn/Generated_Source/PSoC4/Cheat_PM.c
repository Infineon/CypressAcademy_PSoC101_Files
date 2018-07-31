/*******************************************************************************
* File Name: Cheat.c  
* Version 2.20
*
* Description:
*  This file contains APIs to set up the Pins component for low power modes.
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "cytypes.h"
#include "Cheat.h"

static Cheat_BACKUP_STRUCT  Cheat_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Cheat_Sleep
****************************************************************************//**
*
* \brief Stores the pin configuration and prepares the pin for entering chip 
*  deep-sleep/hibernate modes. This function applies only to SIO and USBIO pins.
*  It should not be called for GPIO or GPIO_OVT pins.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None 
*  
* \sideeffect
*  For SIO pins, this function configures the pin input threshold to CMOS and
*  drive level to Vddio. This is needed for SIO pins when in device 
*  deep-sleep/hibernate modes.
*
* \funcusage
*  \snippet Cheat_SUT.c usage_Cheat_Sleep_Wakeup
*******************************************************************************/
void Cheat_Sleep(void)
{
    #if defined(Cheat__PC)
        Cheat_backup.pcState = Cheat_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Cheat_backup.usbState = Cheat_CR1_REG;
            Cheat_USB_POWER_REG |= Cheat_USBIO_ENTER_SLEEP;
            Cheat_CR1_REG &= Cheat_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Cheat__SIO)
        Cheat_backup.sioState = Cheat_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Cheat_SIO_REG &= (uint32)(~Cheat_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Cheat_Wakeup
****************************************************************************//**
*
* \brief Restores the pin configuration that was saved during Pin_Sleep(). This 
* function applies only to SIO and USBIO pins. It should not be called for
* GPIO or GPIO_OVT pins.
*
* For USBIO pins, the wakeup is only triggered for falling edge interrupts.
*
* <b>Note</b> This function is available in PSoC 4 only.
*
* \return 
*  None
*  
* \funcusage
*  Refer to Cheat_Sleep() for an example usage.
*******************************************************************************/
void Cheat_Wakeup(void)
{
    #if defined(Cheat__PC)
        Cheat_PC = Cheat_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Cheat_USB_POWER_REG &= Cheat_USBIO_EXIT_SLEEP_PH1;
            Cheat_CR1_REG = Cheat_backup.usbState;
            Cheat_USB_POWER_REG &= Cheat_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Cheat__SIO)
        Cheat_SIO_REG = Cheat_backup.sioState;
    #endif
}


/* [] END OF FILE */
