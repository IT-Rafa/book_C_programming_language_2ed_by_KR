/**
 * @file exercise_1-14_ver.c
 * @brief Exercise 1-14 (vertical version) from section 1.6.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-8-02
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>
#define CHARSETSIZE 128

// FUNCTIONS
/**
 * @brief Exercise 1-14 (vertical version) from section 1.6.
 * Write a program to print a histogram of the frequencies of diferents 
 * characters in its input.
 * 
 * @note horizontal version
 * @return implicit int - state of program value
 */
main()
{
    int c;       // read char
    int ncd = 0; // nunber of chars in input (without repetitions)
    int max = 0; // the greater num of char repetitions
    int tc = 0;  // total chars
    int charCount[CHARSETSIZE];
    int order[CHARSETSIZE];

    for (int i = 0; i < CHARSETSIZE; ++i)
    {
        charCount[i] = 0;
        order[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        ++tc;

        int find = 0;
        for (int i = 0; i < ncd; ++i)
        {
            if (c == order[i])
            {
                ++charCount[i];
                if (charCount[i] > max)
                    max = charCount[i];
                find = 1;
            }
        }
        if (!find)
        {
            order[ncd] = c;
            ++charCount[ncd];
            ++ncd;
        }
    }

    printf("total chars: %d\n", tc);
    if (tc != 0)
    {
        putchar(' ');
        for (int i = 0; i < (ncd * 4) - 1; ++i)
            putchar('_');

        putchar('\n');
        for (int i = max; i > 0; --i)
        {
            putchar('|');
            for (int j = 0; j < ncd; ++j)
            {
                if (i != 1)
                {
                    if (charCount[j] >= i)
                        printf(" * |");
                    else
                        printf("   |");
                }
                else
                {
                    if (charCount[j] >= i)
                        printf("_*_|");
                    else
                        printf("___|");
                }
            }
            putchar('\n');
        }
        putchar(' ');
        for (int j = 0; j < ncd; ++j)
        {
            if (order[j] == '\n')
                printf("\\n");
            else if (order[j] == '\t')
                printf("\\t");
            else
            {
                putchar(' ');

                putchar(order[j]);
            }
            putchar(' ');

            putchar(' ');
        }
        putchar('\n');
    }
}
