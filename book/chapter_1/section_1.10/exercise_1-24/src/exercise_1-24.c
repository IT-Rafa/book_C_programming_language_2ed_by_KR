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
#define FALSE 0   /* outside comment */
#define OPENING 1 /* read '/', comment up on next char */
#define CLOSING 2 /* read '/', comment up on next char */
#define TRUE 3    /* inside comment */

/* FUNCTIONS DECLARATIONS */
char controlComments(c);
void controlQuotes(c);
void controlEscapeSequences(c);
void printPendingAfterEOF(void);

/* EXTERNAL VARIABLES */
int commState = FALSE;
int quoteState = FALSE;
int escSeqState = FALSE;
int quoteType = '\0';

/*  FUNCTIONS DEFINITIONS */

/**
 * @brief Exercise 1-24 from section 1.10.
 * Exercise 1-24. Write a program to check a C program for rudimentary syntax 
 * errors like unbalanced parentheses, brackets and braces. 
 * Don't forget about quotes, both single and double, escape sequences, and comments. 
 * (This program is hard if you do it full generally.)
 * 
 * @return implicit int - state of program value
 */
main()
{
    int c; /* actual char */

    int parent = 0; /* () */
    int brace = 0;  /* {} */
    int square = 0; /* [] */
    int angled = 0; /* <> */

    // check only in C text
    while ((c = getchar()) != EOF) {
        if (controlComments(c) &&
            quoteState == FALSE && escSeqState == FALSE) {

            if (c == '(')
                ++parent;
            else if (c == ')')
                --parent;
            else if (c == '{')
                ++brace;
            else if (c == '}')
                --brace;
            else if (c == '[')
                ++square;
            else if (c == ']')
                --square;
            else if (c == '<')
                ++angled;
            else if (c == '>')
                --angled;
        }
    }

    if (commState == TRUE || commState == CLOSING) {
        printf("comment no closed\n");
    }
    else if (commState == OPENING) {
        printf("symbol '/' no valid\n");
    }

    if (quoteState == TRUE) {
        printf("quote %c no closed\n", quoteType);
    }

    if (escSeqState == TRUE) {
        printf("quote %c no closed\n", quoteType);
    }

    if (parent > 0) {
        printf("Parentheses error: %d pending to close\n", parent);
    }
    else if (parent < 0) {
        printf("Parentheses error: %d closed but no open\n", -parent);
    }

    if (brace > 0) {
        printf("Error brace: %d pending to close\n", brace);
    }
    else if (brace < 0) {
        printf("Error brace: %d closed but no open\n", -brace);
    }

    if (square > 0) {
        printf("Error square: %d pending to close\n", square);
    }
    else if (square < 0) {
        printf("Error square: %d closed but no open\n", -square);
    }

    if (angled > 0) {
        printf("Error angled: %d pending to close\n", angled);
    }
    else if (square < 0) {
        printf("Error angled: %d closed but no open\n", -angled);
    }
    return 0;
}

/**
 * @brief Print pending char after get EOF.
 * Example: when input = '/' + EOF.
 * when read '/' it needs wait for next char to know if print it.
 * next char is EOF so read is over, so '/' will not be printed.
 * This function fix that.
 * 
 */
void printPendingAfterEOF(void)
{
    if (commState == OPENING) {
        putchar('/');
    }
    else if (commState == CLOSING) {
        putchar('*');
    }
}

/**
 * @brief Check if the actual char is inside a comment or not
 * 
 * @return char Return '\0' if char is inside a comment. else return c value
 */
char controlComments(c)
{
    /* check first char to close comment */
    if (commState == TRUE) {
        if (c == '*') {
            commState = CLOSING;
        }
    }
    /* check second char to close comment */
    else if (commState == CLOSING) {
        if (c == '/') {
            commState = FALSE;
        }
    }
    /* check second char to init comment */
    else if (commState == OPENING) {
        if (c == '*') {
            commState = TRUE;
        }
    }
    /* check fist char to init comment */
    else {
        if (c == '/' && quoteState == FALSE && escSeqState == FALSE) {
            commState = OPENING;
        }
        else {
            // control exceptions (quotes, sequences, etc)
            controlQuotes(c);
            controlEscapeSequences(c);
            return c;
        }
    }
    return '\0';
}

/**
 * @brief Control if a escape sequence is init
 * 
 */
void controlEscapeSequences(c)
{
    if (c == '\\')
        escSeqState = TRUE;
    else
        escSeqState = FALSE;
}

/**
 * @brief Control if a quoute, simple or double, is init
 * 
 */
void controlQuotes(c)
{
    if (quoteState == TRUE) {
        if (c == quoteType) {
            quoteType = '\0';
            quoteState = FALSE;
        }
    }
    else {
        if (c == '"' || c == '\'') {
            if (escSeqState) {
                escSeqState = FALSE;
            }
            else {
                quoteType = c;
                quoteState = TRUE;
            }
        }
    }
}
