/**
 * @file Section_1.7_Test.c
 * @brief Tests for section 1.7. exercises
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-09-30
 */

// LIBRARIES
// Needed to tests
#include "CuTest.h"
#include "testUtil.h"
#include <stddef.h>

// FUNCTIONS

// TEST FUNCTIONS (CUTEST)
/**
 * @brief  Test for exercise 1-15 from section 1.7.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 * @return implicit int - state of program value
 */
void Exercise_1_15_Test(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.07", "exercise_1-15"};

	testOnlyMainExercise(tc, NULL, exer);
}

// ADD CUTEST FUNCTION
CuSuite *Section_1_07()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Exercise_1_15_Test);

	return suite;
}
