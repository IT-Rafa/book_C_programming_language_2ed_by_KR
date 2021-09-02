/**
 * @file countLines_v1.c
 * @brief Example 1 from section 1.5.3 - page 19.
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-10
 */

// LIBRARIES
// Needed to use getchar and putchar functions
#include <stdio.h>

// FUNCTIONS
/**
 * @brief Count lines in input.
 * @return implicit int - state of program value
 */
main()
{
	int c, nl;

	nl = 0;
	while ((c = getchar()) != EOF)
		if (c == '\n')
			++nl;

	printf("%d\n", nl);
}
