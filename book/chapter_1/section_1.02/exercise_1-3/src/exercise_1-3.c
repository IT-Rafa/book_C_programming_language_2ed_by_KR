/**
 * @file exercise_1-3.c
 * @brief Exercise 1-3 from section 1.2.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-07-30
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

// FUNCTIONS
/**
 * @brief  Print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 with a header.
 * @return implicit int - state of program value
 */
main()
{
	float cels, fahr;
	int lower, upper, step;

	lower = 0;
	upper = 300;
	step = 20;

	printf("  ______________________\n");
	printf(" / Fahrenheit |  Celsius \\\n");
	printf(" |------------|----------|\n");
	fahr = lower;
	while (fahr <= upper)
	{
		cels = (5.0 / 9.0) * (fahr - 32);
		printf(" |%11.2f | %8.2f |\n", fahr, cels);
		fahr = fahr + step;
	}
	printf(" \\____________|__________/\n");
}
