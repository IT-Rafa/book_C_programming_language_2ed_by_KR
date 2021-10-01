/**
 * @file exercise_2-7.c
 * @brief Exercise 2-7 from section 2.09
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021/09/29
 * 
 */

/* LIBRARIES */
#include <stdio.h>

/* SYMBOLIC CONSTANTS */
#define SIZE 8

/* EXTERNAL VARIABLES */

/* FUNCTIONS DECLARATIONS */
unsigned invert(unsigned x, int p, int n);
// only for test
void showBits(unsigned n, int size);
unsigned getbits(unsigned x, int p, int n);

/* FUNCTIONS DEFINITIONS */

/**
 * @brief Exercise 2-7 from section 2.09
 * Exercise 2-7. Write a function invert(x, p, n) that returns x with 
 * the n bits that begin at position p inverted (i.e., 1 changed into 0 and 
 * vice versa), leaving the others unchanged.
 * 
 * @return int State of program value
 */
int main(void)
{
    // p=7; n=3
    // n=120(0111 1000)
    // 0111 1000 -> 1001 1000(152)
    printf("invert(120, 7, 3) = ");
    showBits(invert(120, 7, 3), SIZE);
    putchar('\n');

    // p=0; n=1
    // n=120(0111 1000)
    // 0111 1000 -> 0111 1001(121)
    printf("invert(120, 0, 1) = ");
    showBits(invert(120, 0, 1), SIZE);
    putchar('\n');

    // p=0; n=2
    // n=120(0111 1000)
    // 0111 1000? -> 0111 1001? -ERROR
    printf("invert(120, 0, 2) = ");
    showBits(invert(120, 0, 2), SIZE);
    putchar('\n');

    return 0;
}

/**
 * @brief returns x with the n bits that begin at position p inverted (i.e., 1 changed into 0 and 
 * vice versa), leaving the others unchanged.
 * 
 * @param x The number to modify
 * @param p The initial bit position to invert
 * @param n The count of bits to invert
 * @return unsigned The modified number; 0 if error
 */
unsigned invert(unsigned x, int p, int n)
{
    // check right values
    if (n > p + 1) {
        printf("Error in invert() call: No exists %d bits between position %d and rightmost position - ", n, p);
        return 0;
    }
    int move = p - n + 1;
    unsigned pattern;
    unsigned invertField;
    unsigned subChanged;

    // mov n-bit field from x to rightmost position and invert
    subChanged = ~(x >> move);

    // patron n
    pattern = ~(~0 << n);

    // put on 0 the rest
    subChanged = subChanged & pattern;

    // move new n-bit field to position
    subChanged = (subChanged & pattern) << move;

    // move pattern to position
    pattern = pattern << move;

    // put 0 at  n-bits field at x
    x = x & ~pattern;

    // put n-bits field value on  x and return it
    return x | subChanged;
}

/**
 * @brief Get n bits from position p of a number x.
 * 
 * @param x The number where the field to get is
 * @param p The initial bit position to get
 * @param n The count of bits to get
 * 
 * @return unsigned The n-bits field
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

        if (i != size-1 && (i + 1) % 4 == 0)
            putchar(' ');
    }
}
