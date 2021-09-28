/**
 * @file lower_v1.c
 * @brief Example 2 from section 2.7 - page 43
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-09-10
 */

/* LIBRARIES */
/* Needed to use printf */
#include <stdio.h>
#include <string.h>

/* SYMBOLIC CONSTANTS */
/* EXTERNAL VARIABLES */

/* FUNCTIONS DECLARATIONS */
int lower(int c);

/* FUNCTIONS DEFINITIONS */
/**
 * @brief test lower function.
 * @return int State of program value
 */
int main(void)
{
    int n;
    char st[100] = "abcABC123()[]\n";
    printf("Original string: %s", st);
    printf("Converted string: ");
    for (int i = 0; i < strlen(st); ++i) {
        putchar(lower(st[i]));
    }
    return 0;
}

/**
 * @brief convert c to lower case; ASCII only;
 * 
 * @param c Character to convert
 * @return int Lower case converted character
 */
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
