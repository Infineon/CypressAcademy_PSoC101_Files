/*******************************************************************************
* File Name: Software_LED.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_Software_LED_ALIASES_H) /* Pins Software_LED_ALIASES_H */
#define CY_PINS_Software_LED_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define Software_LED_0			(Software_LED__0__PC)
#define Software_LED_0_PS		(Software_LED__0__PS)
#define Software_LED_0_PC		(Software_LED__0__PC)
#define Software_LED_0_DR		(Software_LED__0__DR)
#define Software_LED_0_SHIFT	(Software_LED__0__SHIFT)
#define Software_LED_0_INTR	((uint16)((uint16)0x0003u << (Software_LED__0__SHIFT*2u)))

#define Software_LED_INTR_ALL	 ((uint16)(Software_LED_0_INTR))


#endif /* End Pins Software_LED_ALIASES_H */


/* [] END OF FILE */
