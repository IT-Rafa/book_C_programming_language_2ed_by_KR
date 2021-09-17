/**
 * @file exercise_1-21.c
 * @brief Exercise 1-21 from section 1.10.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-9-06
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

/* SYMBOLIC CONSTANTS */
#define TABSIZE 8 /* maximum input line size */

/* FUNCTIONS DECLARATIONS */

/*  FUNCTIONS DEFINITIONS */

/**
 * @brief Exercise 1-21 from section 1.10.
 * Exercise 1-21. Write a program entab that replaces strings of blanks by the 
 * minimum number of tabs and blanks to achieve the same spacing. Use the same 
 * tab stops as for detab. 
 * When either a tab or a single blank would suffice to reach a tab stop, which 
 * should be given preference?
 * 
 * @return implicit int - state of program value
 */
main()
{
    // getchar
    int c;
    int tabPos = 0;
    int spaces = 0;
    int tabs;

    while ((c = getchar()) != EOF) {
        // tabstop control
        ++tabPos;
        if (c == '\n' || c == '\t' || tabPos == TABSIZE)
            tabPos = 0;
        // spaces straight control
        if (c == ' ') {
            ++spaces;
            if (tabPos == 0 && spaces > 1) { // for tab for 1 space, quit &&
               putchar('\t');
               spaces = 0;
            }
        }
        else {
            for (; spaces > 0; --spaces)
                putchar(' ');

            // rest of char
            putchar(c);
        }
    }

    // count all spaces together
    // replace by tabs and spaces

    return 0;
}
