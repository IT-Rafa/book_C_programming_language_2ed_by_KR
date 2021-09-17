/**
 * @file exercise_2-1.c
 * @brief Exercise 2-1 from section 2.2
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-9-12
 * 
 * @todo convert while repetition in function or 
 */

// LIBRARIES
// Needed to use printf
#include <limits.h>
#include <float.h>
#include <stdio.h>

/* SYMBOLIC CONSTANTS */

/* EXTERNAL VARIABLES */

/* FUNCTIONS DECLARATIONS */

long getlongmax(char sign);
int getintmax(char sign);
short getshortmax(char sign);
char getcharmax(char sign);

long power(long base, long n);

/* FUNCTIONS DEFINITIONS */

/**
 * @brief Exercise 2-1 from section 2.3.
 * Exercise 2-1. Write a program to determine the ranges of char, short, int, 
 * and long values from standard headers and by direct computation.
 * Harder if you compute them: determine the ranges of the various 
 * floating-points types.
 * 
 * @return implicit int - state of program value
 */
int main(void)
{
    printf("HEADER <limit.h>\n");
    printf("\tchar  = %d - %d\n", CHAR_MIN, CHAR_MAX);
    printf("\tshort = %d - %d\n", SHRT_MIN, SHRT_MAX);
    printf("\tint   = %d - %d\n", INT_MIN, INT_MAX);
    printf("\tlong  = %ld - %ld\n", LONG_MIN, LONG_MAX);

    printf("\nCOMPUTE RANGUE: INTEGERS\n");
    printf("\tchar  = %d - %d\n", getcharmax('-'), getcharmax('+'));
    printf("\tshort = %d - %d\n", getshortmax('-'), getshortmax('+'));
    printf("\tint   = %d - %d\n", getintmax('-'), getintmax('+'));
    printf("\tlong  = %ld - %ld\n", getlongmax('-'), getlongmax('+'));

    printf("\nHEADER <float.h>\n");
    printf("\tfloat     = %e - %e\n", FLT_MIN, FLT_MAX);
    printf("\tdouble    = %e - %e\n", DBL_MIN, DBL_MAX);


    return 0;
}
/**
 * @brief Caculate base to the n power.
 * @warning No work with negative values
 * 
 * @param base Number to raise
 * @param n The exponent
 * @return long Result of power
 */
long power(long base, long n)
{
    long p;

    if (n == 0)
        return 1;
    else if (n < 0 || base < 0)
        return -1;
    else {
        for (p = 1; n > 0; --n) {
            p = p * base;
        }
        return p;
    }
}

/**
 * @brief Get the max or min value of char type
 * 
 * @param sign Indicate if return max('+') or min('-') value of char type
 * @return char The max or min value of char type. 0 if error.
 */
char getcharmax(char sign)
{
    /* this vars must be the type to check */
    char maxtype = 0;
    char maxtadd;

    /* this part is the same in all getxmax functions */
    int maxpower;
    /* get the power of two until overflow - when sign is changed */
    for (maxpower = 0; maxtype >= 0; ++maxpower) {
        maxtype = power(2, maxpower);
    }

    /* valid if is two's complement representation */
    if (sign == '+') {
        // get previous power of two, multiply by 2 and substract 1
        return ((maxtype / -2) * 2) - 1;
    }
    else if (sign == '-') {
        /* the calculated overflow is ok */
        return maxtype;
    }
    return 0;
}

/**
 * @brief Get the max or min value of short type
 * 
 * @param sign Indicate if return max('+') or min('-') value of short type
 * @return short The max or min value of short type. 0 if error.
 */
short getshortmax(char sign)
{
    /* this vars must be the type to check */
    short maxtype = 0;
    short maxtadd;

    /* this part is the same in all getxmax functions */
    int maxpower;
    /* get the power of two until overflow - when sign is changed */
    for (maxpower = 0; maxtype >= 0; ++maxpower) {
        maxtype = power(2, maxpower);
    }

    /* valid if is two's complement representation */
    if (sign == '+') {
        // get previous power of two, multiply by 2 and substract 1
        return ((maxtype / -2) * 2) - 1;
    }
    else if (sign == '-') {
        /* the calculated overflow is ok */
        return maxtype;
    }
    return 0;
}

/**
 * @brief Get the max or min value of int type
 * 
 * @param sign Indicate if return max('+') or min('-') value of int type
 * @return int The max or min value of int type. 0 if error.
 */
int getintmax(char sign)
{
    /* this vars must be the type to check */
    int maxtype = 0;
    int maxtadd;

    /* this part is the same in all getxmax functions */
    int maxpower;
    /* get the power of two until overflow - when sign is changed */
    for (maxpower = 0; maxtype >= 0; ++maxpower) {
        maxtype = power(2, maxpower);
    }

    /* valid if is two's complement representation */
    if (sign == '+') {
        // get previous power of two, multiply by 2 and substract 1
        return ((maxtype / -2) * 2) - 1;
    }
    else if (sign == '-') {
        /* the calculated overflow is ok */
        return maxtype;
    }
    return 0;
}

/**
 * @brief Get the max or min value of long type
 * 
 * @param sign Indicate if return max('+') or min('-') value of long type
 * @return long The max or min value of long type. 0 if error.
 */
long getlongmax(char sign)
{
    /* this vars must be the type to check */
    long maxtype = 0;
    long maxtadd;

    /* this part is the same in all getxmax functions */
    int maxpower;
    /* get the power of two until overflow - when sign is changed */
    for (maxpower = 0; maxtype >= 0; ++maxpower) {
        maxtype = power(2, maxpower);
    }

    /* valid if is two's complement representation */
    if (sign == '+') {
        // get previous power of two, multiply by 2 and substract 1
        return ((maxtype / -2) * 2) - 1;
    }
    else if (sign == '-') {
        /* the calculated overflow is ok */
        return maxtype;
    }
    return 0;
}
