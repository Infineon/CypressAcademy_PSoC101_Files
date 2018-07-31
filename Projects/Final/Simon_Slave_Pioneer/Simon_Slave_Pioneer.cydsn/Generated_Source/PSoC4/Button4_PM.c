/*******************************************************************************
* File Name: Button4.c  
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
#include "Button4.h"

static Button4_BACKUP_STRUCT  Button4_backup = {0u, 0u, 0u};


/*******************************************************************************
* Function Name: Button4_Sleep
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
*  \snippet Button4_SUT.c usage_Button4_Sleep_Wakeup
*******************************************************************************/
void Button4_Sleep(void)
{
    #if defined(Button4__PC)
        Button4_backup.pcState = Button4_PC;
    #else
        #if (CY_PSOC4_4200L)
            /* Save the regulator state and put the PHY into suspend mode */
            Button4_backup.usbState = Button4_CR1_REG;
            Button4_USB_POWER_REG |= Button4_USBIO_ENTER_SLEEP;
            Button4_CR1_REG &= Button4_USBIO_CR1_OFF;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Button4__SIO)
        Button4_backup.sioState = Button4_SIO_REG;
        /* SIO requires unregulated output buffer and single ended input buffer */
        Button4_SIO_REG &= (uint32)(~Button4_SIO_LPM_MASK);
    #endif  
}


/*******************************************************************************
* Function Name: Button4_Wakeup
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
*  Refer to Button4_Sleep() for an example usage.
*******************************************************************************/
void Button4_Wakeup(void)
{
    #if defined(Button4__PC)
        Button4_PC = Button4_backup.pcState;
    #else
        #if (CY_PSOC4_4200L)
            /* Restore the regulator state and come out of suspend mode */
            Button4_USB_POWER_REG &= Button4_USBIO_EXIT_SLEEP_PH1;
            Button4_CR1_REG = Button4_backup.usbState;
            Button4_USB_POWER_REG &= Button4_USBIO_EXIT_SLEEP_PH2;
        #endif
    #endif
    #if defined(CYIPBLOCK_m0s8ioss_VERSION) && defined(Button4__SIO)
        Button4_SIO_REG = Button4_backup.sioState;
    #endif
}


/* [] END OF FILE */
