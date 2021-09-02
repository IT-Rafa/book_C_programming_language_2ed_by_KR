/**
 * @file exercise_1-12.c
 * @brief Exercise 1-12 from section 1.5.4.
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
 * @brief Exercise 1-12 from section 1.5.4.
 * Exercise 1-10. Write a program that prints its input one word per line.
 * 
 */
main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
            putchar('\n');
        else
            putchar(c);
    }
}
