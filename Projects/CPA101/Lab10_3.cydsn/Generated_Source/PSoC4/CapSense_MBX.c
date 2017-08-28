/*******************************************************************************
* File Name: CapSense_MBX.c
* Version 2.10
*
* Description:
*  This file provides the source code of Tuner communication APIs for the
*  CapSense CSD component.
*
* Note:
*
********************************************************************************
* Copyright 2013-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "CapSense_MBX.h"


/*******************************************************************************
*  Place your includes, defines and code here
********************************************************************************/
/* `#START CapSense_MBX` */

/* `#END` */

#if (CapSense_TUNING_METHOD == CapSense__TUNING_MANUAL)
    /*******************************************************************************
    * Function Name: CapSense_InitCsdParams
    ********************************************************************************
    *
    * Summary:
    *  Configures the CSD parameters to match the parameters in the inbox.
    *  Used only in the manual tuning mode to apply new scanning parameters from the Tuner
    *  GUI.
    *
    * Parameters:
    *  inbox:  Pointer to Inbox structure in RAM.
    *
    * Return:
    *  None. Contents of the structure are not modified.
    *
    * Global Variables:
    *  CapSense_modulationIDAC[]      - stores modulation IDAC values.
    *  CapSense_compensationIDAC[]    - stores compensation IDAC values.
    *  CapSense_widgetResolution[]    - used to store the scan resolution values for each widget.
    *  CapSense_senseClkDividerVal[]  - used to store the sense clock divider values for each widget.
    *  CapSense_sampleClkDividerVal[] - used to store the sample clock divider values for each widget.
    *  CapSense_fingerThreshold[]     - used to store the finger threshold values for each widget.
    *  CapSense_noiseThreshold[]      - used to store the noise threshold values for each widget.
    *  CapSense_hysteresis[]          - used to store the hysteresis values for each widget.
    *  CapSense_debounce[]            - used to store the debounce values for each widget.
    *
    *******************************************************************************/
    static void CapSense_InitCsdParams(volatile const CapSense_INBOX *inbox);
    static void CapSense_InitCsdParams(volatile const CapSense_INBOX *inbox)
    {
        /* Define widget sensor belongs to */
        uint8 sensor = inbox->sensorIndex;
        uint8 widget = CapSense_widgetNumber[sensor];

        /* Scanning parameters */
        #if(0u == CapSense_AUTOCALIBRATION_ENABLE)
            CapSense_modulationIDAC[sensor] = inbox->CapSense_inboxCsdCfg.modulatorIDAC;

            #if (CapSense_IDAC_CNT == 2u)
                CapSense_compensationIDAC[sensor] = inbox->CapSense_inboxCsdCfg.compensationIDAC;
            #endif /* ( CapSense_IDAC_CNT == 2u ) */
        #endif /* (0u != CapSense_AUTOCALIBRATION_ENABLE) */

        CapSense_SetIDACRange((uint32)inbox->CapSense_inboxCsdCfg.idacRange);

        CapSense_widgetResolution[widget] =
        (uint32)(~(CapSense_RESOLUTION_16_BITS << inbox->CapSense_inboxCsdCfg.scanResolution));

        CapSense_widgetResolution[widget] &= CapSense_RESOLUTION_16_BITS;

        #if (0u != CapSense_MULTIPLE_FREQUENCY_SET )
            CapSense_senseClkDividerVal[sensor] = inbox->CapSense_inboxCsdCfg.analogSwitchDivider;
            CapSense_sampleClkDividerVal[sensor] = inbox->CapSense_inboxCsdCfg.modulatorDivider;
        #else
            CapSense_senseClkDividerVal = inbox->CapSense_inboxCsdCfg.analogSwitchDivider;
            CapSense_sampleClkDividerVal = inbox->CapSense_inboxCsdCfg.modulatorDivider;
        #endif /* (0u != CapSense_MULTIPLE_FREQUENCY_SET ) */

        #if(0u != CapSense_CSHL_API_GENERATE)
            #if (0u != CapSense_TOTAL_GENERICS_COUNT)
                /* Exclude generic widget */
                if(widget < CapSense_END_OF_WIDGETS_INDEX)
                {
            #endif  /* 0u != CapSense_TOTAL_GENERICS_COUNT */

                /* High level parameters */
                CapSense_fingerThreshold[widget] = inbox->CapSense_inboxCsdCfg.fingerThreshold;
                CapSense_noiseThreshold[widget]  = inbox->CapSense_inboxCsdCfg.noiseThreshold;

                CapSense_hysteresis[widget] = inbox->CapSense_inboxCsdCfg.hysteresis;
                CapSense_debounce[widget]   = inbox->CapSense_inboxCsdCfg.debounce;

                #if(CapSense_TOTAL_TRACKPAD_GESTURES_COUNT > 0u)
                    CapSense_centroidMult[widget] = (uint16)((inbox->CapSense_inboxCsdCfg.apiResolution *
                                                            (uint32)CapSense_RES_MULT) / (uint32)CapSense_numberOfSensors[widget]);

                #endif /* (CapSense_TOTAL_TRACKPAD_GESTURES_COUNT > 0u) */

            #if (0u != CapSense_TOTAL_GENERICS_COUNT)
                /* Exclude generic widget */
                }
            #endif  /* 0u != CapSense_TOTAL_GENERICS_COUNT */

            /* Re-Init baseline */
            CapSense_InitializeAllBaselines();
        #endif /* (0u != CapSense_CSHL_API_GENERATE) */
    }
#endif  /* (CapSense_TUNING_METHOD == CapSense__TUNING_MANUAL) */


    /*******************************************************************************
    * Function Name: CapSense_InitGesturesParams
    ********************************************************************************
    *
    * Summary:
    *  Configures the parameters of gestures to match the parameters in the inbox.
    *  Used only in the manual and auto tuning mode or if the gestures support is enabled.
    *  Intended apply new scanning parameters from the Tuner GUI.
    *
    * Parameters:
    *  inbox:  Pointer to Inbox structure in RAM.
    *
    * Return:
    *  None. Contents of the structure are not modified.
    *
    *******************************************************************************/
#if((CapSense_TUNING_METHOD != CapSense__TUNING_NONE) && (0u != CapSense_TOTAL_TRACKPAD_GESTURES_COUNT))
    static void CapSense_InitGesturesParams(volatile const CapSense_INBOX *inbox);
    static void CapSense_InitGesturesParams(volatile const CapSense_INBOX *inbox)
    {
        #if(0u != CapSense_IS_ANY_GESTURES_EN)
            #if(0u != CapSense_CLICK_GEST_ENABLED)
                CapSense_gesturesConfig.clickRadiusX            = (uint8)inbox->CapSense_inboxTmgCfg.clickRadiusX;
                CapSense_gesturesConfig.clickRadiusY            = (uint8)inbox->CapSense_inboxTmgCfg.clickRadiusY;
                CapSense_gesturesConfig.doubleClickRadius       = (uint8)inbox->CapSense_inboxTmgCfg.doubleClickRadius;
                CapSense_gesturesConfig.STDoubleClickTimeoutMax = inbox->CapSense_inboxTmgCfg.stDoubleClickTimeoutMax;
                CapSense_gesturesConfig.STDoubleClickTimeoutMin = inbox->CapSense_inboxTmgCfg.stDoubleClickTimeoutMin;
                CapSense_gesturesConfig.STClickTimeoutMax       = inbox->CapSense_inboxTmgCfg.stClickTimeoutMax;
                CapSense_gesturesConfig.STClickTimeoutMin       = inbox->CapSense_inboxTmgCfg.stClickTimeoutMin;
                CapSense_gesturesConfig.DTClickTimeoutMax       = inbox->CapSense_inboxTmgCfg.dtClickTimeoutMax;
                CapSense_gesturesConfig.DTClickTimeoutMin       = inbox->CapSense_inboxTmgCfg.dtClickTimeoutMin;
            #endif /* (0u != CapSense_CLICK_GEST_ENABLED) */

            #if(0u != CapSense_ZOOM_GEST_ENABLED)
                CapSense_gesturesConfig.dtScrollToZoomDebounce  = inbox->CapSense_inboxTmgCfg.dtPanToZoomDebounce;
                CapSense_gesturesConfig.DTZoomDebounce          = inbox->CapSense_inboxTmgCfg.dtZoomDebounce;
                CapSense_gesturesConfig.zoomActiveDistanceX     = inbox->CapSense_inboxTmgCfg.zoomActiveDistanceX;
                CapSense_gesturesConfig.zoomActiveDistanceY     = inbox->CapSense_inboxTmgCfg.zoomActiveDistanceY;
            #endif /* (0u != CapSense_ZOOM_GEST_ENABLED) */

            #if(0u != CapSense_ST_SCROLL_GEST_ENABLED)
                CapSense_gesturesConfig.stScrollDebounce        = inbox->CapSense_inboxTmgCfg.stScrDebounce;

                CapSense_gesturesConfig.stScrollThreshold1X     = inbox->CapSense_inboxTmgCfg.stScrThreshold1X;
                CapSense_gesturesConfig.stScrollThreshold2X     = inbox->CapSense_inboxTmgCfg.stScrThreshold2X;
                CapSense_gesturesConfig.stScrollThreshold3X     = inbox->CapSense_inboxTmgCfg.stScrThreshold3X;
                CapSense_gesturesConfig.stScrollThreshold4X     = inbox->CapSense_inboxTmgCfg.stScrThreshold4X;
                CapSense_gesturesConfig.stScrollThreshold1Y     = inbox->CapSense_inboxTmgCfg.stScrThreshold1Y;
                CapSense_gesturesConfig.stScrollThreshold2Y     = inbox->CapSense_inboxTmgCfg.stScrThreshold2Y;
                CapSense_gesturesConfig.stScrollThreshold3Y     = inbox->CapSense_inboxTmgCfg.stScrThreshold3Y;
                CapSense_gesturesConfig.stScrollThreshold4Y     = inbox->CapSense_inboxTmgCfg.stScrThreshold4Y;
                CapSense_gesturesConfig.stScrollStep1           = inbox->CapSense_inboxTmgCfg.stScrStep1;
                CapSense_gesturesConfig.stScrollStep2           = inbox->CapSense_inboxTmgCfg.stScrStep2;
                CapSense_gesturesConfig.stScrollStep3           = inbox->CapSense_inboxTmgCfg.stScrStep3;
                CapSense_gesturesConfig.stScrollStep4           = inbox->CapSense_inboxTmgCfg.stScrStep4;
                CapSense_gesturesConfig.stInScrActiveDistanceX  = inbox->CapSense_inboxTmgCfg.stInScrActiveDistanceX;
                CapSense_gesturesConfig.stInScrActiveDistanceY  = inbox->CapSense_inboxTmgCfg.stInScrActiveDistanceY;
                CapSense_gesturesConfig.stInScrCountLevel       = inbox->CapSense_inboxTmgCfg.stInScrCountLevel;
            #endif /* (0u != CapSense_ST_SCROLL_GEST_ENABLED) */

            #if(0u != CapSense_DT_SCROLL_GEST_ENABLED)
                CapSense_gesturesConfig.dtScrollDebounce        = inbox->CapSense_inboxTmgCfg.dtScrDebounce;
                CapSense_gesturesConfig.dtScrollThreshold1X     = inbox->CapSense_inboxTmgCfg.dtScrThreshold1X;
                CapSense_gesturesConfig.dtScrollThreshold2X     = inbox->CapSense_inboxTmgCfg.dtScrThreshold2X;
                CapSense_gesturesConfig.dtScrollThreshold3X     = inbox->CapSense_inboxTmgCfg.dtScrThreshold3X;
                CapSense_gesturesConfig.dtScrollThreshold4X     = inbox->CapSense_inboxTmgCfg.dtScrThreshold4X;
                CapSense_gesturesConfig.dtScrollThreshold1Y     = inbox->CapSense_inboxTmgCfg.dtScrThreshold1Y;
                CapSense_gesturesConfig.dtScrollThreshold2Y     = inbox->CapSense_inboxTmgCfg.dtScrThreshold2Y;
                CapSense_gesturesConfig.dtScrollThreshold3Y     = inbox->CapSense_inboxTmgCfg.dtScrThreshold3Y;
                CapSense_gesturesConfig.dtScrollThreshold4Y     = inbox->CapSense_inboxTmgCfg.dtScrThreshold4Y;
                CapSense_gesturesConfig.dtScrollStep1           = inbox->CapSense_inboxTmgCfg.dtScrStep1;
                CapSense_gesturesConfig.dtScrollStep2           = inbox->CapSense_inboxTmgCfg.dtScrStep2;
                CapSense_gesturesConfig.dtScrollStep3           = inbox->CapSense_inboxTmgCfg.dtScrStep3;
                CapSense_gesturesConfig.dtScrollStep4           = inbox->CapSense_inboxTmgCfg.dtScrStep4;
                CapSense_gesturesConfig.dtInScrActiveDistanceX  = inbox->CapSense_inboxTmgCfg.dtInScrActiveDistanceX;
                CapSense_gesturesConfig.dtInScrActiveDistanceY  = inbox->CapSense_inboxTmgCfg.dtInScrActiveDistanceY;
                CapSense_gesturesConfig.dtInScrCountLevel       = inbox->CapSense_inboxTmgCfg.dtInScrCountLevel;
            #endif /* (0u != CapSense_DT_SCROLL_GEST_ENABLED) */

            #if(0u != CapSense_FLICK_GEST_ENABLED)
                CapSense_gesturesConfig.flickSampleTime         = inbox->CapSense_inboxTmgCfg.flickSampleTime;
                CapSense_gesturesConfig.flickActiveDistanceX    = inbox->CapSense_inboxTmgCfg.flickActiveDistanceX;
                CapSense_gesturesConfig.flickActiveDistanceY    = inbox->CapSense_inboxTmgCfg.flickActiveDistanceY;
            #endif /* (0u != CapSense_FLICK_GEST_ENABLED) */

            #if(0u != CapSense_ROTATE_GEST_ENABLED)
                CapSense_gesturesConfig.rotateDebounce          = inbox->CapSense_inboxTmgCfg.rotateDebounce;
            #endif /* (0u != CapSense_ROTATE_GEST_ENABLED) */

            #if(0u != CapSense_EDGE_SWIPE_GEST_ENABLED)
                CapSense_gesturesConfig.edgeSwipeActiveDistance = inbox->CapSense_inboxTmgCfg.edgeSwipeActiveDistance;
                CapSense_gesturesConfig.bottomAngleThreshold    = inbox->CapSense_inboxTmgCfg.bottomAngleThreshold;
                CapSense_gesturesConfig.edgeSwipeTimeout        = inbox->CapSense_inboxTmgCfg.edgeSwipeTime;
                CapSense_TMG_edgeSwipeCompleteTimeout           = inbox->CapSense_inboxTmgCfg.edgeSwipeCompleteTimeout;
                CapSense_gesturesConfig.topAngleThreshold       = inbox->CapSense_inboxTmgCfg.topAngleThreshold;
                CapSense_gesturesConfig.widthOfDisambiguation   = inbox->CapSense_inboxTmgCfg.widthOfDisambiguation;
            #endif /* (0u != CapSense_EDGE_SWIPE_GEST_ENABLED) */

            CapSense_TMG_InitGestures(&CapSense_gesturesConfig);
        #endif /* (0u != CapSense_IS_ANY_GESTURES_EN) */

        #if(0u != CapSense_TP_GESTURE_POS_FILTERS_MASK)
            CapSense_posFiltersMask[CapSense_TRACKPAD__TPG] = inbox->CapSense_inboxTmgCfg.filtersMask;
        #endif /* (0u != CapSense_TP_GESTURE_POS_FILTERS_MASK) */

        #if(0u != (CapSense_XY_ADAPTIVE_IIR_MASK & CapSense_TP_GESTURE_POS_FILTERS_MASK))
            CapSense_adpFltOptions.divVal       = inbox->CapSense_inboxTmgCfg.filterDivisor;
            CapSense_adpFltOptions.largeMovTh   = inbox->CapSense_inboxTmgCfg.largeMovThreshold;
            CapSense_adpFltOptions.littleMovTh  = inbox->CapSense_inboxTmgCfg.littleMovThreshold;
            CapSense_adpFltOptions.maxK     = inbox->CapSense_inboxTmgCfg.maxFilterCoef;
            CapSense_adpFltOptions.minK     = inbox->CapSense_inboxTmgCfg.minFilterCoef;
            CapSense_adpFltOptions.noMovTh      = inbox->CapSense_inboxTmgCfg.noMovThreshold;
        #endif /* (0u != (CapSense_XY_ADAPTIVE_IIR_MASK & CapSense_TP_GESTURE_POS_FILTERS_MASK)) */
    }
#endif /* ((CapSense_TUNING_METHOD != CapSense__TUNING_NONE) && (0u != CapSense_TOTAL_TRACKPAD_GESTURES_COUNT)) */


/*******************************************************************************
* Function Name: CapSense_InitMailbox
********************************************************************************
*
* Summary:
*  Initializes parameters of the mailbox structure.
*  Sets the type and size of the mailbox structure.
*  Sets a check sum to check by the Tuner GUI and noReadMsg flag to indicate that this
*  is the first communication packet.
*
* Parameters:
*  mbx:  Pointer to Mailbox structure in RAM.
*
* Return:
*  None. Modifies the contents of mbx and mbx->outbox.
*
* Global Variables:
*  None
*
*******************************************************************************/
void CapSense_InitMailbox(volatile CapSense_MAILBOX *mbx)
{
    /* Restore TYPE_ID (clear busy flag) to indicate "action complete" */
    mbx->type = CapSense_TYPE_ID;
    /* Restore default value - clear "have_msg" */
    mbx->size = sizeof(CapSense_MAILBOX);

    /* Additional fields for async and reset handling */
    #if((CapSense_TUNING_METHOD != CapSense__TUNING_NONE) && (0u != CapSense_TOTAL_TRACKPAD_GESTURES_COUNT) ||\
        (CapSense_TUNING_METHOD == CapSense__TUNING_MANUAL))
        mbx->outbox.noReadMessage = 1u;
    #endif  /* ((CapSense_TUNING_METHOD != CapSense__TUNING_NONE) && (0u != CapSense_TOTAL_TRACKPAD_GESTURES_COUNT) ||\
                (CapSense_TUNING_METHOD == CapSense__TUNING_MANUAL)) */

    mbx->outbox.checkSum = (uint16)(CapSense_CHECK_SUM);
}


/*******************************************************************************
* Function Name:  CapSense_PostMessage
********************************************************************************
*
* Summary:
*  This blocking function waits while the Tuner GUI reports that the mailbox content
*  could be modified (clears CapSense_BUSY_FLAG). Then loads the report
*  data to the outbox and sets a busy flag.
*  In the manual tuning mode the report data is:
*    - raw data, baseline, signal;
*  In the auto tuning mode the added data is:
*    - fingerThreshold;
*    - noiseThreshold;
*    - scanResolution;
*    - idacValue;
*    - prescaler.
*
* Parameters:
*  mbx:  Pointer to Mailbox structure in RAM.
*
* Return:
*  None. Modifies the contents of mbx->outbox.
*
* Global Variables:
*  None
*
*******************************************************************************/
void CapSense_PostMessage(volatile CapSense_MAILBOX *mbx)
{
    uint8 i;

    #if ( CapSense_TUNING_METHOD == CapSense__TUNING_AUTO )
        uint8 tmpResolutionIndex;
        uint16 tmpResolutionValue;
    #endif /* ( CapSense_TUNING_METHOD == CapSense__TUNING_AUTO ) */

    /* Check busy flag */
    while (mbx->type != CapSense_TYPE_ID){}

    /* Copy scan parameters */
    #if((CapSense_TUNING_METHOD == CapSense__TUNING_AUTO) || (0u != CapSense_AUTOCALIBRATION_ENABLE))
        /* Copy tuned idac values */
        for(i = 0u; i < CapSense_TOTAL_SENSOR_COUNT; i++)
        {
            mbx->outbox.modulationIDAC[i] = CapSense_modulationIDAC[i];
            #if (CapSense_IDAC_CNT == 2u)
                mbx->outbox.compensationIDAC[i] = CapSense_compensationIDAC[i];
            #endif /* (CapSense_IDAC_CNT == 2u) */
        }
    #endif /* ((CapSense_TUNING_METHOD == CapSense__TUNING_AUTO) || (0u != CapSense_AUTOCALIBRATION_ENABLE)) */

    #if ( CapSense_TUNING_METHOD == CapSense__TUNING_AUTO )
        for(i = 0u; i < CapSense_TOTAL_SCANSLOT_COUNT; i++)
        {
            mbx->outbox.analogSwitchDivider[i] = CapSense_senseClkDividerVal[i];
            mbx->outbox.modulatorDivider[i] = CapSense_sampleClkDividerVal[i];
        }

        /* Widget resolution, take to account TP and MB */
        for(i = 0u; i < CapSense_WIDGET_RESOLUTION_PARAMETERS_COUNT; i++)
        {
            tmpResolutionValue = (uint16)(CapSense_widgetResolution[i] >> CapSense_MSB_RESOLUTION_OFFSET);
            tmpResolutionIndex = 0u;

            while(0u != tmpResolutionValue)
            {
                tmpResolutionIndex++;
                tmpResolutionValue >>= 1u;
            }

            mbx->outbox.scanResolution[i] = tmpResolutionIndex;
        }

        #if(0u != CapSense_CSHL_API_GENERATE)
            /* Parameters are changed in run time */
            for(i = 0u; i < CapSense_WIDGET_CSHL_PARAMETERS_COUNT; i++)
            {
                mbx->outbox.fingerThreshold[i] = CapSense_fingerThreshold[i];
                mbx->outbox.noiseThreshold[i]  = CapSense_noiseThreshold[i];
                mbx->outbox.hysteresis[i]      = CapSense_hysteresis[i];
            }
        #endif /* (0u != CapSense_CSHL_API_GENERATE) */

    #endif /* (CapSense_TUNING_METHOD == CapSense__TUNING_AUTO) */


    /* Copy all data - Raw, Base, Signal, OnMask */
    for(i = 0u; i < CapSense_TOTAL_SENSOR_COUNT; i++)
    {
        mbx->outbox.rawData[i]  = CapSense_sensorRaw[i];
        #if(0u != CapSense_CSHL_API_GENERATE)
            mbx->outbox.baseLine[i] = CapSense_sensorBaseline[i];
            #if (CapSense_SIGNAL_SIZE == CapSense_SIGNAL_SIZE_UINT8)
                mbx->outbox.sensorSignal[i]   = (uint8)CapSense_sensorSignal[i];
            #else
                mbx->outbox.sensorSignal[i]   = (uint16)CapSense_sensorSignal[i];
            #endif  /* (CapSense_SIGNAL_SIZE == CapSense_SIGNAL_SIZE_UINT8) */
        #endif /* (0u != CapSense_CSHL_API_GENERATE) */
    }

    /* Set busy flag */
    mbx->type = CapSense_BUSY_FLAG;
}


#if ((CapSense_TUNING_METHOD != CapSense__TUNING_NONE) && (0u != CapSense_TOTAL_TRACKPAD_GESTURES_COUNT) ||\
     (CapSense_TUNING_METHOD == CapSense__TUNING_MANUAL))

    /*******************************************************************************
    * Function Name: CapSense_ReadMessage
    ********************************************************************************
    *
    * Summary:
    *  If CapSense_HAVE_MSG is found in the mailbox, the function initializes
    *   the component with parameters which are found in the inbox.
    *   Signal is DONE by overwriting the value in the mailbox size field.
    *  Only available in the manual tuning mode.
    *
    * Parameters:
    *  mbx:  Pointer to Mailbox structure in RAM.
    *
    * Return:
    *  None. Modifies the contents of mbx.
    *
    * Global Variables:
    *  None
    *
    *******************************************************************************/
    void CapSense_ReadMessage(volatile CapSense_MAILBOX *mbx)
    {
        volatile CapSense_INBOX *tmpInbox;

        /* Do we have a message waiting? */
        if ((mbx->size) == CapSense_HAVE_MSG)
        {
            tmpInbox = &(mbx->inbox);

            #if(CapSense_TUNING_METHOD == CapSense__TUNING_MANUAL)
                if(tmpInbox->sensorIndex != CapSense_MAX_UINT_8)
                {
                    CapSense_InitCsdParams(tmpInbox);
                }
            #endif /* (CapSense_TUNING_METHOD == CapSense__TUNING_MANUAL) */

            #if(0u != CapSense_TOTAL_TRACKPAD_GESTURES_COUNT)
                if(tmpInbox->sensorIndex == CapSense_MAX_UINT_8)
                {
                    CapSense_InitGesturesParams(tmpInbox);
                }
            #endif /* (0u != CapSense_TOTAL_TRACKPAD_GESTURES_COUNT) */

            /* Notify host/tuner that we have consumed message */
            mbx->size = sizeof(CapSense_MAILBOX);

            /* Default settings were changed */
            mbx->outbox.noReadMessage = 0u;

            /* `#START CapSense_MBX_READ_MSG` */

            /* `#END` */
            
            #ifdef CapSense_READ_MESSAGE_MBX_READ_MSG_CALLBACK
                CapSense_ReadMessage_MBX_READ_MSG_Callback();
            #endif /* CapSense_READ_MESSAGE_MBX_READ_MSG_CALLBACK */
        }
    }
#endif  /* ((CapSense_TUNING_METHOD != CapSense__TUNING_NONE) && (0u != CapSense_TOTAL_TRACKPAD_GESTURES_COUNT) ||\
            (CapSense_TUNING_METHOD == CapSense__TUNING_MANUAL)) */


/* [] END OF FILE */
