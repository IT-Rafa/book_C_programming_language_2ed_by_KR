/**
 * @file exercise_2-3.c
 * @brief Exercise 2-3 from section 2.7
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-9-12
 * 
 */

/* LIBRARIES */
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
/* SYMBOLIC CONSTANTS */

/* EXTERNAL VARIABLES */
/* FUNCTIONS DECLARATIONS */
unsigned int htoi(char s[]);
int hexaCharToInt(char c);
int getInitNoEmptyPosition(char s[]);

/* FUNCTIONS DEFINITIONS */

/**
 * @brief Exercise 2-3 from section 2.7.
 * Exercise 2-3. Write the function htoi(s), which converts a string of hexadecimal digits 
 * (including an optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9, a through f, and A throught F
 * 
 * @return int State of program value
 */
int main(void)
{
    // Test htoi(s)

    unsigned int value;

    // list of test but max
    char stList[10][15] = {
        "  f",
        "  F",
        "0xf",
        "0Xf",
        "0xF",
        "0XF",
        "0xF5",
        "1acb2fF",
        "j"
        };

    // convert list
    for (int i = 0; i < 9; ++i) {
        printf("hexadecimal number: %s is the integer: %u\n",
               stList[i], htoi(stList[i]));
    }

    // convert max
    char maxHex[15]; // string to store the max value of usigned int
    sprintf(maxHex, "%x", UINT_MAX);

    printf("hexadecimal number: %s is the integer: %u\n",
           maxHex, htoi(maxHex));

    // convert over max
    char overMaxHex[15] = ""; // string to store the max value of usigned int
    int len = strlen(maxHex);
    strcat(overMaxHex, "1");
    for (int i = 0; i < len; ++i) {
        strcat(overMaxHex, "0");
    }
    printf("hexadecimal number: %s is the integer: %u\n",
           overMaxHex, htoi(overMaxHex));

    return 0;
}
/**
 * @brief Converts a string of hexadecimal digits into its equivalent integer value
 * Converts a string of hexadecimal digits into its equivalent integer value
 * (including an optional 0x or 0X) 
 * 
 * @param s The string of hexadecimal to convert
 * @return unsigned int The base 10 value of the string converted. 
 * Return 0 if overflow or any char isn't hexadecimal char
 * @note Cannot return -1 when return type is unsigned. All return values could be valid.
 */
unsigned int htoi(char s[])
{
    unsigned int result = 0;
    int init, end, ptwo;

    init = getInitNoEmptyPosition(s);
    end = strlen(s) - 1;

    // ignore prefix 0x 0X
    if (s[init] == '0' && (s[init + 1] == 'x' || s[init + 1] == 'X'))
        init = init + 2;

    // Calculate powers of 16 of each right position and add all
    for (end = strlen(s) - 1, ptwo = 0;
         end >= init;
         --end, ++ptwo) {
        int n;
        if ((n = hexaCharToInt(s[end])) == -1)
            return 0;
        if ((result + (n * pow(16, ptwo))) > UINT_MAX) {
            return 0;
        }
        result = result + (n * pow(16, ptwo));
    }
    return result;
}
/**
 * @brief Convert a hexadecimal character into its base 10 value
 * 
 * @param c The hexadecimal character to convert
 * @return int The base 10 value of c. 0 if no hexadecimal char.
 */
int hexaCharToInt(char c)
{
    if (c >= '0' && c <= '9')
        return c - '0';
    else if (c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if (c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    else
        return -1;
}

int getInitNoEmptyPosition(char s[])
{
    int init = 0;
    if (s[0] == ' ' || s[0] == '\t') {
        for (int i = 1; s[i] == ' '; ++i)
            init = i;

        ++init;
    }
    return init;
}
