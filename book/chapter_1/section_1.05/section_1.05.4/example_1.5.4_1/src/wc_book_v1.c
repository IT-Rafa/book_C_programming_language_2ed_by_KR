/**
 * @file wc_book_v1.c
 * @brief Example 1 from section 1.5.4 - page 20.
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-10
 */

// LIBRARIES
// Needed to use getchar and putchar functions
#include <stdio.h>

// SYMBOLIC CONSTANTS
#define IN 1  /**< inside a word */
#define OUT 0 /**< outside a word */

// FUNCTIONS
/**
 * @brief Example 1 from section 1.5.4 - page 20.
 * Counts lines, words, and characters in input.
 * Similar to Unix wc.
 * .
 * @return implicit int - state of program value
 */
main()
{
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
		{
			++nl;
		}
		if (c == ' ' || c == '\n' || c == '\t')
		{
			state = OUT;
		}
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}
