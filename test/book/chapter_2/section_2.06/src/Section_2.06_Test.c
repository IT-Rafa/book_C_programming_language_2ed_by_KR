/**
 * @file Section_2.6_Test.c
 * @brief Tests for section 2.6. exercises
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
 * @brief  Test 1 for exercise 2-2 from section 2.6.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_2_02_Test1(CuTest *tc)
{
    struct dataExercise exer = {"chapter_2", "section_2.06", "exercise_2-2"};

    testOnlyMainExercise(tc, "test1_", exer);
}

/**
 * @brief  Test 1 for exercise 2-2 from section 2.6.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_2_02_Test2(CuTest *tc)
{
    struct dataExercise exer = {"chapter_2", "section_2.06", "exercise_2-2"};

    testOnlyMainExercise(tc, "test2_", exer);
}
// ADD CUTEST FUNCTION
CuSuite *Section_2_06()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, Exercise_2_02_Test1);
    SUITE_ADD_TEST(suite, Exercise_2_02_Test2);

    return suite;
}
