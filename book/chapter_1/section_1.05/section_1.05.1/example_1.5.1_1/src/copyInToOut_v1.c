/**
 * @file copyInToOut_v1.c
 * @brief Example 1 from section 1.5.1 - page 16.
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-10
 */

// LIBRARIES
// Needed to use getchar and putchar functions
#include <stdio.h>

// FUNCTIONS
/**
 * @brief Copy input to output; 1st version.
 * @return implicit int - state of program value
 */
main()
{
	int c;

	c = getchar();
	while (c !=EOF){
		putchar(c);
		c = getchar();
	}
}
