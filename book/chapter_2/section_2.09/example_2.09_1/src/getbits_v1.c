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
#define SIZE 8
/* EXTERNAL VARIABLES */
/* FUNCTIONS DECLARATIONS */
unsigned getbits(unsigned x, int p, int n);
void showBits(unsigned n, int size);

/* FUNCTIONS DEFINITIONS */
/**
 * @brief test getbits function.
 * @return int State of program value
 */
int main(void)
{
    unsigned resultB10;

    // get the value in base-10 of 3 bits from position x of 125(base-10)
    // (begin to count from right))
    unsigned x = 121; // 0111 1001
    int p = 4;        //    *
    int n = 3;        //    * **
                      // Debe ser 6(110)
    resultB10 = getbits(x, p, n);
    printf("The value in base-10 of %d bits from position %d of %u(base-10) is: %u\n",
           n, p, x, resultB10);

    // Result in base-2
    printf("%u in base-2 is: ", resultB10);
    showBits(resultB10, SIZE);
    putchar('\n');
    return 0;
}

/**
 * @brief Get n bits from position p of a number x.
 * 
 * @param x Number for which get the bits 
 * @param p Position of first bit to get (counting from the right)
 * @param n Count of bits to get
 * @return unsigned The base-10 value of the captured bits
 */
unsigned getbits(unsigned x, int p, int n)
{
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
