/**
 * @file exercise_1-9.c
 * @brief Exercise 1-9 from section 1.5.3.
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
 * @brief Exercise 1-9 from section 1.5.3
 * Exercise 1-9. Write a program to copy its input to its output, 
 * replacing each string of one or more blanks by a single blanck.
 * 
 * @return implicit int - state of program value
 */
main()
{
    int c;
    int count = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            ++count;
        }
        else
        {
            count = 0;
        }
        if (count <= 1)
        {
            putchar(c);
        }
    }
    return 0;
}
