/*******************************************************************************
* File Name: SpeedPin.h  
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

#if !defined(CY_PINS_SpeedPin_ALIASES_H) /* Pins SpeedPin_ALIASES_H */
#define CY_PINS_SpeedPin_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"


/***************************************
*              Constants        
***************************************/
#define SpeedPin_0			(SpeedPin__0__PC)
#define SpeedPin_0_PS		(SpeedPin__0__PS)
#define SpeedPin_0_PC		(SpeedPin__0__PC)
#define SpeedPin_0_DR		(SpeedPin__0__DR)
#define SpeedPin_0_SHIFT	(SpeedPin__0__SHIFT)
#define SpeedPin_0_INTR	((uint16)((uint16)0x0003u << (SpeedPin__0__SHIFT*2u)))

#define SpeedPin_INTR_ALL	 ((uint16)(SpeedPin_0_INTR))


#endif /* End Pins SpeedPin_ALIASES_H */


/* [] END OF FILE */
