/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>

/* I will arbitrarily chose a clock of 100kHz */
/* Therefore, the notes/frequencies/dividers I need are: */
/* C4 - 261.6 - 382 */
/* D4 - 293.7 - 340 */
/* E4 - 329.6 - 303 */
/* F4 - 349.2 - 286 */
/* G4 - 392.0 - 255 */
/* A4 - 440.0 - 227 */
#define C (382)
#define D (340)
#define E (303)
#define F (286)
#define G (255)
#define A (227)

/* Note durations */
#define QUARTER (200)
#define HALF    (QUARTER*2)

/* This function will play the specified note for the specified duration (ms) and a specified number of times */
/* A fixed pause of 1/4th the note duration is added after the note for separation from the next node */
void playNote(uint16 note, uint16 duration, uint8 repeat)
{
    uint8 loop;
    for(loop = 0; loop < repeat; loop++)
    {
        PWM_WritePeriod(note);      /* Update PWM based on note */
        PWM_WriteCompare(note>>1);  /* Set duty cycle to 50% */
        PWM_WriteCounter(0);        /* Need to make sure count is less than period value to avoid overflow */
        PWM_Start();
        CyDelay(duration);          /* Play note for specified duration */
        PWM_Stop();
        CyDelay(note>>2);
    }
}

/* This function plays a line from the song. Note that line 1 and 3 are the same */
void playLine(uint8 line)
{
    if(line == 2)
    {
        playNote(G, QUARTER, 2);
        playNote(F, QUARTER, 2);
        playNote(E, QUARTER, 2);
        playNote(D, HALF, 1);
        playNote(G, QUARTER, 2);
        playNote(F, QUARTER, 2);
        playNote(E, QUARTER, 2);
        playNote(D, HALF, 1);       
    }
    else /* Lines 1 and 3 are the same */
    {
        playNote(C, QUARTER, 2);
        playNote(G, QUARTER, 2);
        playNote(A, QUARTER, 2);
        playNote(G, HALF, 1);
        playNote(F, QUARTER, 2);
        playNote(E, QUARTER, 2);
        playNote(D, QUARTER, 2);
        playNote(C, HALF, 1);               
    }
    
}

int main()
{    
    PWM_Start(); /* Need to do this so that the first start doesn't re-initialize the count/compare values */
    PWM_Stop();
    
    /* CyGlobalIntEnable; */ /* Uncomment this line to enable global interrupts. */
    for(;;)
    {
        playLine(1);
        playLine(2);
        playLine(3);
        CyDelay(1000); /* Wait before playing the song again */
    }
}

/* [] END OF FILE */
