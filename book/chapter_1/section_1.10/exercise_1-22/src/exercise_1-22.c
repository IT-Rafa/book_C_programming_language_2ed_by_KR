/**
 * @file exercise_1-22.c
 * @brief Exercise 1-22 from section 1.10.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-9-06
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

/* SYMBOLIC CONSTANTS */
#define MAXLINE 1024 /**< maximum input line size */
#define FOLDLIMIT 60 /**< maximum input line size */

/* FUNCTIONS DECLARATIONS */
int getline_book(char line[], int maxline);
int printfold(char originalLine[], int len, int limit);

/*  FUNCTIONS DEFINITIONS */

/**
 * @brief Exercise 1-22 from section 1.10.
 * Exercise 1-22. Write a program to "fold" long input lines into two or more 
 * shorter lines after the last non-blank character that occurs before the 
 * n-th column of input. 
 * Make sure your program does something intelligent with very long lines, and 
 * if there are no blanks or tabs before the specific column.
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
        if (len > FOLDLIMIT) {
            printfold(line, len, FOLDLIMIT);
        }
        else
            printf("%s", line);
    }
    if (len == -1)
        printf("\n--- ERROR: input line %d exceeded the limit(%d)\n", nline + 1, MAXLINE);
}

int printfold(char source[], int len, int limit)
{
    // Detectar espacio anterior a posición máxima  = end1
    int init = 0;
    int end = len;

    // Repetir mientras (len -init) > limit
    while ((len - init) > limit) {
        // Calcular nuevo fin (si espacio previo)
        for (end = limit + init; end > 0 && source[end] != ' ' && source[end] != '\t'; --end)
            ;
        // Calcular nuevo fin (si no espacio previo)
        if (end == 0)
            end = init + FOLDLIMIT-2;
        // imprimir linea recortada
        for (; init <= end; init++)
            putchar(source[init]);
        putchar('\n');
    }
    for (; init < len; init++)
        putchar(source[init]);
    return 0;
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
