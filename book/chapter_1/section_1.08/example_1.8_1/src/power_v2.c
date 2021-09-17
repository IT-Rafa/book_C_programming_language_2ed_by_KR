/**
 * @file power_v2.c
 * @brief Example 1 from section 1.8 - page 29.
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-09-3
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

// FUNCTIONS DECLARATIONS
int power(int base, int n);

// FUNCTIONS DEFINITIONS
/**
 * @brief Test power function.
 * copy from example 1 from section 1.7
 * @return implicit int - state of program value
 */
main()
{
    int i;
    for (i = 0; i < 10; ++i)
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    return 0;
}
/**
 * @brief raise base to n-th power; n>=0; version 2
 * making use of call-by-value property
 * 
 * @param base 
 * @param n 
 * @return int 
 */
int power(int base, int n)
{
    int p;

    for (p = 1; n > 0; --n)
        p = p * base;
    return p;
}
