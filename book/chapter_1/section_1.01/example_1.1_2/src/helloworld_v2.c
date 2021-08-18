/**
 * @file helloworld_v2.c
 * @brief Example 2 from section 1.1 - page 8.
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 0.1
 * @date 2021-07-30
 */
// LIBRARIES
// Needed to use printf
#include <stdio.h>

// FUNCTIONS
/**
 * @brief Send "hello, world\n" to standard output. Version 2 - Divide printf in several.
 * @return implicit int - state of program value
 */
main()
{
	printf("hello, ");
	printf("world");
	printf("\n");
}