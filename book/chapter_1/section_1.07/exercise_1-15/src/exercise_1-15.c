/**
 * @file exercise_1-15.c
 * @brief Exercise 1-15 from section 1.6.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-9-02
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

// FUNCTIONS
/**
 * @brief Exercise 1-15 from section 1.6.
 * Rewrite the temperature conversion program of Section 1.2 to use a function for conversion.
 * 
 * @note There are two versions. We will use the float version
 * @return implicit int - state of program value
 */
float fahrToCelsius(float fahr);

main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;   /* lower limit of temerature table */
    upper = 300; /* upper limit */
    step = 20;   /* step size */

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = fahrToCelsius(fahr);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

float fahrToCelsius(float fahr)
{
    return (5.0/9.0) * (fahr - 32.0);
}
