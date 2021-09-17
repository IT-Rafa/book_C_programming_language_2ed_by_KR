/**
 * @file exercise_1-20.c
 * @brief Exercise 1-20 from section 1.10.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-9-06
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

/* SYMBOLIC CONSTANTS */
#define TABSIZE 8

/* FUNCTIONS DECLARATIONS */

/* FUNCTIONS DEFINITIONS */

/**
 * @brief Exercise 1-20 from section 1.10.
 * Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number 
 * of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns. 
 * Should n be a variable or a symbolic parameter?
 * 
 * @return implicit int - state of program value
 */
main()
{
    int c;
    int posTab = 0;

    // Capture char
    while ((c = getchar()) != EOF) {
        // tabstop control
        ++posTab;
        if (c == '\n' || posTab == TABSIZE) {
            posTab = 0;
        }
        // replace tab by spaces
        if (c == '\t') {
            for (int i = 0; i <= (TABSIZE - posTab); ++i)
                putchar(' ');
            posTab = 0;
        }
        else
            putchar(c);
    }
    return 0;
}
