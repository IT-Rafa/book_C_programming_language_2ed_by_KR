/**
 * @file countChars_v2.c
 * @brief Example 2 from section 1.5.2 - page 18.
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 2
 * @date 2021-08-10
 */

// LIBRARIES
// Needed to use getchar and putchar functions
#include <stdio.h>

// FUNCTIONS
/**
 * @brief Count characters in input; 2st version.
 * @return implicit int - state of program value
 */
main()
{
	double nc;
	nc = 0;
	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("%.0f\n", nc);
}
