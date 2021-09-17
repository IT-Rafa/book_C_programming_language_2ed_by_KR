/**
 * @file Section_2.1_Test.c
 * @brief Tests for section 2.1. exercises
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
 * @brief  Test 1 for exercise 2-1 from section 2.2.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_2_01_Test1(CuTest *tc)
{
    struct dataExercise exer = {"chapter_2", "section_2.02", "exercise_2-1"};

    testOnlyMainExercise(tc, "test1_", exer);
}

// ADD CUTEST FUNCTION
CuSuite *Section_2_02()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, Exercise_2_01_Test1);

    return suite;
}
