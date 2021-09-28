/**
 * @file squeeze_v1.c
 * @brief Example 1 from section 2.8 - page 47
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
void squeeze(char s[], int c);

/* FUNCTIONS DEFINITIONS */
/**
 * @brief test squeeze function.
 * @return int State of program value
 */
int main(void)
{
    char st1[] = "12345";
    char st2[] = "one, two, three";

    printf("String 1:\n");
    printf("\tOriginal: %s\n", st1);
    squeeze(st1, '1');
    printf("\tModified: %s\n", st1);

    printf("String 2:\n");
    printf("\tOriginal: %s\n", st2);
    squeeze(st2, ',');
    printf("\tModified: %s\n", st2);

    return 0;
}

/**
 * @brief delete all c from s
 * 
 * @param s String to modify
 * @param c char to delete
 */
void squeeze(char s[], int c)
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];

    s[j] = '\0';
}
