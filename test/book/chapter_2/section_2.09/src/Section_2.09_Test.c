/**
 * @file Section_2.09_Test.c
 * @brief Tests for section 2.9. exercises
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-09-29
 */

// LIBRARIES
// Needed to tests
#include "CuTest.h"
#include "testUtil.h"
#include <stddef.h>

// FUNCTIONS

// TEST FUNCTIONS (CUTEST)
/**
 * @brief  Test 1 for exercise 2-6 from section 2.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_2_6_Test(CuTest *tc)
{
    struct dataExercise exer = {"chapter_2", "section_2.09", "exercise_2-6"};

    testOnlyMainExercise(tc, NULL, exer);
}

/**
 * @brief  Test 1 for exercise 2-7 from section 2.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_2_7_Test(CuTest *tc)
{
    struct dataExercise exer = {"chapter_2", "section_2.09", "exercise_2-7"};

    testOnlyMainExercise(tc, NULL, exer);
}

/**
 * @brief  Test 1 for exercise 2-8 from section 2.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_2_8_Test(CuTest *tc)
{
    struct dataExercise exer = {"chapter_2", "section_2.09", "exercise_2-8"};

    testOnlyMainExercise(tc, NULL, exer);
}

// ADD CUTEST FUNCTION
CuSuite *Section_2_09()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, Exercise_2_6_Test);
    SUITE_ADD_TEST(suite, Exercise_2_7_Test);
    SUITE_ADD_TEST(suite, Exercise_2_8_Test);

    return suite;
}
