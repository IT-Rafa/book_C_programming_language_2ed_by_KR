/**
 * @file countChars_v1.c
 * @brief Example 1 from section 1.5.2 - page 18.
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-10
 */

// LIBRARIES
// Needed to use getchar and putchar functions
#include <stdio.h>

// FUNCTIONS
/**
 * @brief Count characters in input; 1st version.
 * @return implicit int - state of program value
 */
main()
{
	long nc;
	nc = 0;
	while (getchar() != EOF)
		++nc;
	printf("%ld\n", nc);
}
