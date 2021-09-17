/**
 * @file exercise_1-19.c
 * @brief Exercise 1-19 from section 1.9.
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
int reverse(char s[]);
int len(char s[]);

/**
 * @brief Exercise 1-19 from section 1.9.
 * Exercise 1-19. Write a function reverse(s) that reverses the character string s. 
 * Use it to write a program that reverses its input a line at a time.
 * 
 * @return implicit int - state of program value
 */

main()
{
    char line[MAXLINE];
    int len;
    int nline = 0;

    while ((len = getline_book(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s", line);
    }
    if (len == -1)
        printf("\n--- ERROR: input line %d exceeded the limit(%d)\n", nline + 1, MAXLINE);
}

/**
 * @brief Reverses the character string s
 * 
 * @param s String to reverse
 * @return int 1 if ok. 0 if error.
 */
int reverse(char s[])
{
    int l = len(s) - 1;
    if (s[l] == '\n')
        --l;

    int i = 0;
    if (l > 0) { // no only '\n'
        for (int i = 0; i <= l / 2; i++) {
            char swap;
            swap = s[i];
            s[i] = s[l - i];
            s[l - i] = swap;
        }
    }

    return i;
}

/**
 * @brief Reverses the character string s
 * 
 * @param s String to reverse
 * @return int 1 if ok. 0 if error.
 */
int len(char s[])
{
    // calculate len
    int len = 0;
    for (len = 0; s[len] != '\0' && len < MAXLINE; len++)
        ;
    return len;
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
