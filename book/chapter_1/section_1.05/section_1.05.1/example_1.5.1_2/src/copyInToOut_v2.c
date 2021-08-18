/**
 * @file copyInToOut_v2.c
 * @brief Example 2 from section 1.5.1 - page 17.
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-10
 */

// LIBRARIES
// Needed to use getchar and putchar functions
#include <stdio.h>

// FUNCTIONS
/**
 * @brief Copy input to output; 2nd version.
 * @return implicit int - state of program value
 */
main()
{
	int c;

	while ((c = getchar()) !=EOF){
		putchar(c);
	}
}
