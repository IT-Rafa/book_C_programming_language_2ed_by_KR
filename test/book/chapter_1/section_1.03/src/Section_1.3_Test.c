/**
 * @file Section_1.3_Test.c
 * @brief Tests for section 1.3. exercises
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
 * @brief  Test for exercise 1-5 from section 1.3.
 * Check if output is as the expected
 * 
 * @pre the exercise 1-5 source must exists and be in the expected folder 
 * @return implicit int - state of program value
 */
void Exercise_1_5_Test(CuTest *tc)
{
	struct dataExercise exer = {"chapter_1", "section_1.03", "exercise_1-5"};

	testOnlyMainExercise(tc, NULL,  exer);
}

// ADD CUTEST FUNCTION
CuSuite *Section_1_03()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Exercise_1_5_Test);
	return suite;
}
