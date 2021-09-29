/**
 * @file Section_x.x_Test.c
 * @brief Tests for section x.x. exercises
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
 * @brief  Test 1 for exercise x.x from section x.x.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_x_x_Test(CuTest *tc)
{
    struct dataExercise exer = {"chapter_x", "section_x.xx", "exercise_x-x"};

    testOnlyMainExercise(tc, NULL, exer);
}

// TEST FUNCTIONS (CUTEST)
/**
 * @brief  Test 1 for exercise x.x from section x.x.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_x_x_Test1(CuTest *tc)
{
    struct dataExercise exer = {"chapter_x", "section_x.xx", "exercise_x-x"};

    testOnlyMainExercise(tc, "test1_", exer);
}
// ADD CUTEST FUNCTION
CuSuite *Section_x_xx()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, Exercise_x_x_Test);
    SUITE_ADD_TEST(suite, Exercise_x_x_Test1);
    return suite;
}
