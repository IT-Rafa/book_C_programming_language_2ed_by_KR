/**
 * @file Section_1.3_Test.c
 * @brief Tests for section 1.3. exercises
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-10
 */

// LIBRARIES
// Needed to tests
#include "..\..\..\CuTest\CuTest.h"
#include "..\..\..\testUtil\testUtil.h"

// FUNCTIONS

// TEST FUNCTIONS
/**
 * @brief  Test for exercise 1-5 from section 1.3.
 * Check if output is as the expected
 * 
 * @pre the exercise 1-5 must be compiled
 * @return implicit int - state of program value
 */
#define MAXOUTPUTSIZE 1024

void Exercise_1_5_Test(CuTest *tc)
{
	char exePath[MAXOUTPUTSIZE] = ".\\book\\chapter_1\\section_1.03\\exercise_1-5\\bin\\exercise_1-5.exe";
	char actualPath[MAXOUTPUTSIZE] = ".\\test\\src\\chapter_1\\section_1.03\\docTest\\exe_1_5_out_actual.txt";
	char expectedPath[MAXOUTPUTSIZE] = ".\\test\\src\\chapter_1\\section_1.03\\docTest\\exe_1_5_out_expected.txt";
	char expected[MAXOUTPUTSIZE];
	char actual[MAXOUTPUTSIZE];
	/* execute program and send output to file */
	if (!exeToFile(exePath, actualPath))
	{
		CuAssert(tc, "Fail to execute the exercise 1.5", 0);
	}

	/* read actual(executable output) and expected (directly created) text files and store both in strings */
	if (fileToSt(actualPath, actual) >= 0)
	{
		if (fileToSt(expectedPath, expected) >= 0)
		{
		}
		else
		{
			CuAssert(tc, "Fail to read the expected output of exercise 1.5", 0);
		}
	}
	else
	{
		CuAssert(tc, "Fail to read the actual output of exercise 1.5", 0);
	}
	/* compare strings */
	CuAssertStrEquals(tc, expected, actual);
}

// ADD CUTEST FUNCTION
CuSuite *Section_1_03()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Exercise_1_5_Test);
	return suite;
}
