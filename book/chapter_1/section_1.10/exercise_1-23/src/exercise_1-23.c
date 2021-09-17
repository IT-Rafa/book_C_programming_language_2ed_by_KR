/**
 * @file exercise_1-23.c
 * @brief Exercise 1-23 from section 1.10.
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
 * @brief Exercise 1-23 from section 1.10.
 * Exercise 1-23. Write a program to remove all comments from a C program.
 * Don't forget to handle quoted strings and character constants properly. 
 * C comments not nest.
 * 
 * @return implicit int - state of program value
 */
main()
{
    int c; /* actual char */

    // check and print if must
    while ((c = getchar()) != EOF) {
        if (controlComments(c)) {
            putchar(c);
        }
    }
    // print char pending check
    printPendingAfterEOF();
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
