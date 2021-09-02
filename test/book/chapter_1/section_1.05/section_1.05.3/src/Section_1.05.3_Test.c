/**
 * @file Section_1.05.3_Test.c
 * @brief Tests for section 1.05.3. exercises
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
 * @brief  Test 1 for exercise 1-8 from section 1.05.3
 * Use a empty file as input.
 * 
 * @pre the exercise 1-8 source must exists and be in the expected folder 
 */
void Exercise_1_8_Test1(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.3", "exercise_1-8"};
	char testName[] = "test1_";

	testOnlyMainExercise(tc, testName, exer);
}

void Exercise_1_8_Test2(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.3", "exercise_1-8"};
	char testName[] = "test2_";

	testOnlyMainExercise(tc, testName, exer);
}
/**
 * @brief  Test 1 for exercise 1-9 from section 1.05.3
 * Use a empty file as input.
 * 
 * @pre the exercise 1-9 source must exists and be in the expected folder 
 */
void Exercise_1_9_Test1(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.3", "exercise_1-9"};
	char testName[] = "test1_";

	testOnlyMainExercise(tc, testName, exer);
}
void Exercise_1_9_Test2(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.3", "exercise_1-9"};
	char testName[] = "test2_";

	testOnlyMainExercise(tc, testName, exer);
}
void Exercise_1_9_Test3(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.3", "exercise_1-9"};
	char testName[] = "test3_";

	testOnlyMainExercise(tc, testName, exer);
}
/**
 * @brief  Test 1 for exercise 1-10 from section 1.05.3
 * it use a empty file as input.
 * 
 * @pre the exercise 1-10 source must exists and be in the expected folder.
 * @pre the input1 file of exercise 1-10 must exists, it must content the corresponding input and must be in the expected folder.
 */
void Exercise_1_10_Test1(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.3", "exercise_1-10"};
	char testName[] = "test1_";

	testOnlyMainExercise(tc, testName, exer);
}
void Exercise_1_10_Test2(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.3", "exercise_1-10"};
	char testName[] = "test2_";

	testOnlyMainExercise(tc, testName, exer);
}
void Exercise_1_10_Test3(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.3", "exercise_1-10"};
	char testName[] = "test3_";

	testOnlyMainExercise(tc, testName, exer);
}
void Exercise_1_10_Test4(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.05/section_1.05.3", "exercise_1-10"};
	char testName[] = "test4_";

	testOnlyMainExercise(tc, testName, exer);
}
// ADD CUTEST FUNCTION
CuSuite *Section_1_05_3()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Exercise_1_8_Test1);
	SUITE_ADD_TEST(suite, Exercise_1_8_Test2);

	SUITE_ADD_TEST(suite, Exercise_1_9_Test1);
	SUITE_ADD_TEST(suite, Exercise_1_9_Test2);
	SUITE_ADD_TEST(suite, Exercise_1_9_Test3);

	SUITE_ADD_TEST(suite, Exercise_1_10_Test1);
	SUITE_ADD_TEST(suite, Exercise_1_10_Test2);


	return suite;
}
