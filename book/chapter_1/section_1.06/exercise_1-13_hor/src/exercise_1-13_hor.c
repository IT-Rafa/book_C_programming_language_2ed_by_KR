/**
 * @file exercise_1-13_hor.c
 * @brief Exercise 1-13 (horizontal version) from section 1.6.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1-hor
 * @date 2021-08-8
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

#define IN 1
#define OUT 0
// FUNCTIONS
/**
 * @brief  Exercise 1-13 (horizontal version) from section 1.6.
 * Write a program to print a histogram of the lengths of words in its input. 
 * It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 * 
 * @note Horizontal version

 * @return implicit int - state of program value
 */
main()
{
	int c;
	int inWord = OUT;
	int nLine = 1;
	int pos = 0;
	int count = 0;

	while ((c = getchar()) != EOF)
	{
		// header
		if (pos == 0)
		{
			printf("%2dL |", nLine);
		}

		// control
		++pos;
		if (c == ' ' || c == '\t' || c == '\n')
		{
			// words
			if (inWord)
			{
				inWord = OUT;
				printf(" %d", count);
				count = 0;
			}
			// lines
			if (c == '\n')
			{
				if (pos == 1)
				{
					printf(" %d", count);
				}
				pos = 0;
				putchar(c);
				++nLine;
			}
		}
		else
		{
			inWord = IN;
			count++;
		}

	}
	if (nLine == 1 && c == EOF)
	{
		printf("No word in input\n");
	}
}
