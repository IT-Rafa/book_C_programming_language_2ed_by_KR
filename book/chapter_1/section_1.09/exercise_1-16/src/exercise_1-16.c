/**
 * @file exercise_1-16.c
 * @brief Exercise 1-16 from section 1.9.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-9-02
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

/* SYMBOLIC CONSTANTS */
#define MAXLINE 10 /* maximum input line size */

/* FUNCTIONS DECLARATIONS */
int getline_book(char line[], int maxline);
void copy(char to[], char from[]);

// FUNCTIONS DEFINITIONS
/**
 * @brief Exercise 1-16 from section 1.9.
 * Exercise 1-16 - Revise the main routine of the longest-line program so 
 * it will correctly print the length of arbitrarily long input lines, and 
 * as much as possible of the text.
 * 
 * @note getline_book and copy functions are textual copies of example 1 from section 1.9
 * @note main is modified
 * @note MAXLINE is changed to 10 to make test input readly
 * 
 * @warning if last line is not ending with newline but it have same length than MAXLINE -1, is considered too much long
 * 
 * @return implicit int - state of program value
 */
main()
{
    int len;               /* current line lenghth */
    int max;               /*  maximum length seen to far */
    char line[MAXLINE];    /* current input line */
    char longest[MAXLINE]; /* longest line saved here */
    int nline = 0;
    max = 0;
    while ((len = getline_book(line, MAXLINE)) > 0) {
        ++nline;
        if (len == MAXLINE-1 && line[len - 1] != '\n') {
            printf("line %d too long\n", nline);
            return -1;
        }
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0)  /* there was a line */
        printf("%s", longest);
    
    return 0;
}

/**
 * @brief read a line into s, return length.
 * 
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
