/**
 * @file exercise_1-10.c
 * @brief Exercise 1-10 from section 1.5.3.
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
 * @brief Exercise 1-10 from section 1.5.3
 * Exercise 1-10. Write a program to copy its input to its output, replacing
 * each tab with \t, each backspace by \b, and each backlash by \\.
 * This make tabs and backspaces visible in a unambiguous way.
 */
main()
{
    int c;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\b')
        {
            putchar('\\');
            putchar('b');
        }        else if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }else{
            putchar(c);
        }
    }
    return 0;
}
