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
#include "functions.h"

int main()
{
	char string[12];
	uint32 sequence;
	
	/* Fill the array named "string" with a message */
	fillArray(string);
	
    for(;;)
    {        
		/* Update the value of "sequence" every 10ms */
		sequence = returnVal();
		sequence = sequence; /* This fixes the warning 
								about an unused variable */
		CyDelay(10);
    }
}

/* [] END OF FILE */
