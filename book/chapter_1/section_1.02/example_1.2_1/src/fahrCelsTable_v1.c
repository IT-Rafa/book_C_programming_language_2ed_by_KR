/**
 * @file fahrCelsTable_v1.c
 * @brief Example 1 from section 1.2 - page 9.
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-07
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

// FUNCTIONS
/**
 * @brief Print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300. Version 1.
 * @return implicit int - state of program value
 */
main()
{
	int fahr, celsius;
	int lower, upper, step;

	lower = 0;	 /* lower limit of temerature table */
	upper = 300; /* upper limit */
	step = 20;	 /* step size */

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = 5 * (fahr - 32) / 9;
		printf("%d\t%d\n", fahr, celsius);
		fahr = fahr + step;
	}
}