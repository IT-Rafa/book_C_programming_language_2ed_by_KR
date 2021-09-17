/**
 * @file Section_1.6_Test.c
 * @brief Tests for section 1.6. exercises
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
 * @brief  Test for exercise 1-5 from section 1.13.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 * @return implicit int - state of program value
 */
void Exercise_1_13_hor_Test1(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.06", "exercise_1-13_hor"};
	char testName[] = "test1_";

	testOnlyMainExercise(tc, testName, exer);
}

void Exercise_1_13_hor_Test2(CuTest *tc)

{
	struct dataExercise exer = {"chapter_1", "section_1.06", "exercise_1-13_hor"};
	char testName[] = "test2_";

	testOnlyMainExercise(tc, testName, exer);
}

void Exercise_1_13_ver_Test1(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.06", "exercise_1-13_ver"};
	char testName[] = "test1_";

	testOnlyMainExercise(tc, testName, exer);
}

void Exercise_1_13_ver_Test2(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.06", "exercise_1-13_ver"};
	char testName[] = "test2_";

	testOnlyMainExercise(tc, testName, exer);
}

void Exercise_1_14_hor_Test1(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.06", "exercise_1-14_hor"};
	char testName[] = "test1_";

	testOnlyMainExercise(tc, testName, exer);
}
void Exercise_1_14_hor_Test2(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.06", "exercise_1-14_hor"};
	char testName[] = "test2_";

	testOnlyMainExercise(tc, testName, exer);
}
void Exercise_1_14_ver_Test1(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.06", "exercise_1-14_ver"};
	char testName[] = "test1_";

	testOnlyMainExercise(tc, testName, exer);
}

void Exercise_1_14_ver_Test2(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.06", "exercise_1-14_ver"};
	char testName[] = "test2_";

	testOnlyMainExercise(tc, testName, exer);
}

// ADD CUTEST FUNCTION
CuSuite *Section_1_06()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Exercise_1_13_hor_Test1);
	SUITE_ADD_TEST(suite, Exercise_1_13_hor_Test2);
	SUITE_ADD_TEST(suite, Exercise_1_13_ver_Test1);
	SUITE_ADD_TEST(suite, Exercise_1_13_ver_Test2);

	SUITE_ADD_TEST(suite, Exercise_1_14_hor_Test1);
	SUITE_ADD_TEST(suite, Exercise_1_14_hor_Test2);

	SUITE_ADD_TEST(suite, Exercise_1_14_ver_Test1);
	SUITE_ADD_TEST(suite, Exercise_1_14_ver_Test2);

	return suite;
}
