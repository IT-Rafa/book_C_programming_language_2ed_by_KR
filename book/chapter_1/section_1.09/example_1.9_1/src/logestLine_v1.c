/**
 * @file logestLine_v1.c
 * @brief Example 1 from section 1.9 - page 29
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-09-10
 */

/* LIBRARIES */
/* Needed to use printf */
#include <stdio.h>

/* SYMBOLIC CONSTANTS */
#define MAXLINE 1000 /* maximum input line size */

/* FUNCTIONS DECLARATIONS */
int getline_book(char line[], int maxline);
void copy(char to[], char from[]);

/* FUNCTIONS DEFINITIONS */
/**
 * @brief print longest input line.
 * @return implicit int - state of program value
 */
main()
{
    int len;               /* current line lenghth */
    int max;               /*  maximum length seen to far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = getline_book(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }

    if (max > 0) /* there was a line */
        printf("%s", longest);

    return 0;
}

/**
 * @brief read a line into s, return length.
 * @warning the original function name, getline, was changed becouse the 
 * standard library have a function with this name
 * @param s Array to save string
 * @param lim Maximum size of string
 * @return int length of saved string
 */
int getline_book(char s[], int lim)
{
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

/**
 * @brief copy 'from' into 'to'; assume 'to' is big enough.
 * 
 * @param to array to save string
 * @param from array to read string
 */
void copy(char to[], char from[])
{
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
