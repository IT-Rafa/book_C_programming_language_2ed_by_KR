/**
 * @file Section_1.05.1_Test.c
 * @brief Tests for section 1.05.1. exercises
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-07-30
 */

// LIBRARIES
// Needed to tests
#include "CuTest.h"
#include "testUtil.h"
#include <stddef.h>

// FUNCTIONS

// TEST FUNCTIONS (CUTEST)
/**
 * @brief  Test 1 for exercise 1-6 from section 1.05.1
 * Use a empty file as input.
 * char() != EOF read the first char. there is no char so char() return EOF.
 * So EOF != EOF is false(0)
 * 
 * @pre the exercise 1-6 source must exists and be in the expected folder 
 */
void Exercise_1_6_Test1(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.1", "exercise_1-6"};
	char testName[] = "test1_";

	testOnlyMainExercise(tc, testName, exer);
}
void Exercise_1_6_Test2(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.1", "exercise_1-6"};
	char testName[] = "test2_";

	testOnlyMainExercise(tc, testName, exer);
}
/**
 * @brief  Test for exercise 1-7 from section 1.05.1
 * Check if output is as the expected
 * 
 * @pre the exercise 1-7 source must exists and be in the expected folder 
 */
void Exercise_1_7_Test(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.1", "exercise_1-7"};

	testOnlyMainExercise(tc, NULL, exer);
}

// ADD CUTEST FUNCTION
CuSuite *Section_1_05_1()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Exercise_1_6_Test1);
	SUITE_ADD_TEST(suite, Exercise_1_6_Test2);

	SUITE_ADD_TEST(suite, Exercise_1_7_Test);
	return suite;
}
