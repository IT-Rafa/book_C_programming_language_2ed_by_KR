/**
 * @file rand_v1.c
 * @brief Example 3 from section 2.7 - page 46
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
unsigned long int next = 1;

/* FUNCTIONS DECLARATIONS */
int rand(void);
void srand(unsigned int seed);

/* FUNCTIONS DEFINITIONS */
/**
 * @brief test rand function.
 * @return int State of program value
 */
int main(void)
{
    printf("random number 1: %d\n", rand());
    printf("random number 2: %d\n", rand());
    return 0;
}

/**
 * @brief Return pseudo-random integer on 0..32767
 * 
 * @return int A pseudo-random integer between 0 and 32767
 */
int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

/**
 * @brief Set seed for rand() function
 * 
 * @return int Seed
 */
void srand(unsigned int seed)
{
    next = seed;
}
