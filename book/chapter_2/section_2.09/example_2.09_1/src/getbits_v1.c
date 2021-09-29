/**
 * @file getbits_v1.c
 * @brief Example 1 from section 2.9 - page 49
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-09-29
 */

/* LIBRARIES */
/* Needed to use printf */
#include <stdio.h>

/* SYMBOLIC CONSTANTS */
/* EXTERNAL VARIABLES */
/* FUNCTIONS DECLARATIONS */
unsigned getbits(unsigned x, int p, int n);

/* FUNCTIONS DEFINITIONS */
/**
 * @brief test function.
 * @return int State of program value
 */
int main(void)
{

    return 0;
}

/**
 * @brief Get n bits from position p.
 * 
 * @param x 
 * @param p 
 * @param n 
 * @return unsigned 
 */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
