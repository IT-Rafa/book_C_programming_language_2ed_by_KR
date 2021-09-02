/**
 * @file exercise_1-11.c
 * @brief Exercise 1-11 from section 1.5.4.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-10
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

// SYMBOLIC CONSTANTS
#define IN 1  /**< inside a word */
#define OUT 0 /**< outside a word */

// FUNCTIONS
/**
 * @brief Exercise 1-11 from section 1.5.4
 * Exercise 1-11. How would you test the word count program?
 * What kind of input are most likely to uncover bugs if there are any?.
 * 
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
