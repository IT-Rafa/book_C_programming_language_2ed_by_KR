/**
 * @file Section_1.2_Test.c
 * @brief Tests for section 1.2. exercises
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-07-30
 */

// LIBRARIES
// Needed to tests
#include "..\..\..\CuTest\CuTest.h"
// Needed to use printf
#include <stdio.h>
// Neede to run exercise compiled
#include <stdlib.h>
// Needed to create the instruction to system for save output
#include <string.h>

// FUNCTIONS

// TEST FUNCTIONS (CUTEST)
/**
 * @brief  Test for exercise 1-3 from section 1.2.
 * Check if output is as the expected
 * 
 * @pre the exercise 1-3 must be compiled
 * @return implicit int - state of program value
 */
void Exercise_1_3_Test(CuTest *tc)
{

	int filetostring(char *fileName, char *st);

	char exePath[1000] = ".\\book\\chapter_1\\section_1.02\\exercise_1-3\\bin\\exercise_1-3.exe";
	char actualPath[1000] = ".\\test\\src\\chapter_1\\section_1.02\\docTest\\exe_1_3_out_actual.txt";
	char expectedPath[1000] = ".\\test\\src\\chapter_1\\section_1.02\\docTest\\exe_1_3_out_expected.txt";

	char expected[1000];
	char actual[1000];

	/* check if executable exists */
	FILE *exe = fopen(exePath, "r");
	if (exe == NULL)
	{
		system("dir");
		CuAssert(tc, "Falta el ejecutable del ejercicio 1-3", 0);
	}
	
	/* check if file to compare exists */
	FILE *f = fopen(expectedPath, "r");
	if (f == NULL)
	{
		CuAssert(tc, "Falta el archivo para comparar la salida del ejercicio 1-3", 0);
	}
	/* run executable and store in file */
	/* depend on system */
	strcat(exePath, " > ");
	strcat(exePath, actualPath);
	system(exePath);

	/* store output and example in strings*/
	filetostring(actualPath, actual);
	filetostring(expectedPath, expected);
	/* compare strings */
	CuAssertStrEquals(tc, expected, actual);
}

/**
 * @brief  Test for exercise 1-4 from section 1.2.
 * Check if output is as the expected
 * 
 * @pre the exercise 1-4 must be compiled
 * @return implicit int - state of program value
 */
void Exercise_1_4_Test(CuTest *tc)
{

	int filetostring(char *fileName, char *st);

	char exePath[1000] = ".\\book\\chapter_1\\section_1.02\\exercise_1-4\\bin\\exercise_1-4.exe";
	char actualPath[1000] = ".\\test\\src\\chapter_1\\section_1.02\\docTest\\exe_1_4_out_actual.txt";
	char expectedPath[1000] = ".\\test\\src\\chapter_1\\section_1.02\\docTest\\exe_1_4_out_expected.txt";

	char expected[1000];
	char actual[1000];

	/* check if executable exists */
	FILE *exe = fopen(exePath, "r");
	if (exe == NULL)
	{
		CuAssert(tc, "Falta el ejecutable del ejercicio 1-4", 0);
	}
	/* check if file to compare exists */
	FILE *f = fopen(expectedPath, "r");
	if (f == NULL)
	{
		CuAssert(tc, "Falta el archivo para comparar la salida del ejercicio 1-4", 0);
	}
	/* run executable and store in file */
	/* depend on system */
	strcat(exePath, " > ");
	strcat(exePath, actualPath);
	system(exePath);

	/* store output and example in strings*/
	filetostring(actualPath, actual);
	filetostring(expectedPath, expected);
	/* compare strings */
	CuAssertStrEquals(tc, expected, actual);
}

// ADD CUTEST FUNCTION
CuSuite *Section_1_02()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Exercise_1_3_Test);
	SUITE_ADD_TEST(suite, Exercise_1_4_Test);
	return suite;
}


// UTILITIES FOR TEST FUNCTIONS
/**
 * @brief Store content of text file in a string.
 * 
 * @param fileName Path to file to read content.
 * @param st Pointer to init of string where will be stored the content
 * @return -1 if error else the number of char read from file
 */
int filetostring(char *fileName, char *st)
{
	char c;
	int count = 0;
	// Check if file exists
	FILE *f = fopen(fileName, "r");
	if (f == NULL)
	{
		return -1;
	}

	// Store file content in string
	while ((c = getc(f)) != EOF)
	{
		*st++ = c;
		count++;
	}
	*st = '\0';
	return count;
}
