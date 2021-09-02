/**
 * @file exercise_1-8.c
 * @brief Exercise 1-8 from section 1.5.3.
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
 * @brief Exercise 1-8 from section 1.5.3
 * Exercise 1-8. Write a program to count blanks, tabs, and newlines.
 * @return implicit int - state of program value
 */
main()
{
    int c;
    int bc, tc, nlc;
    bc = tc = nlc = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
            ++bc;
        if (c == '\t')
            ++tc;
        if (c == '\n')
            ++nlc;
    }
    printf("blanks: %d; tabs: %d; newlines: %d\n", bc, tc, nlc);
    return 0;
}
