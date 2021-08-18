/**
 * @file exercise_1-5.c
 * @brief Exercise 1-5 from section 1.3.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-02
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

// FUNCTIONS
/**
 * @brief  Print Fahrenheit-Celsius table for fahr = 300, 280, ..., 0 with a header.
 * @return implicit int - state of program value
 */
main()
{
	float fahr;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("  ______________________\n");
	printf(" / Fahrenheit |  Celsius \\\n");
	printf(" |------------|----------|\n");
	for (fahr = upper; fahr >= lower; fahr = fahr - step)
	{
		printf(" |%11.2f | %8.2f |\n", fahr, (5.0 / 9.0) * (fahr - 32));
	}
	printf(" \\____________|__________/\n");
}
