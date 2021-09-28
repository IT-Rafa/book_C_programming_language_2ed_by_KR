/**
 * @file strcat_v1.c
 * @brief Example 2 from section 2.8 - page 47
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
void strcat_v1(char s[], char t[]);

/* FUNCTIONS DEFINITIONS */
/**
 * @brief test squeeze function.
 * @return int State of program value
 */
int main(void)
{
    char st1[100] = "hello";
    char st2[] = " ";
    char st3[] = "word";

    printf("st1=\"%s\" + st2=\"%s\"\n", st1, st2);
    strcat_v1(st1, st2);
    printf("result: \"%s\"\n", st1);

    printf("\n+ st3=\"%s\"\n", st3);
    strcat_v1(st1, st3);
    printf("result: \"%s\"\n", st1);

    return 0;
}

/**
 * @brief Concatenate t to end of s;
 * s must be big enough
 * 
 * @param s String where add t
 * @param t String to add to s
 */
void strcat_v1(char s[], char t[])
{
    int i, j;

    i = j = 0;
    while (s[i] != '\0') /* find end of s */
        i++;
    while ((s[i++] = t[j++]) != '\0') /* copy */
        ;
}
