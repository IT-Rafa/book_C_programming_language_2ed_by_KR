/**
 * @file Section_2.7_Test.c
 * @brief Tests for section 2.7. exercises
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
 * @brief  Test 1 for exercise 2-3 from section 2.7.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_2_03_Test(CuTest *tc)
{
    struct dataExercise exer = {"chapter_2", "section_2.07", "exercise_2-3"};

    testOnlyMainExercise(tc, NULL, exer);
}

// ADD CUTEST FUNCTION
CuSuite *Section_2_07()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, Exercise_2_03_Test);

    return suite;
}
