/**
 * @file Section_1.05.4_Test.c
 * @brief Tests for section 1.05.4. exercises
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-10
 */

// LIBRARIES
// Needed to tests
#include "CuTest.h"
#include "testUtil.h"
#include <stddef.h>

// FUNCTIONS

// TEST FUNCTIONS (CUTEST)

/**
 * @brief  Test 1 for exercise 1-11 from section 1.05.4
 * Use a empty file as input.
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_11_Test1(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.4", "exercise_1-11"};
	char testName[] = "test1_";

	testOnlyMainExercise(tc, testName, exer);
}

void Exercise_1_11_Test2(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.4", "exercise_1-11"};
	char testName[] = "test2_";

	testOnlyMainExercise(tc, testName, exer);
}
void Exercise_1_12_Test1(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.4", "exercise_1-12"};
	char testName[] = "test1_";

	testOnlyMainExercise(tc, testName, exer);
}

void Exercise_1_12_Test2(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.4", "exercise_1-12"};
	char testName[] = "test2_";

	testOnlyMainExercise(tc, testName, exer);
}
// ADD CUTEST FUNCTION
CuSuite *Section_1_05_4()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Exercise_1_11_Test1);
	SUITE_ADD_TEST(suite, Exercise_1_11_Test2);

	SUITE_ADD_TEST(suite, Exercise_1_12_Test1);
	SUITE_ADD_TEST(suite, Exercise_1_12_Test2);

	return suite;
}
