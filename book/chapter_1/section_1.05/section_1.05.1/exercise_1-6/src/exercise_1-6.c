/**
 * @file exercise_1-6.c
 * @brief Exercise 1-6 from section 1.5.1.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-10
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

// FUNCTIONS
/**
 * @brief Verify that the expression **getchar() != EOF** is 0 or 1.
 * @return implicit int - state of program value
 */
main()
{
    printf ("The first char of input compared with EOF is: %d\n", getchar() != EOF);
}
