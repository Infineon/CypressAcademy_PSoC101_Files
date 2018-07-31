/*******************************************************************************
* File Name: PWM_Fail.h
* Version 2.10
*
* Description:
*  This file provides constants and parameter values for the PWM_Fail
*  component.
*
* Note:
*  None
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_TCPWM_PWM_Fail_H)
#define CY_TCPWM_PWM_Fail_H


#include "CyLib.h"
#include "cytypes.h"
#include "cyfitter.h"


/*******************************************************************************
* Internal Type defines
*******************************************************************************/

/* Structure to save state before go to sleep */
typedef struct
{
    uint8  enableState;
} PWM_Fail_BACKUP_STRUCT;


/*******************************************************************************
* Variables
*******************************************************************************/
extern uint8  PWM_Fail_initVar;


/***************************************
*   Conditional Compilation Parameters
****************************************/

#define PWM_Fail_CY_TCPWM_V2                    (CYIPBLOCK_m0s8tcpwm_VERSION == 2u)
#define PWM_Fail_CY_TCPWM_4000                  (CY_PSOC4_4000)

/* TCPWM Configuration */
#define PWM_Fail_CONFIG                         (7lu)

/* Quad Mode */
/* Parameters */
#define PWM_Fail_QUAD_ENCODING_MODES            (0lu)
#define PWM_Fail_QUAD_AUTO_START                (0lu)

/* Signal modes */
#define PWM_Fail_QUAD_INDEX_SIGNAL_MODE         (0lu)
#define PWM_Fail_QUAD_PHIA_SIGNAL_MODE          (3lu)
#define PWM_Fail_QUAD_PHIB_SIGNAL_MODE          (3lu)
#define PWM_Fail_QUAD_STOP_SIGNAL_MODE          (0lu)

/* Signal present */
#define PWM_Fail_QUAD_INDEX_SIGNAL_PRESENT      (0lu)
#define PWM_Fail_QUAD_STOP_SIGNAL_PRESENT       (0lu)

/* Interrupt Mask */
#define PWM_Fail_QUAD_INTERRUPT_MASK            (1lu)

/* Timer/Counter Mode */
/* Parameters */
#define PWM_Fail_TC_RUN_MODE                    (0lu)
#define PWM_Fail_TC_COUNTER_MODE                (0lu)
#define PWM_Fail_TC_COMP_CAP_MODE               (2lu)
#define PWM_Fail_TC_PRESCALER                   (0lu)

/* Signal modes */
#define PWM_Fail_TC_RELOAD_SIGNAL_MODE          (0lu)
#define PWM_Fail_TC_COUNT_SIGNAL_MODE           (3lu)
#define PWM_Fail_TC_START_SIGNAL_MODE           (0lu)
#define PWM_Fail_TC_STOP_SIGNAL_MODE            (0lu)
#define PWM_Fail_TC_CAPTURE_SIGNAL_MODE         (0lu)

/* Signal present */
#define PWM_Fail_TC_RELOAD_SIGNAL_PRESENT       (0lu)
#define PWM_Fail_TC_COUNT_SIGNAL_PRESENT        (0lu)
#define PWM_Fail_TC_START_SIGNAL_PRESENT        (0lu)
#define PWM_Fail_TC_STOP_SIGNAL_PRESENT         (0lu)
#define PWM_Fail_TC_CAPTURE_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PWM_Fail_TC_INTERRUPT_MASK              (1lu)

/* PWM Mode */
/* Parameters */
#define PWM_Fail_PWM_KILL_EVENT                 (0lu)
#define PWM_Fail_PWM_STOP_EVENT                 (0lu)
#define PWM_Fail_PWM_MODE                       (4lu)
#define PWM_Fail_PWM_OUT_N_INVERT               (0lu)
#define PWM_Fail_PWM_OUT_INVERT                 (0lu)
#define PWM_Fail_PWM_ALIGN                      (0lu)
#define PWM_Fail_PWM_RUN_MODE                   (0lu)
#define PWM_Fail_PWM_DEAD_TIME_CYCLE            (0lu)
#define PWM_Fail_PWM_PRESCALER                  (0lu)

/* Signal modes */
#define PWM_Fail_PWM_RELOAD_SIGNAL_MODE         (0lu)
#define PWM_Fail_PWM_COUNT_SIGNAL_MODE          (3lu)
#define PWM_Fail_PWM_START_SIGNAL_MODE          (0lu)
#define PWM_Fail_PWM_STOP_SIGNAL_MODE           (0lu)
#define PWM_Fail_PWM_SWITCH_SIGNAL_MODE         (0lu)

/* Signal present */
#define PWM_Fail_PWM_RELOAD_SIGNAL_PRESENT      (0lu)
#define PWM_Fail_PWM_COUNT_SIGNAL_PRESENT       (0lu)
#define PWM_Fail_PWM_START_SIGNAL_PRESENT       (0lu)
#define PWM_Fail_PWM_STOP_SIGNAL_PRESENT        (0lu)
#define PWM_Fail_PWM_SWITCH_SIGNAL_PRESENT      (0lu)

/* Interrupt Mask */
#define PWM_Fail_PWM_INTERRUPT_MASK             (1lu)


/***************************************
*    Initial Parameter Constants
***************************************/

/* Timer/Counter Mode */
#define PWM_Fail_TC_PERIOD_VALUE                (65535lu)
#define PWM_Fail_TC_COMPARE_VALUE               (65535lu)
#define PWM_Fail_TC_COMPARE_BUF_VALUE           (65535lu)
#define PWM_Fail_TC_COMPARE_SWAP                (0lu)

/* PWM Mode */
#define PWM_Fail_PWM_PERIOD_VALUE               (30lu)
#define PWM_Fail_PWM_PERIOD_BUF_VALUE           (65535lu)
#define PWM_Fail_PWM_PERIOD_SWAP                (0lu)
#define PWM_Fail_PWM_COMPARE_VALUE              (15lu)
#define PWM_Fail_PWM_COMPARE_BUF_VALUE          (65535lu)
#define PWM_Fail_PWM_COMPARE_SWAP               (0lu)


/***************************************
*    Enumerated Types and Parameters
***************************************/

#define PWM_Fail__LEFT 0
#define PWM_Fail__RIGHT 1
#define PWM_Fail__CENTER 2
#define PWM_Fail__ASYMMETRIC 3

#define PWM_Fail__X1 0
#define PWM_Fail__X2 1
#define PWM_Fail__X4 2

#define PWM_Fail__PWM 4
#define PWM_Fail__PWM_DT 5
#define PWM_Fail__PWM_PR 6

#define PWM_Fail__INVERSE 1
#define PWM_Fail__DIRECT 0

#define PWM_Fail__CAPTURE 2
#define PWM_Fail__COMPARE 0

#define PWM_Fail__TRIG_LEVEL 3
#define PWM_Fail__TRIG_RISING 0
#define PWM_Fail__TRIG_FALLING 1
#define PWM_Fail__TRIG_BOTH 2

#define PWM_Fail__INTR_MASK_TC 1
#define PWM_Fail__INTR_MASK_CC_MATCH 2
#define PWM_Fail__INTR_MASK_NONE 0
#define PWM_Fail__INTR_MASK_TC_CC 3

#define PWM_Fail__UNCONFIG 8
#define PWM_Fail__TIMER 1
#define PWM_Fail__QUAD 3
#define PWM_Fail__PWM_SEL 7

#define PWM_Fail__COUNT_UP 0
#define PWM_Fail__COUNT_DOWN 1
#define PWM_Fail__COUNT_UPDOWN0 2
#define PWM_Fail__COUNT_UPDOWN1 3


/* Prescaler */
#define PWM_Fail_PRESCALE_DIVBY1                ((uint32)(0u << PWM_Fail_PRESCALER_SHIFT))
#define PWM_Fail_PRESCALE_DIVBY2                ((uint32)(1u << PWM_Fail_PRESCALER_SHIFT))
#define PWM_Fail_PRESCALE_DIVBY4                ((uint32)(2u << PWM_Fail_PRESCALER_SHIFT))
#define PWM_Fail_PRESCALE_DIVBY8                ((uint32)(3u << PWM_Fail_PRESCALER_SHIFT))
#define PWM_Fail_PRESCALE_DIVBY16               ((uint32)(4u << PWM_Fail_PRESCALER_SHIFT))
#define PWM_Fail_PRESCALE_DIVBY32               ((uint32)(5u << PWM_Fail_PRESCALER_SHIFT))
#define PWM_Fail_PRESCALE_DIVBY64               ((uint32)(6u << PWM_Fail_PRESCALER_SHIFT))
#define PWM_Fail_PRESCALE_DIVBY128              ((uint32)(7u << PWM_Fail_PRESCALER_SHIFT))

/* TCPWM set modes */
#define PWM_Fail_MODE_TIMER_COMPARE             ((uint32)(PWM_Fail__COMPARE         <<  \
                                                                  PWM_Fail_MODE_SHIFT))
#define PWM_Fail_MODE_TIMER_CAPTURE             ((uint32)(PWM_Fail__CAPTURE         <<  \
                                                                  PWM_Fail_MODE_SHIFT))
#define PWM_Fail_MODE_QUAD                      ((uint32)(PWM_Fail__QUAD            <<  \
                                                                  PWM_Fail_MODE_SHIFT))
#define PWM_Fail_MODE_PWM                       ((uint32)(PWM_Fail__PWM             <<  \
                                                                  PWM_Fail_MODE_SHIFT))
#define PWM_Fail_MODE_PWM_DT                    ((uint32)(PWM_Fail__PWM_DT          <<  \
                                                                  PWM_Fail_MODE_SHIFT))
#define PWM_Fail_MODE_PWM_PR                    ((uint32)(PWM_Fail__PWM_PR          <<  \
                                                                  PWM_Fail_MODE_SHIFT))

/* Quad Modes */
#define PWM_Fail_MODE_X1                        ((uint32)(PWM_Fail__X1              <<  \
                                                                  PWM_Fail_QUAD_MODE_SHIFT))
#define PWM_Fail_MODE_X2                        ((uint32)(PWM_Fail__X2              <<  \
                                                                  PWM_Fail_QUAD_MODE_SHIFT))
#define PWM_Fail_MODE_X4                        ((uint32)(PWM_Fail__X4              <<  \
                                                                  PWM_Fail_QUAD_MODE_SHIFT))

/* Counter modes */
#define PWM_Fail_COUNT_UP                       ((uint32)(PWM_Fail__COUNT_UP        <<  \
                                                                  PWM_Fail_UPDOWN_SHIFT))
#define PWM_Fail_COUNT_DOWN                     ((uint32)(PWM_Fail__COUNT_DOWN      <<  \
                                                                  PWM_Fail_UPDOWN_SHIFT))
#define PWM_Fail_COUNT_UPDOWN0                  ((uint32)(PWM_Fail__COUNT_UPDOWN0   <<  \
                                                                  PWM_Fail_UPDOWN_SHIFT))
#define PWM_Fail_COUNT_UPDOWN1                  ((uint32)(PWM_Fail__COUNT_UPDOWN1   <<  \
                                                                  PWM_Fail_UPDOWN_SHIFT))

/* PWM output invert */
#define PWM_Fail_INVERT_LINE                    ((uint32)(PWM_Fail__INVERSE         <<  \
                                                                  PWM_Fail_INV_OUT_SHIFT))
#define PWM_Fail_INVERT_LINE_N                  ((uint32)(PWM_Fail__INVERSE         <<  \
                                                                  PWM_Fail_INV_COMPL_OUT_SHIFT))

/* Trigger modes */
#define PWM_Fail_TRIG_RISING                    ((uint32)PWM_Fail__TRIG_RISING)
#define PWM_Fail_TRIG_FALLING                   ((uint32)PWM_Fail__TRIG_FALLING)
#define PWM_Fail_TRIG_BOTH                      ((uint32)PWM_Fail__TRIG_BOTH)
#define PWM_Fail_TRIG_LEVEL                     ((uint32)PWM_Fail__TRIG_LEVEL)

/* Interrupt mask */
#define PWM_Fail_INTR_MASK_TC                   ((uint32)PWM_Fail__INTR_MASK_TC)
#define PWM_Fail_INTR_MASK_CC_MATCH             ((uint32)PWM_Fail__INTR_MASK_CC_MATCH)

/* PWM Output Controls */
#define PWM_Fail_CC_MATCH_SET                   (0x00u)
#define PWM_Fail_CC_MATCH_CLEAR                 (0x01u)
#define PWM_Fail_CC_MATCH_INVERT                (0x02u)
#define PWM_Fail_CC_MATCH_NO_CHANGE             (0x03u)
#define PWM_Fail_OVERLOW_SET                    (0x00u)
#define PWM_Fail_OVERLOW_CLEAR                  (0x04u)
#define PWM_Fail_OVERLOW_INVERT                 (0x08u)
#define PWM_Fail_OVERLOW_NO_CHANGE              (0x0Cu)
#define PWM_Fail_UNDERFLOW_SET                  (0x00u)
#define PWM_Fail_UNDERFLOW_CLEAR                (0x10u)
#define PWM_Fail_UNDERFLOW_INVERT               (0x20u)
#define PWM_Fail_UNDERFLOW_NO_CHANGE            (0x30u)

/* PWM Align */
#define PWM_Fail_PWM_MODE_LEFT                  (PWM_Fail_CC_MATCH_CLEAR        |   \
                                                         PWM_Fail_OVERLOW_SET           |   \
                                                         PWM_Fail_UNDERFLOW_NO_CHANGE)
#define PWM_Fail_PWM_MODE_RIGHT                 (PWM_Fail_CC_MATCH_SET          |   \
                                                         PWM_Fail_OVERLOW_NO_CHANGE     |   \
                                                         PWM_Fail_UNDERFLOW_CLEAR)
#define PWM_Fail_PWM_MODE_ASYM                  (PWM_Fail_CC_MATCH_INVERT       |   \
                                                         PWM_Fail_OVERLOW_SET           |   \
                                                         PWM_Fail_UNDERFLOW_CLEAR)

#if (PWM_Fail_CY_TCPWM_V2)
    #if(PWM_Fail_CY_TCPWM_4000)
        #define PWM_Fail_PWM_MODE_CENTER                (PWM_Fail_CC_MATCH_INVERT       |   \
                                                                 PWM_Fail_OVERLOW_NO_CHANGE     |   \
                                                                 PWM_Fail_UNDERFLOW_CLEAR)
    #else
        #define PWM_Fail_PWM_MODE_CENTER                (PWM_Fail_CC_MATCH_INVERT       |   \
                                                                 PWM_Fail_OVERLOW_SET           |   \
                                                                 PWM_Fail_UNDERFLOW_CLEAR)
    #endif /* (PWM_Fail_CY_TCPWM_4000) */
#else
    #define PWM_Fail_PWM_MODE_CENTER                (PWM_Fail_CC_MATCH_INVERT       |   \
                                                             PWM_Fail_OVERLOW_NO_CHANGE     |   \
                                                             PWM_Fail_UNDERFLOW_CLEAR)
#endif /* (PWM_Fail_CY_TCPWM_NEW) */

/* Command operations without condition */
#define PWM_Fail_CMD_CAPTURE                    (0u)
#define PWM_Fail_CMD_RELOAD                     (8u)
#define PWM_Fail_CMD_STOP                       (16u)
#define PWM_Fail_CMD_START                      (24u)

/* Status */
#define PWM_Fail_STATUS_DOWN                    (1u)
#define PWM_Fail_STATUS_RUNNING                 (2u)


/***************************************
*        Function Prototypes
****************************************/

void   PWM_Fail_Init(void);
void   PWM_Fail_Enable(void);
void   PWM_Fail_Start(void);
void   PWM_Fail_Stop(void);

void   PWM_Fail_SetMode(uint32 mode);
void   PWM_Fail_SetCounterMode(uint32 counterMode);
void   PWM_Fail_SetPWMMode(uint32 modeMask);
void   PWM_Fail_SetQDMode(uint32 qdMode);

void   PWM_Fail_SetPrescaler(uint32 prescaler);
void   PWM_Fail_TriggerCommand(uint32 mask, uint32 command);
void   PWM_Fail_SetOneShot(uint32 oneShotEnable);
uint32 PWM_Fail_ReadStatus(void);

void   PWM_Fail_SetPWMSyncKill(uint32 syncKillEnable);
void   PWM_Fail_SetPWMStopOnKill(uint32 stopOnKillEnable);
void   PWM_Fail_SetPWMDeadTime(uint32 deadTime);
void   PWM_Fail_SetPWMInvert(uint32 mask);

void   PWM_Fail_SetInterruptMode(uint32 interruptMask);
uint32 PWM_Fail_GetInterruptSourceMasked(void);
uint32 PWM_Fail_GetInterruptSource(void);
void   PWM_Fail_ClearInterrupt(uint32 interruptMask);
void   PWM_Fail_SetInterrupt(uint32 interruptMask);

void   PWM_Fail_WriteCounter(uint32 count);
uint32 PWM_Fail_ReadCounter(void);

uint32 PWM_Fail_ReadCapture(void);
uint32 PWM_Fail_ReadCaptureBuf(void);

void   PWM_Fail_WritePeriod(uint32 period);
uint32 PWM_Fail_ReadPeriod(void);
void   PWM_Fail_WritePeriodBuf(uint32 periodBuf);
uint32 PWM_Fail_ReadPeriodBuf(void);

void   PWM_Fail_WriteCompare(uint32 compare);
uint32 PWM_Fail_ReadCompare(void);
void   PWM_Fail_WriteCompareBuf(uint32 compareBuf);
uint32 PWM_Fail_ReadCompareBuf(void);

void   PWM_Fail_SetPeriodSwap(uint32 swapEnable);
void   PWM_Fail_SetCompareSwap(uint32 swapEnable);

void   PWM_Fail_SetCaptureMode(uint32 triggerMode);
void   PWM_Fail_SetReloadMode(uint32 triggerMode);
void   PWM_Fail_SetStartMode(uint32 triggerMode);
void   PWM_Fail_SetStopMode(uint32 triggerMode);
void   PWM_Fail_SetCountMode(uint32 triggerMode);

void   PWM_Fail_SaveConfig(void);
void   PWM_Fail_RestoreConfig(void);
void   PWM_Fail_Sleep(void);
void   PWM_Fail_Wakeup(void);


/***************************************
*             Registers
***************************************/

#define PWM_Fail_BLOCK_CONTROL_REG              (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PWM_Fail_BLOCK_CONTROL_PTR              ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__TCPWM_CTRL )
#define PWM_Fail_COMMAND_REG                    (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PWM_Fail_COMMAND_PTR                    ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__TCPWM_CMD )
#define PWM_Fail_INTRRUPT_CAUSE_REG             (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PWM_Fail_INTRRUPT_CAUSE_PTR             ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__TCPWM_INTR_CAUSE )
#define PWM_Fail_CONTROL_REG                    (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__CTRL )
#define PWM_Fail_CONTROL_PTR                    ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__CTRL )
#define PWM_Fail_STATUS_REG                     (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__STATUS )
#define PWM_Fail_STATUS_PTR                     ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__STATUS )
#define PWM_Fail_COUNTER_REG                    (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__COUNTER )
#define PWM_Fail_COUNTER_PTR                    ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__COUNTER )
#define PWM_Fail_COMP_CAP_REG                   (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__CC )
#define PWM_Fail_COMP_CAP_PTR                   ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__CC )
#define PWM_Fail_COMP_CAP_BUF_REG               (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__CC_BUFF )
#define PWM_Fail_COMP_CAP_BUF_PTR               ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__CC_BUFF )
#define PWM_Fail_PERIOD_REG                     (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__PERIOD )
#define PWM_Fail_PERIOD_PTR                     ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__PERIOD )
#define PWM_Fail_PERIOD_BUF_REG                 (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PWM_Fail_PERIOD_BUF_PTR                 ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__PERIOD_BUFF )
#define PWM_Fail_TRIG_CONTROL0_REG              (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PWM_Fail_TRIG_CONTROL0_PTR              ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__TR_CTRL0 )
#define PWM_Fail_TRIG_CONTROL1_REG              (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PWM_Fail_TRIG_CONTROL1_PTR              ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__TR_CTRL1 )
#define PWM_Fail_TRIG_CONTROL2_REG              (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PWM_Fail_TRIG_CONTROL2_PTR              ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__TR_CTRL2 )
#define PWM_Fail_INTERRUPT_REQ_REG              (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__INTR )
#define PWM_Fail_INTERRUPT_REQ_PTR              ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__INTR )
#define PWM_Fail_INTERRUPT_SET_REG              (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__INTR_SET )
#define PWM_Fail_INTERRUPT_SET_PTR              ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__INTR_SET )
#define PWM_Fail_INTERRUPT_MASK_REG             (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__INTR_MASK )
#define PWM_Fail_INTERRUPT_MASK_PTR             ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__INTR_MASK )
#define PWM_Fail_INTERRUPT_MASKED_REG           (*(reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__INTR_MASKED )
#define PWM_Fail_INTERRUPT_MASKED_PTR           ( (reg32 *) PWM_Fail_cy_m0s8_tcpwm_1__INTR_MASKED )


/***************************************
*       Registers Constants
***************************************/

/* Mask */
#define PWM_Fail_MASK                           ((uint32)PWM_Fail_cy_m0s8_tcpwm_1__TCPWM_CTRL_MASK)

/* Shift constants for control register */
#define PWM_Fail_RELOAD_CC_SHIFT                (0u)
#define PWM_Fail_RELOAD_PERIOD_SHIFT            (1u)
#define PWM_Fail_PWM_SYNC_KILL_SHIFT            (2u)
#define PWM_Fail_PWM_STOP_KILL_SHIFT            (3u)
#define PWM_Fail_PRESCALER_SHIFT                (8u)
#define PWM_Fail_UPDOWN_SHIFT                   (16u)
#define PWM_Fail_ONESHOT_SHIFT                  (18u)
#define PWM_Fail_QUAD_MODE_SHIFT                (20u)
#define PWM_Fail_INV_OUT_SHIFT                  (20u)
#define PWM_Fail_INV_COMPL_OUT_SHIFT            (21u)
#define PWM_Fail_MODE_SHIFT                     (24u)

/* Mask constants for control register */
#define PWM_Fail_RELOAD_CC_MASK                 ((uint32)(PWM_Fail_1BIT_MASK        <<  \
                                                                            PWM_Fail_RELOAD_CC_SHIFT))
#define PWM_Fail_RELOAD_PERIOD_MASK             ((uint32)(PWM_Fail_1BIT_MASK        <<  \
                                                                            PWM_Fail_RELOAD_PERIOD_SHIFT))
#define PWM_Fail_PWM_SYNC_KILL_MASK             ((uint32)(PWM_Fail_1BIT_MASK        <<  \
                                                                            PWM_Fail_PWM_SYNC_KILL_SHIFT))
#define PWM_Fail_PWM_STOP_KILL_MASK             ((uint32)(PWM_Fail_1BIT_MASK        <<  \
                                                                            PWM_Fail_PWM_STOP_KILL_SHIFT))
#define PWM_Fail_PRESCALER_MASK                 ((uint32)(PWM_Fail_8BIT_MASK        <<  \
                                                                            PWM_Fail_PRESCALER_SHIFT))
#define PWM_Fail_UPDOWN_MASK                    ((uint32)(PWM_Fail_2BIT_MASK        <<  \
                                                                            PWM_Fail_UPDOWN_SHIFT))
#define PWM_Fail_ONESHOT_MASK                   ((uint32)(PWM_Fail_1BIT_MASK        <<  \
                                                                            PWM_Fail_ONESHOT_SHIFT))
#define PWM_Fail_QUAD_MODE_MASK                 ((uint32)(PWM_Fail_3BIT_MASK        <<  \
                                                                            PWM_Fail_QUAD_MODE_SHIFT))
#define PWM_Fail_INV_OUT_MASK                   ((uint32)(PWM_Fail_2BIT_MASK        <<  \
                                                                            PWM_Fail_INV_OUT_SHIFT))
#define PWM_Fail_MODE_MASK                      ((uint32)(PWM_Fail_3BIT_MASK        <<  \
                                                                            PWM_Fail_MODE_SHIFT))

/* Shift constants for trigger control register 1 */
#define PWM_Fail_CAPTURE_SHIFT                  (0u)
#define PWM_Fail_COUNT_SHIFT                    (2u)
#define PWM_Fail_RELOAD_SHIFT                   (4u)
#define PWM_Fail_STOP_SHIFT                     (6u)
#define PWM_Fail_START_SHIFT                    (8u)

/* Mask constants for trigger control register 1 */
#define PWM_Fail_CAPTURE_MASK                   ((uint32)(PWM_Fail_2BIT_MASK        <<  \
                                                                  PWM_Fail_CAPTURE_SHIFT))
#define PWM_Fail_COUNT_MASK                     ((uint32)(PWM_Fail_2BIT_MASK        <<  \
                                                                  PWM_Fail_COUNT_SHIFT))
#define PWM_Fail_RELOAD_MASK                    ((uint32)(PWM_Fail_2BIT_MASK        <<  \
                                                                  PWM_Fail_RELOAD_SHIFT))
#define PWM_Fail_STOP_MASK                      ((uint32)(PWM_Fail_2BIT_MASK        <<  \
                                                                  PWM_Fail_STOP_SHIFT))
#define PWM_Fail_START_MASK                     ((uint32)(PWM_Fail_2BIT_MASK        <<  \
                                                                  PWM_Fail_START_SHIFT))

/* MASK */
#define PWM_Fail_1BIT_MASK                      ((uint32)0x01u)
#define PWM_Fail_2BIT_MASK                      ((uint32)0x03u)
#define PWM_Fail_3BIT_MASK                      ((uint32)0x07u)
#define PWM_Fail_6BIT_MASK                      ((uint32)0x3Fu)
#define PWM_Fail_8BIT_MASK                      ((uint32)0xFFu)
#define PWM_Fail_16BIT_MASK                     ((uint32)0xFFFFu)

/* Shift constant for status register */
#define PWM_Fail_RUNNING_STATUS_SHIFT           (30u)


/***************************************
*    Initial Constants
***************************************/

#define PWM_Fail_CTRL_QUAD_BASE_CONFIG                                                          \
        (((uint32)(PWM_Fail_QUAD_ENCODING_MODES     << PWM_Fail_QUAD_MODE_SHIFT))       |\
         ((uint32)(PWM_Fail_CONFIG                  << PWM_Fail_MODE_SHIFT)))

#define PWM_Fail_CTRL_PWM_BASE_CONFIG                                                           \
        (((uint32)(PWM_Fail_PWM_STOP_EVENT          << PWM_Fail_PWM_STOP_KILL_SHIFT))   |\
         ((uint32)(PWM_Fail_PWM_OUT_INVERT          << PWM_Fail_INV_OUT_SHIFT))         |\
         ((uint32)(PWM_Fail_PWM_OUT_N_INVERT        << PWM_Fail_INV_COMPL_OUT_SHIFT))   |\
         ((uint32)(PWM_Fail_PWM_MODE                << PWM_Fail_MODE_SHIFT)))

#define PWM_Fail_CTRL_PWM_RUN_MODE                                                              \
            ((uint32)(PWM_Fail_PWM_RUN_MODE         << PWM_Fail_ONESHOT_SHIFT))
            
#define PWM_Fail_CTRL_PWM_ALIGN                                                                 \
            ((uint32)(PWM_Fail_PWM_ALIGN            << PWM_Fail_UPDOWN_SHIFT))

#define PWM_Fail_CTRL_PWM_KILL_EVENT                                                            \
             ((uint32)(PWM_Fail_PWM_KILL_EVENT      << PWM_Fail_PWM_SYNC_KILL_SHIFT))

#define PWM_Fail_CTRL_PWM_DEAD_TIME_CYCLE                                                       \
            ((uint32)(PWM_Fail_PWM_DEAD_TIME_CYCLE  << PWM_Fail_PRESCALER_SHIFT))

#define PWM_Fail_CTRL_PWM_PRESCALER                                                             \
            ((uint32)(PWM_Fail_PWM_PRESCALER        << PWM_Fail_PRESCALER_SHIFT))

#define PWM_Fail_CTRL_TIMER_BASE_CONFIG                                                         \
        (((uint32)(PWM_Fail_TC_PRESCALER            << PWM_Fail_PRESCALER_SHIFT))       |\
         ((uint32)(PWM_Fail_TC_COUNTER_MODE         << PWM_Fail_UPDOWN_SHIFT))          |\
         ((uint32)(PWM_Fail_TC_RUN_MODE             << PWM_Fail_ONESHOT_SHIFT))         |\
         ((uint32)(PWM_Fail_TC_COMP_CAP_MODE        << PWM_Fail_MODE_SHIFT)))
        
#define PWM_Fail_QUAD_SIGNALS_MODES                                                             \
        (((uint32)(PWM_Fail_QUAD_PHIA_SIGNAL_MODE   << PWM_Fail_COUNT_SHIFT))           |\
         ((uint32)(PWM_Fail_QUAD_INDEX_SIGNAL_MODE  << PWM_Fail_RELOAD_SHIFT))          |\
         ((uint32)(PWM_Fail_QUAD_STOP_SIGNAL_MODE   << PWM_Fail_STOP_SHIFT))            |\
         ((uint32)(PWM_Fail_QUAD_PHIB_SIGNAL_MODE   << PWM_Fail_START_SHIFT)))

#define PWM_Fail_PWM_SIGNALS_MODES                                                              \
        (((uint32)(PWM_Fail_PWM_SWITCH_SIGNAL_MODE  << PWM_Fail_CAPTURE_SHIFT))         |\
         ((uint32)(PWM_Fail_PWM_COUNT_SIGNAL_MODE   << PWM_Fail_COUNT_SHIFT))           |\
         ((uint32)(PWM_Fail_PWM_RELOAD_SIGNAL_MODE  << PWM_Fail_RELOAD_SHIFT))          |\
         ((uint32)(PWM_Fail_PWM_STOP_SIGNAL_MODE    << PWM_Fail_STOP_SHIFT))            |\
         ((uint32)(PWM_Fail_PWM_START_SIGNAL_MODE   << PWM_Fail_START_SHIFT)))

#define PWM_Fail_TIMER_SIGNALS_MODES                                                            \
        (((uint32)(PWM_Fail_TC_CAPTURE_SIGNAL_MODE  << PWM_Fail_CAPTURE_SHIFT))         |\
         ((uint32)(PWM_Fail_TC_COUNT_SIGNAL_MODE    << PWM_Fail_COUNT_SHIFT))           |\
         ((uint32)(PWM_Fail_TC_RELOAD_SIGNAL_MODE   << PWM_Fail_RELOAD_SHIFT))          |\
         ((uint32)(PWM_Fail_TC_STOP_SIGNAL_MODE     << PWM_Fail_STOP_SHIFT))            |\
         ((uint32)(PWM_Fail_TC_START_SIGNAL_MODE    << PWM_Fail_START_SHIFT)))
        
#define PWM_Fail_TIMER_UPDOWN_CNT_USED                                                          \
                ((PWM_Fail__COUNT_UPDOWN0 == PWM_Fail_TC_COUNTER_MODE)                  ||\
                 (PWM_Fail__COUNT_UPDOWN1 == PWM_Fail_TC_COUNTER_MODE))

#define PWM_Fail_PWM_UPDOWN_CNT_USED                                                            \
                ((PWM_Fail__CENTER == PWM_Fail_PWM_ALIGN)                               ||\
                 (PWM_Fail__ASYMMETRIC == PWM_Fail_PWM_ALIGN))               
        
#define PWM_Fail_PWM_PR_INIT_VALUE              (1u)
#define PWM_Fail_QUAD_PERIOD_INIT_VALUE         (0x8000u)



#endif /* End CY_TCPWM_PWM_Fail_H */

/* [] END OF FILE */
