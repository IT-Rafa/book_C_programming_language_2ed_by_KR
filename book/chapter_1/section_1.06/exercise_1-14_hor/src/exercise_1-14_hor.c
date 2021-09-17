/**
 * @file exercise_1-14_hor.c
 * @brief Exercise 1-14 (horizontal version) from section 1.6.
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
 * @brief Exercise 1-14 (horizontal version) from section 1.6.
 * Write a program to print a histogram of the frequencies of diferents 
 * characters in its input.
 * 
 * @note horizontal version
 * @return implicit int - state of program value
 */
main()
{

    /*
        - differents chars = ascii chars
        - ascii chars: 0-127

    */
    int c;
    int nc = 0;
    int ascii[CHARSETSIZE];
    for (int i = 0; i < CHARSETSIZE; ++i)
        ascii[i] = 0;

    // count chars from input
    while ((c = getchar()) != EOF)
    {
        ++ascii[c];
        ++nc;
    }

    // print result
    printf("total chars: %d\n", nc);
    if (nc > 0)
    {
        putchar('\n');
        for (int i = 0; i < CHARSETSIZE; ++i)
        {
            if (ascii[i] > 0)
            {
                putchar('\'');
                if (i == '\n')
                    printf("\\n'");
                else if (i == '\t')
                    printf("\\t'");
                else
                    printf("%c\' ", i);

                printf(" (%3d)| ", i);
                for (int j = 0; j < ascii[i]; ++j)
                    putchar('*');
                putchar('\n');
            }
        }
    }
}
