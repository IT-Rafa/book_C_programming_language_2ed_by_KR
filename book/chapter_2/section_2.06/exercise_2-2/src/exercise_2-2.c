/**
 * @file exercise_2-2.c
 * @brief Exercise 2-2 from section 2.6
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-9-12
 * 
 */

/* LIBRARIES */
#include <stdio.h>

/* SYMBOLIC CONSTANTS */
#define LIMIT 30

/* EXTERNAL VARIABLES */
/* FUNCTIONS DECLARATIONS */
int getline_book(char s[], int lim);
/* FUNCTIONS DEFINITIONS */

/**
 * @brief Exercise 2-2 from section 2.6.
 * Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||.
 * @note above function
 * @code for (i=0; i < lim-1 && (c=getchar)) != '\n' && c != EOF;++i)
    s[i] = c;
 * @return int State of program value
 */
int main(void)
{
    int len;
    char s[LIMIT];
    len = getline_book_v2(s, LIMIT);
    printf("%s", s);
    printf("\nlen = %d", len);
    return 0;
}

int getline_book_v2(char s[], int lim)
{
    int c, i;
    int end = 0;
    for (i = 0; !end; i++) {
        if (i < lim - 1) {
            if ((c = getchar()) != EOF) {
                s[i] = c;
                if (c == '\n') {
                    end = 1;
                }
            }
            else {
                end = 1;
                --i;
            }
        }
        else {
            end = 1;
            --i;
        }
    }

    s[i] = '\0';

    if (i >= lim - 1) {
        return -i;
    }
    else
        return i;
}
