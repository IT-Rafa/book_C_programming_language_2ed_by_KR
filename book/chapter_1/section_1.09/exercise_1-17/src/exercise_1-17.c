/**
 * @file exercise_1-17.c
 * @brief Exercise 1-17 from section 1.9.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-9-02
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

/* SYMBOLIC CONSTANTS */
#define MAXLINE 100 /* maximum input line size */

// FUNCTION DECLARATIONS
int getline_book(char line[], int max);

// FUNCTIONS DEFINITIONS
/**
 * @brief Exercise 1-17 from section 1.9.
 * Exercise 1-17. Write a program to print all input lines that 
 * are longer than 80 characteres.
 * 
 * @return implicit int - state of program value
 */
main()
{
    char line[MAXLINE];
    int len;
    int nline = 0;
    while ((len = getline_book(line, MAXLINE)) > 0) {
        ++nline;
        if (len >= 80)
            printf("%s", line);
    }
    if (len == -1)
        printf("\n--- ERROR: input line %d exceeded the limit(%d)\n", nline+1, MAXLINE);
}

/**
 * @brief Save a line from input and return its length
 * 
 * @param line string to save the line
 * @param max Maximum lenght of string, including terminator string.
 * @return int length of line read; If EOF return 0; if line exceed the limit, return -1.
 */
int getline_book(char line[], int max)
{
    int c, i;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i == max - 1)
            return -1;
        else
            line[i] = c;
    }
    if (c == '\n') {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}
