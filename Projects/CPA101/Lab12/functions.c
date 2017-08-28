/* ========================================
 *
 * Copyright Cypress Semiconductor, 2014
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF Cypress Semiconductor.
 *
 * ========================================
*/

#include <project.h>

/* This function fills a provided array with the string "PSoC Rocks!" */
void fillArray(char * string)
{
	const char stringConst[] = "PSoC Rocks!";
	strcpy(string, stringConst);
}

/* This function returns the a running count of the fibonacci sequence */
uint32 returnVal(void)
{
	static uint8 count = 0;
	
	static uint32 nm1 = 1;
	static uint32 nm2 = 0;
	
	uint32 newVal;

	if (count < 2) /* used to return 0, 1 as the first two results */
	{
		count++;
		return (count-1);
	}
	else
	{
		newVal = nm1 + nm2;
		nm2 = nm1;
		nm1 = newVal;
	
		return (newVal);
	}
}


/* [] END OF FILE */
