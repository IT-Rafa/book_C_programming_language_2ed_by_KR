/**
 * @file fahrCelsTable_v2.c
 * @brief Example 2 from section 1.2 - page 12.
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 2
 * @date 2021-08-07
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

// FUNCTIONS
/**
 * @brief Print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300; floating-point version.
 * @return implicit int - state of program value
 */
main()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0;	 /* lower limit of temerature table */
	upper = 300; /* upper limit */
	step = 20;	 /* step size */

	fahr = lower;
	while (fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr - 32.0);
		printf("%3.0f\t%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}