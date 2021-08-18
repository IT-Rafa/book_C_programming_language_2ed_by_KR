/**
 * @file fahrCelsTable_v4.c
 * @brief Example 1 from section 1.4 - page 15.
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 3
 * @date 2021-08-07
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

// SYMBOLIC CONSTANT
#define LOWER 0	  /**< lower limit of table */
#define UPPER 300 /**< upper limit */
#define STEP 20	  /**< step size */

// FUNCTIONS
/**
 * @brief Print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300. Symbolic constants version.
 * @return implicit int - state of program value
 */
main()
{
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
	{
		printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32));
	}
}
