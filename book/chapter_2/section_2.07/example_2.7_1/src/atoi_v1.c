/**
 * @file atoi_v1.c
 * @brief Example 1 from section 2.7 - page 43
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
int atoi(char s[]);

/* FUNCTIONS DEFINITIONS */
/**
 * @brief test atoi function.
 * @return int State of program value
 */
int main(void)
{
    int n;
    char st[100] = "123456";
    n = atoi(st);
    printf("string(\"%s\") is the integer(%d)\n", st, n);

    return 0;
}
/**
 * @brief Convert s to integer
 * 
 * @param s String to convert
 * @return int The integer corresponding to s
 */
int atoi(char s[])
{
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');

    return n;
}
