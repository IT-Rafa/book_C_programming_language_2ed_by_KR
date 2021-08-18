/**
 * @file exercise_1-4.c
 * @brief Exercise 1-4 from section 1.2.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-8-02
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

// FUNCTIONS
/**
 * @brief  Print Celsius-Fahrenheit table for fahr = 0, 20, ..., 300 with a header.
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
	printf(" / Celsius |  Fahrenheit \\\n");
	printf(" |---------|-------------|\n");
	cels = lower;
	while (cels <= upper)
	{
		fahr = (cels / (5.0 / 9.0)) + 32;
		printf(" |%8.2f | %11.2f |\n", cels, fahr);
		cels = cels + step;
	}
	printf(" \\_________|_____________/\n");
}
