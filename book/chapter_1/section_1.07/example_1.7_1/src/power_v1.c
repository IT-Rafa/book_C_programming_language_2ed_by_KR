/**
 * @file power_v1.c
 * @brief Example 1 from section 1.7 - page 24, 25.
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-10
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

// FUNCTIONS DECLARATIONS
int power(int m, int n);

// FUNCTIONS DEFINITIONS
/**
 * @brief Test power function. 
 * @return implicit int - state of program value
 */
main()
{
	int i;
	for (i = 0; i < 10; ++i)
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
	return 0;
}

/**
 * @brief raise base to n-th power; n >= 0
 * Calculate positive power of small integers.int power(int base, int n)
 * 
 * @param base 
 * @param n 
 * @return int 
 */
int power(int base, int n)
{
	int i, p;
	p = 1;

	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}
