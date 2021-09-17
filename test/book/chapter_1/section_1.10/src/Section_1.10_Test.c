/**
 * @file Section_1.10_Test.c
 * @brief Tests for section 1.10. exercises
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
 * @brief  Test 1 for exercise 1-20 from section 1.10.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_20_Test1(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.10", "exercise_1-20"};

    testOnlyMainExercise(tc, "test1_", exer);
}

/**
 * @brief  Test 2 for exercise 1-20 from section 1.10.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_20_Test2(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.10", "exercise_1-20"};

    testOnlyMainExercise(tc, "test2_", exer);
}

/**
 * @brief  Test 1 for exercise 1-21 from section 1.10.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_21_Test1(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.10", "exercise_1-21"};

    testOnlyMainExercise(tc, "test1_", exer);
}

/**
 * @brief  Test 2 for exercise 1-21 from section 1.10.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_21_Test2(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.10", "exercise_1-21"};

    testOnlyMainExercise(tc, "test2_", exer);
}

/**
 * @brief  Test 1 for exercise 1-22 from section 1.10.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_22_Test1(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.10", "exercise_1-22"};

    testOnlyMainExercise(tc, "test1_", exer);
}

/**
 * @brief  Test 2 for exercise 1-22 from section 1.10.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_22_Test2(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.10", "exercise_1-22"};

    testOnlyMainExercise(tc, "test2_", exer);
}

/**
 * @brief  Test 1 for exercise 1-23 from section 1.10.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_23_Test1(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.10", "exercise_1-23"};

    testOnlyMainExercise(tc, "test1_", exer);
}

/**
 * @brief  Test 2 for exercise 1-23 from section 1.10.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_23_Test2(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.10", "exercise_1-23"};

    testOnlyMainExercise(tc, "test2_", exer);
}

/**
 * @brief  Test 3 for exercise 1-23 from section 1.10.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_23_Test3(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.10", "exercise_1-23"};

    testOnlyMainExercise(tc, "test3_", exer);
}

/**
 * @brief  Test 3 for exercise 1-23 from section 1.10.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_23_Test4(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.10", "exercise_1-23"};

    testOnlyMainExercise(tc, "test4_", exer);
}
/**
 * @brief  Test 1 for exercise 1-24 from section 1.10.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_24_Test1(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.10", "exercise_1-24"};

    testOnlyMainExercise(tc, "test1_", exer);
}


/**
 * @brief  Test 2 for exercise 1-24 from section 1.10.
 * Check if output is as the expected
 * 
 * @pre the exercise source file must exists and be in the expected folder 
 */
void Exercise_1_24_Test2(CuTest *tc)
{
    struct dataExercise exer = {"chapter_1", "section_1.10", "exercise_1-24"};

    testOnlyMainExercise(tc, "test2_", exer);
}


// ADD CUTEST FUNCTION
CuSuite *Section_1_10()
{
    CuSuite *suite = CuSuiteNew();
    SUITE_ADD_TEST(suite, Exercise_1_20_Test1);
    SUITE_ADD_TEST(suite, Exercise_1_20_Test2);

    SUITE_ADD_TEST(suite, Exercise_1_21_Test1);
    SUITE_ADD_TEST(suite, Exercise_1_21_Test2);

    SUITE_ADD_TEST(suite, Exercise_1_22_Test1);
    SUITE_ADD_TEST(suite, Exercise_1_22_Test2);

    SUITE_ADD_TEST(suite, Exercise_1_23_Test1);
    SUITE_ADD_TEST(suite, Exercise_1_23_Test2);
    SUITE_ADD_TEST(suite, Exercise_1_23_Test3);
    SUITE_ADD_TEST(suite, Exercise_1_23_Test4);

    SUITE_ADD_TEST(suite, Exercise_1_24_Test1);
    SUITE_ADD_TEST(suite, Exercise_1_24_Test2);

    return suite;
}
