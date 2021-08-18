/**
 * @file fahrCelsTable_v3.c
 * @brief Example 1 from section 1.3 - page 13.
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 3
 * @date 2021-08-07
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

// FUNCTIONS
/**
 * @brief Print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300. for version.
 * @return implicit int - state of program value
 */
main()
{
	int fahr;

	for (fahr = 0; fahr <= 300; fahr = fahr + 20){
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
}
