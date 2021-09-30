/**
 * @file exercise_2-6.c
 * @brief Exercise 2-6 from section 2.09
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021/09/29
 * 
 */

/* LIBRARIES */
#include <stdio.h>

/* SYMBOLIC CONSTANTS */
/* EXTERNAL VARIABLES */
/* FUNCTIONS DECLARATIONS */
unsigned setbits(unsigned x, int p, int n, int y);
// only for test
void showBits(unsigned n, int size);
unsigned getbits(unsigned x, int p, int n);

/* FUNCTIONS DEFINITIONS */

/**
 * @brief Exercise 2-6 from section 2.09
 * Exercise 2-6. Write a function setbits(x, p, n, y) that returns x with 
 * the n bits that begin at position p set to the rightmost n bits of y, 
 * leaving the other bits unchanged.
 * 
 * @return int State of program value
 */
int main(void)
{
    // x= 1111 1111; p=7; n=4; y=0111 1000
    // p: 7654 3210 (positions)
    // n: ****
    // Result:  x: ---- ****   <--  y: ---- **** = 1000 1111
    printf("setbits(%u, %d, %d, %u) = ", 255, 7, 4, 120);
    showBits(setbits(255, 7, 4, 120), 8);
    putchar('\n');

    // x= 0110 1010; p=2; n=1; y=1111 1111
    // p: 7654 3210 (positions)
    // n: ****
    // Result:  x: ---- -*--   <--  y: ---- ---* = 0110 1110
    printf("setbits(%u, %d, %d, %u) = ", 106, 2, 1, 255);
    showBits(setbits(106, 2, 1, 255), 8);
    putchar('\n');

    // x= 0110 1010; p=0; n=1; y=1111 1111
    // p: 7654 3210 (positions)
    // n: *
    // Result:  x: ---- ---*   <--  y: ---- ---* = 0110 1011
    printf("setbits(%u, %d, %d, %u) = ", 106, 0, 1, 255);
    showBits(setbits(106, 0, 1, 255), 8);
    putchar('\n');

    // x= 0110 1010; p=0; n=1; y=1111 1111
    // p: 7654 3210 (positions)
    // n: *
    // Result:  x: ---- ---*?   <--  y: ---- ---*? = ??
    printf("setbits(%u, %d, %d, %u) = ", 106, 0, 2, 255);
    showBits(setbits(106, 0, 2, 255), 8);
    putchar('\n');
    return 0;
}

/**
 * @brief Replace the n bits in x that begin at p, for the n rightmost bits in y
 * 
 * @param x Number to modify
 * @param p Position to begin modification
 * @param n Count of bits to modify
 * @param y Number with the n bits used to replace (at rightmost place)
 * 
 * @return unsigned Number modified; 0 if error
 */
unsigned setbits(unsigned x, int p, int n, int y)
{
    if (n > p + 1) {
        printf("Error No exists %d bits between position %d and rightmost position - ", n, p);
        return 0;
    }
    unsigned pattern_n;
    unsigned pattern_np;
    unsigned y_last_n;

    // GET X WITH BITS TO BE REPLACED AS 0
    // get pattern for rightmost n digits
    pattern_n = ~(~0 << n);

    // move pattern to pos
    pattern_np = pattern_n << p - n + 1;

    // switch off the pattern-in-pos bits for x
    x = x & ~pattern_np;

    // GET Y WITH ONLY BITS TO REPLACE
    // get the n last numbers of y
    y_last_n = y & pattern_n;

    // Move the last numbers of y to pos
    y = y_last_n << p - n + 1;

    // replace bits off in x with bits on in y
    return x | y;
}

/**
 * @brief Get n bits from position p of a number x.
 * 
 * @param x 
 * @param p 
 * @param n 
 * @return unsigned 
 */
unsigned getbits(unsigned x, int p, int n)
{
    // if max bits = 8; x = 125(0111 1101); n = 3; p = 4
    // ~0                 --> 1111 1111
    // (~0 << n)          --> 1111 1000
    // ~(~0 << n)         --> 0000 0111 (get set of bits align to right)
    //
    // (p + 1 - n)        --> 4 +1 -3 = 2 (calculate the number of positions to move the group)
    // (x >> (p + 1 - n)) --> 0001 1111 (move the set of bits to get into right)
    // (0001 1111) & (0000 0111) --> 111 (capture only the set of bits)
    return (x >> (p + 1 - n)) & ~(~0 << n);
}
/**
 * @brief print to standard output the "size" rightmost bits of n
 * 
 * @param n number to show as base-2
 * @param size Number of bits to show.
 */
void showBits(unsigned n, int size)
{
    int pos = size;
    for (int i = 0; i < size; i++) {

        printf("%u", getbits(n, --pos, 1));
        if ((i + 1) % 4 == 0)
            putchar(' ');
    }
}
