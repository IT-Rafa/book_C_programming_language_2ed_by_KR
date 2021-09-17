/**
 * @file Section_1.9_Test.c
 * @brief Tests for section 1.9. exercises
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
 * @brief  Test 1 for exercise 1-16 from section 1.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_16_Test1(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.09", "exercise_1-16"};

    testOnlyMainExercise(tc, "test1_", exer);
}

/**
 * @brief  Test 2 for exercise 1-16 from section 1.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_16_Test2(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.09", "exercise_1-16"};

    testOnlyMainExercise(tc, "test2_", exer);
}

/**
 * @brief  Test 3 for exercise 1-16 from section 1.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_16_Test3(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.09", "exercise_1-16"};

    testOnlyMainExercise(tc, "test3_", exer);
}

/**
 * @brief  Test 1 for exercise 1-17 from section 1.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 * @return implicit int - state of program value
 */
void Exercise_1_17_Test1(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.09", "exercise_1-17"};

    testOnlyMainExercise(tc, "test1_", exer);
}

/**
 * @brief  Test 2 for exercise 1-17 from section 1.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 * @return implicit int - state of program value
 */
void Exercise_1_17_Test2(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.09", "exercise_1-17"};

    testOnlyMainExercise(tc, "test2_", exer);
}

/**
 * @brief  Test 3 for exercise 1-17 from section 1.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 * @return implicit int - state of program value
 */
void Exercise_1_17_Test3(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.09", "exercise_1-17"};

    testOnlyMainExercise(tc, "test3_", exer);
}


/**
 * @brief  Test for exercise 1-18 from section 1.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 * @return implicit int - state of program value
 */
void Exercise_1_18_Test1(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.09", "exercise_1-18"};

    testOnlyMainExercise(tc, "test1_", exer);
}

/**
 * @brief  Test for exercise 1-18 from section 1.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 * @return implicit int - state of program value
 */
void Exercise_1_18_Test2(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.09", "exercise_1-18"};

    testOnlyMainExercise(tc, "test2_", exer);
}

/**
 * @brief  Test for exercise 1-18 from section 1.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 * @return implicit int - state of program value
 */
void Exercise_1_18_Test3(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.09", "exercise_1-18"};

    testOnlyMainExercise(tc, "test3_", exer);
}

/**
 * @brief  Test for exercise 1-19 from section 1.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 * @return implicit int - state of program value
 */
void Exercise_1_19_Test1(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.09", "exercise_1-19"};

    testOnlyMainExercise(tc, "test1_", exer);
}
/**
 * @brief  Test for exercise 1-19 from section 1.9.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 * @return implicit int - state of program value
 */

void Exercise_1_19_Test2(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.09", "exercise_1-19"};

    testOnlyMainExercise(tc, "test2_", exer);
}
// ADD CUTEST FUNCTION
CuSuite *Section_1_09()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, Exercise_1_16_Test1);
    SUITE_ADD_TEST(suite, Exercise_1_16_Test2);
    SUITE_ADD_TEST(suite, Exercise_1_16_Test3);

    SUITE_ADD_TEST(suite, Exercise_1_17_Test1);
    SUITE_ADD_TEST(suite, Exercise_1_17_Test2);
    SUITE_ADD_TEST(suite, Exercise_1_17_Test3);

    SUITE_ADD_TEST(suite, Exercise_1_18_Test1);
    SUITE_ADD_TEST(suite, Exercise_1_18_Test2);
    SUITE_ADD_TEST(suite, Exercise_1_18_Test3);

    SUITE_ADD_TEST(suite, Exercise_1_19_Test1);
    SUITE_ADD_TEST(suite, Exercise_1_19_Test2);

    return suite;
}
