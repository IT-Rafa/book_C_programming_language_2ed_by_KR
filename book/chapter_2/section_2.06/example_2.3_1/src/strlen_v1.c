/**
 * @file strlen_v1.c
 * @brief Example 1 from section 2.3 - page 39
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-09-10
 */

/* LIBRARIES */
/* Needed to use printf */
#include <stdio.h>

/* SYMBOLIC CONSTANTS */

/* EXTERNAL VARIABLES */

/* FUNCTIONS DECLARATIONS */
int strlen(char s[]);

/* FUNCTIONS DEFINITIONS */
/**
 * @brief test strlen function.
 * @return implicit int - state of program value
 */
int main(void)
{
    char s1[100] = "Hola, mundo";
    char s2[100] = "x";
    char s3[100] = "x\tx";

    printf("\"%s\"\n\tContains %d chars\n", s1, strlen(s1));
    printf("\"%s\"\n\tContains %d chars\n", s2, strlen(s2));
    printf("\"%s\"\n\tContains %d chars\n", s3, strlen(s3));

    return 0;
}

int strlen(char s[])
{
    int i;
    i = 0;
    while (s[i] != '\0')
        ++i;
    return i;
}
