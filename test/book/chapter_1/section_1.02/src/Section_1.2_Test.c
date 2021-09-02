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
#include "CuTest.h"
#include "testUtil.h"
#include <stddef.h>

// FUNCTIONS

// TEST FUNCTIONS (CUTEST)
/**
 * @brief  Test for exercise 1-3 from section 1.2.
 * Check if output is as the expected
 * 
 * @pre the exercise 1-3 source must exists and be in the expected folder 
 * @return implicit int - state of program value
 */
void Exercise_1_3_Test(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.02", "exercise_1-3"};

	testOnlyMainExercise(tc, NULL, exer);
}

/**
 * @brief  Test for exercise 1-4 from section 1.2.
 * Check if output is as the expected
 * 
 * @pre the exercise 1-4 source must exists and be in the expected folder 
 * @return implicit int - state of program value
 */
void Exercise_1_4_Test(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.02", "exercise_1-4"};

	testOnlyMainExercise(tc, NULL, exer);
}

// ADD CUTEST FUNCTION
CuSuite *Section_1_02()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Exercise_1_3_Test);
	SUITE_ADD_TEST(suite, Exercise_1_4_Test);
	return suite;
}
