/**
 * @file exercise_1-24.c
 * @brief Exercise 1-24 from section 1.10.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-9-06
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

/* SYMBOLIC CONSTANTS */
#define TABSIZE 4

#define OPENING 0
#define OPEN 1
#define CLOSING 2
#define CLOSED 3

/* FUNCTIONS DECLARATIONS */
int commentControl(int c);
int quotesControl(int c);
int codeControl(int c);
void controlPosition(int c);
void showFinalErrors(void);

/* EXTERNAL VARIABLES */
int quote = CLOSED;
int actquote = '\0';

int escseq = CLOSED;
int comment = CLOSED;
char errorHeader[] = "-------------"
                     " ERRORS FOUND "
                     "-------------\n";
int parenth = 0;
int bracket = 0;
int brace = 0;
int line = 1;
int column = 0;

/*  FUNCTIONS DEFINITIONS */

/**
 * @brief Exercise 1-24 from section 1.10.
 * Exercise 1-24. Write a program to check a C program for rudimentary syntax 
 * errors like unbalanced parentheses, brackets and braces. 
 * Don't forget about quotes, both single and double, escape sequences, and comments. 
 * (This program is hard if you do it full generally.)
 * 
 * @return implicit int - state of program value
 @todo in 1º line, the column is bad numbered
 */
main()
{
    int c; /* actual char */

    while ((c = getchar()) != EOF) {
        controlPosition(c);

        if (comment != CLOSED) {
            // inside comment
            if (!commentControl(c)) {
                return 0;
            }
        }
        else {
            // C code
            if (quote == OPEN) {
                // inside quotes
                if (!quotesControl(c)) {
                    return 0;
                }
            }
            else {
                // outside quotes - normal C
                if (!codeControl(c)) {
                    return 0;
                }
            }
        }
    }
    showFinalErrors();
    return 0;
}
void showFinalErrors(void)
{

    if (parenth || bracket || brace) {
        printf("%s", errorHeader);
    }
    if (parenth > 0) {
        printf("Error: There are %d "
               "parenthesis open but no closed\n",
               parenth);
    }
    else if (parenth < 0) {
        printf("Error: There are %d "
               "parenthesis closed but no opened\n",
               -parenth);
    }

    if (bracket > 0) {
        printf("Error: There are %d "
               "brackets open but no closed\n",
               bracket);
    }
    else if (bracket < 0) {
        printf("Error: There are %d "
               "brackets closed but no opened\n",
               -bracket);
    }

    if (brace > 0) {
        printf("Error: There are %d "
               "braces open but no closed\n",
               brace);
    }
    else if (brace < 0) {
        printf("Error: There are %d "
               "braces closed but no opened\n",
               -brace);
    }
}
void controlPosition(int c)
{
    if (c == '\n' && quote == CLOSED) {
        ++line;
        column = 0;
    }
    else if (c == '\t') {
        column = column + TABSIZE;
    }
    else {
        ++column;
    }
}
int codeControl(int c)
{
    if (c == '/') {
        comment = OPENING;
    }
    else if (c == '\'' || c == '\"') {
        quote = OPEN;
        actquote = c;
    }

    else if (c == '(') {
        ++parenth;
    }
    else if (c == ')') {
        --parenth;
        if (parenth < 0) {
            printf("%s", errorHeader);
            printf("Error: parentheses closed before open in line %d; column: %d\n",
                   line, column);
            return 0;
        }
    }
    else if (c == '[') {
        ++bracket;
    }
    else if (c == ']') {
        --bracket;
        if (bracket < 0) {
            printf("%s", errorHeader);
            printf("Error: bracket closed before open in line %d; column: %d\n",
                   line, column);
            return 0;
        }
    }
    else if (c == '{') {
        ++brace;
    }
    else if (c == '}') {
        --brace;
        if (brace < 0) {
            printf("%s", errorHeader);
            printf("Error: brace closed before open in line %d; column: %d\n",
                   line, column);
            return 0;
        }
    }
    else if (c == '\\') {
        // UNKNOWN TOKEN
        printf("%s", errorHeader);
        printf("Error: unrecognized token (\'%c\') in line %d; column: %d\n",
               c, line, column);
        return 0;
    }
    return 1;
}

int quotesControl(int c)
{
    if (escseq == CLOSED) {
        if (c == actquote) {
            quote = CLOSED;
            actquote = '\0';
        }
        else if (c == '\\') {
            escseq = OPEN;
        }
        else if (c == '\n') {
            printf("%s", errorHeader);
            printf("Error: quote (%c) no closed before end-of-line in line %d; column: %d\n",
                   actquote, line, column);
            return 0;
        }
        else {
            escseq == CLOSED;
        }
    }
    else {
        escseq = CLOSED;
    }
    return 1;
}

int commentControl(int c)
{
    if (comment == OPENING) {
        if (c == '*') {
            comment = OPEN;
        }
        else {
            comment == CLOSED;
        }
    }
    else if (comment == OPEN) {
        if (c == '*') {
            comment = CLOSING;
        }
    }
    else if (comment == CLOSING) {
        if (c == '/') {
            comment = CLOSED;
        }
        else {
            comment = OPEN;
        }
    }
    return 1;
}
