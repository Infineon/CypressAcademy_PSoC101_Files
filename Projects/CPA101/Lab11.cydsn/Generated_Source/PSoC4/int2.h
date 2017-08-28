/*******************************************************************************
* File Name: int2.h
* Version 1.70
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_int2_H)
#define CY_ISR_int2_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void int2_Start(void);
void int2_StartEx(cyisraddress address);
void int2_Stop(void);

CY_ISR_PROTO(int2_Interrupt);

void int2_SetVector(cyisraddress address);
cyisraddress int2_GetVector(void);

void int2_SetPriority(uint8 priority);
uint8 int2_GetPriority(void);

void int2_Enable(void);
uint8 int2_GetState(void);
void int2_Disable(void);

void int2_SetPending(void);
void int2_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the int2 ISR. */
#define int2_INTC_VECTOR            ((reg32 *) int2__INTC_VECT)

/* Address of the int2 ISR priority. */
#define int2_INTC_PRIOR             ((reg32 *) int2__INTC_PRIOR_REG)

/* Priority of the int2 interrupt. */
#define int2_INTC_PRIOR_NUMBER      int2__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable int2 interrupt. */
#define int2_INTC_SET_EN            ((reg32 *) int2__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the int2 interrupt. */
#define int2_INTC_CLR_EN            ((reg32 *) int2__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the int2 interrupt state to pending. */
#define int2_INTC_SET_PD            ((reg32 *) int2__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the int2 interrupt. */
#define int2_INTC_CLR_PD            ((reg32 *) int2__INTC_CLR_PD_REG)



#endif /* CY_ISR_int2_H */


/* [] END OF FILE */
