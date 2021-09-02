/**
 * @file exercise_1-13_ver.c
 * @brief Exercise 1-13 (vertical version) from section 1.6.
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1-ver
 * @date 2021-08-8
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>

// SYMBOLIC CONSTANTS
#define IN 1
#define OUT 0
#define MAXWORDS 1024

// FUNCTIONS
/**
 * @brief  Exercise 1-13 (vertical version) from section 1.6.
 * Write a program to print a histogram of the lengths of words in its input. 
 * It is easy to draw the histogram with the bars horizontal;
 * a vertical orientation is more challenging.
 * 
 * @note vertical version
 * @return implicit int - state of program value
 */

main()
{
	int c;
	int maxLines = 0;	  // number of lines in all input
	int width = 0;		  // current word lenght
	int maxWidth = 0;	  // longest word
	int posInLine = 0;	  // position of word in its line
	int maxPos = 0;		  // max number of words by line
	int widths[MAXWORDS]; // all words witdth
	int i = 0;			  // index to widths

	// init array values to 0
	for (int i = 0; i < MAXWORDS; ++i)
		widths[i] = 0;

	// GET INPUT DATA
	while ((c = getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if (width > 0)
			{
				if (width > maxWidth)
					maxWidth = width;

				widths[i] = width;
				++i;
			}

			width = 0;
			if (++posInLine > maxPos)
				maxPos = posInLine;

			if (c == '\n')
			{
				widths[i] = width;
				++i;
				posInLine = 0;
				maxLines++;
			}
		}
		else
		{
			++width;
		}
	}

	// PRINT RESULT
	// if no words
	if (maxPos == 0)
	{
		printf("No word in input\n");
	}
	// if words
	else
	{
		// print header
		printf("maxLines: %d - maxWordsLine: %d - greaterWord: %d\n",
			   maxLines, maxPos, maxWidth);

		// top table
		printf("        ");
		for (int i = 0; i < (maxLines * 5) - 1; ++i)
		{
			putchar('_');
		}
		putchar('\n');

		// data line
		for (int i = maxWidth - 1; i > 0; --i)
		{
			// line header (position in each line)
			printf("pos %2d |", i);

			// data
			// line data
			for (int j = maxLines; j > 0; --j)
			{
				// calculate each data and print (word position in a line)

				// search width in array up on line and position
				//
				int findLine =
					(maxLines - j) + 1; // line to find
				int findPos = i;		// position to find
				int size =
					maxLines * maxPos; // max util size of array
				int lin = 1;		   // line where it´s searching
				int pos = 0;		   // position where it´s searching
				width = 0;			   // value to print

				for (int i = 0; i < size && lin < maxLines; ++i)
				{
					// get the table position
					if (widths[i] == 0) // end line
					{
						++lin;
						pos = 0;
					}
					else
					{
						++pos;
					}
					// store value
					if (pos == findPos && lin == findLine)
						width = widths[i];
				}

				// print width value
				if (width == 0)
				{
					printf("    |");
				}
				else
				{
					printf("%3d |", width);
				}
			}
			putchar('\n');
		}

		// data bottom / lines header top
		printf("       |");
		for (int i = 0; i < (maxLines); ++i)
		{
			printf("____|");
		}
		putchar('\n');

		// lines header (in table bottom)
		printf("        ");
		for (int i = maxLines; i > 0; --i)
		{
			printf("%2dL  ", maxLines - i + 1);
		}
		putchar('\n');
	}
}
