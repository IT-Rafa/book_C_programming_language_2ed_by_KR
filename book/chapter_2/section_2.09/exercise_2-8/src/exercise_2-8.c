/**
 * @file exercise_2-8.c
 * @brief Exercise 2-8 from section 2.09
 * Exercise 2-8. Write a function rightrot(x, n) that returns the value of
 * the integer x rotated to the right by n bit positions.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021/09/29
 * 
 */

/* LIBRARIES */
#include <limits.h>
#include <stdio.h>

/* SYMBOLIC CONSTANTS */
#define SIZE 32

/* EXTERNAL VARIABLES */

/* FUNCTIONS DECLARATIONS */
// only for test
void showBits(unsigned n, unsigned size);
unsigned getbits(unsigned x, int p, int n);

/* FUNCTIONS DEFINITIONS */
/**
 * @brief Calculate the base-2 value  of x rotated to the right by n bit positions.
 * 
 * @param x The value to mofify
 * @param n Caunt of bits to rotate
 * @return unsigned The modified value
 */
unsigned rightrot(unsigned x, int n)
{

    // rotation is equal
    if (x == 0 || x == ~0U || n == 0) {
        return x;
    }

    unsigned allBitsLessLast, lastbitToleft;

    for (; n > 0; n--) {
        // move all bits one to one position to right (lose last bit)
        allBitsLessLast = x >> 1U;

        // MOVE LAST BIT OF x TO THE LEFTMOST POSITION
        // get the all one number (using unsigned literal to ignore sign, or it add 1 to leftmost)
        // if rightmost bit is on, move 1 bit to right; else, nothing
        // invert the result
        lastbitToleft = ~(~0U >> (x & 1U));

        // add bit rotated
        x = allBitsLessLast | lastbitToleft;
    }

    return x;
}

/**
 * @brief Print test for exercise 
 * 
 * @return int State of program value
 */
int main(void)
{
    unsigned result, n;
    int p;
    // rightrot(267437004, 7)
    // original: 0000 1111 1111 0000 1100 0011 1100 1100
    // changed : 1001 1000 0001 1111 1110 0001 1000 0111(2552226183)
    n = 267437004;
    p = 7;
    result = rightrot(n, p);
    printf("rightrot(%u, %d) = %u (", n, p, result);
    showBits(result, SIZE);
    printf(")\n");

    // rightrot(221, 2)
    // original: 0000 0000 0000 0000 0000 0000 1101 1101
    // changed : 0100 0000 0000 0000 0000 0000 0011 0111
    n = 221;
    p = 2;
    result = rightrot(n, p);
    printf("rightrot(%u, %d) = %u (", n, p, result);
    showBits(result, SIZE);
    printf(")\n");

    // rightrot(221, 34) ;full rotate + 2; if (uint = 32)
    // original: 0000 0000 0000 0000 0000 0000 1101 1101
    // changed : 0100 0000 0000 0000 0000 0000 0011 0111
    n = 221;
    p = 34;
    result = rightrot(n, p);
    printf("rightrot(%u, %d) = %u (", n, p, result);
    showBits(result, SIZE);
    printf(")\n");

    // rightrot(221, 0) ;
    // original: 0000 0000 0000 0000 0000 0000 1101 1101
    // changed : 0000 0000 0000 0000 0000 0000 1101 1101
    n = 221;
    p = 0;
    result = rightrot(n, p);
    printf("rightrot(%u, %d) = %u (", n, p, result);
    showBits(result, SIZE);
    printf(")\n");

    // rightrot(0, 2) ;
    // original: 0000 0000 0000 0000 0000 0000 0000 0000
    // changed : 0000 0000 0000 0000 0000 0000 0000 0000
    n = 0;
    p = 5;
    result = rightrot(n, p);
    printf("rightrot(%u, %d) = %u (", n, p, result);
    showBits(result, SIZE);
    printf(")\n");

    // rightrot(~0U, 0) ;
    // original: 0000 0000 0000 0000 0000 0000 0000 0000
    // changed : 0000 0000 0000 0000 0000 0000 0000 0000
    n = ~0U;
    p = 5;
    result = rightrot(n, p);
    printf("rightrot(%u, %d) = %u (", n, p, result);
    showBits(result, SIZE);
    printf(")\n");

    return 0;
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
void showBits(unsigned n, unsigned size)
{
    unsigned pos = size;
    for (int i = 0; i < size; i++) {
        printf("%u", getbits(n, --pos, 1));

        if (i != size - 1 && (i + 1) % 4 == 0)
            putchar(' ');
    }
}
