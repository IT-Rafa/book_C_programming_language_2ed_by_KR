/**
 * @file logestLine_v2.c
 * @brief Example 1 from section 1.10 - page 32
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-09-10
 */

/* LIBRARIES */
/* Needed to use printf */
#include <stdio.h>

/* SYMBOLIC CONSTANTS */
#define MAXLINE 1000 /**< maximum input line size */

/* EXTERNAL VARIABLES */
int max;               /**<maximimum length seen so far */
char line[MAXLINE];    /**< current input line */
char longest[MAXLINE]; /**< longest line saved here */

/* FUNCTIONS DECLARATIONS */
int getline_book(void);
void copy(void);

/* FUNCTIONS DEFINITIONS */
/**
 * @brief print longest input line.
 * @return implicit int - state of program value
 */
main()
{
    int len;
    extern int max;
    extern char longest[MAXLINE];

    max = 0;
    while ((len = getline_book()) > 0)
        if (len > max) {
            max = len;
            copy();
        }

    if (max > 0) /* there was a line */
        printf("%s", longest);

    return 0;
}

/**
 * @brief read a line into s, return length. specialized version
 * Use external vars
 * @warning the original function name, getline, was changed becouse the 
 * standard library have a function with this name
 * @return int length of saved string
 */
int getline_book()
{
    int c, i;
    extern char line[];
    for (i = 0; i < MAXLINE - 1 &&
                (c = getchar()) != EOF && c != '\n';
         ++i)
        line[i] = c;

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/**
 * @brief copy 'from' into 'to'; assume 'to' is big enough.
 * specialized version. Use extern vars
 * 
 */
void copy()
{
    int i;
    extern char line[], longest[];
    
    i = 0;
    while ((longest[i] = line[i]) != '\0')
        ++i;
}
