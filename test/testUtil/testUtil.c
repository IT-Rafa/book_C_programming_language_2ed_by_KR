/**
 * @file testutil.c
 * @brief Tests utils 
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-10
 */

// LIBRARIES
#include "testUtil.h"

// Needed to use sprintf, fopen, fclose and FILE, NULL definitions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int runExercise(CuTest *tc, char *inputPath, char *outputPath, struct dataExercise exer)
{
    char message[OUTPUTMAX];
    int compileResult = compileExercise(exer);

    if (compileResult == 1) {
        char binPath[PATHMAX];
        getBinPath(binPath, exer);

        if (fileExists(binPath, "r")) {
            // use input if exists
            if (inputPath == NULL || fileExists(inputPath, "r")) {
                char command[COMMANDMAX];
                if (inputPath == NULL) {
                    sprintf(command, "%s > %s", binPath, outputPath);
                }
                else {
                    sprintf(command, "%s < %s > %s", binPath, inputPath, outputPath);
                }

                return (system(command) == 0);
            }
            else {
                sprintf(message, "\n\tFail: File with input to test exercise not found:\n\t%s", inputPath);
                CuAssert(tc, message, 0);
            }
        }
        else {
            sprintf(message, "\n\tFail: Executable file of exercise not found:\n\t%s", binPath);
            CuAssert(tc, message, 0);
        }
    }
    else if (compileResult == -1) {
        // not source
        char srcPath[PATHMAX];
        getSourcePath(srcPath, exer);
        sprintf(message, "\n\tFail: Source file of exercise not found:\n\t%s", srcPath);
        CuAssert(tc, message, 0);
    }
    else {
        // other fail
        sprintf(message, "\n\tFail: Source file can´t be compiled:\n\t");
        CuAssert(tc, message, 0);
    }
    return 0;
}

/**
 * @brief Used to test exercise with only main, with only a exected output.
 * Compile, execute and store the output in a file and  compare its content
 * with the content of other file with the expected output.
 * 
 * @pre Need the source file of exercise and a file with the expected output.
 * 		Both in the right folder's structure
 * @param tc Required by CuTest
 * @param exer data of exercise to find files in folder structure
 */
void testOnlyMainExercise(CuTest *tc, char *testName, struct dataExercise exer)
{
    char testPath[PATHMAX];
    char inputPath[FULLPATHMAX];
    char expectedPath[FULLPATHMAX];
    char outputPath[FULLPATHMAX];

    char actual[OUTPUTMAX];
    char expected[OUTPUTMAX];
    char message[OUTPUTMAX];

    getTestFolder(testPath, exer);

    if (testName == NULL) // Test for no input programs
    {
        *inputPath = '\0';
        sprintf(outputPath, "%s%s", testPath, "output.txt");
        sprintf(expectedPath, "%s%s", testPath, "expected.txt");
        runExercise(tc, NULL, outputPath, exer);
    }
    else // Test for several input programs
    {
        sprintf(inputPath, "%s%s%s", testPath, testName, "input.txt");
        sprintf(outputPath, "%s%s%s", testPath, testName, "output.txt");
        sprintf(expectedPath, "%s%s%s", testPath, testName, "expected.txt");
        runExercise(tc, inputPath, outputPath, exer);
    }

    if (fileExists(outputPath, "r")) {
        if (txtFileToSt(actual, outputPath)) {
            if (fileExists(expectedPath, "r")) {
                if (txtFileToSt(expected, expectedPath)) {
                    CuAssertStrEquals(tc, expected, actual);
                }
                else {

                    sprintf(message, "\n\tFail: Expected content file cannot be read:\n\t%s", expectedPath);
                    CuAssert(tc, message, 0);
                }
            }
            else {
                sprintf(message, "\n\tFail: Expected content file not found:\n\t%s", expectedPath);
                CuAssert(tc, message, 0);
            }
        }
        else {
            sprintf(message, "\n\tFail: Actual output file cannot be read:\n\t%s", expectedPath);
            CuAssert(tc, message, 0);
        }
    }
    else {
        sprintf(message, "\n\tFail: Actual output file not found:\n\t%s", expectedPath);
        CuAssert(tc, message, 0);
    }
}

/**
 * @brief Store the content of a file in a string
 * 
 * @pre the string must be long enough
 * @param st string where the content will be stored
 * @param fileName path of the file
 * @return int return the cant of chars. if it can access to file, return -1
 */
int txtFileToSt(char *st, char *fileName)
{
    FILE *f;
    int c;
    f = fopen(fileName, "r");
    if (f) {
        while ((c = getc(f)) != EOF) {
            *st++ = c;
        }
        *st = '\0';
        return 1;
    }
    else {
        return 0;
    }
}

/**
 * @brief Compile a exercise with only a source file
 * 
 * @pre the source file must exists
 * @pre In Windows cl must be accesible from terminal used.
 * @pre In Linux gcc must be accesible from terminal used.
 * 
 * @param exer data of exercise
 * @return int return 1 if compile ok. 0 if don't exist the source. -1 if compile error.
 */
int compileExercise(struct dataExercise exer)
{
    char srcPath[PATHMAX];
    char binFile[PATHMAX];
    char command[COMMANDMAX];

    getSourcePath(srcPath, exer);

    if (fileExists(srcPath, "r")) {
        mkExerciseBinFolder(exer);
        getBinPath(binFile, exer);

#if defined(_WIN32)
        sprintf(command, "%s %s %s %s", "cl", src, "-Fe", binFile);
#else
        sprintf(command, "%s %s %s %s  > /dev/null", "gcc -w", srcPath, "-o", binFile);
#endif
        return system(command) == 0;
    }
    else { // file not found
        return -1;
    }
    return 0; // other fail
}

/**
 * @brief Get the source path of a exercise and return if it exists.
 * 
 * @param path the string where the path will be stored.
 * @param exer Data of exercise
 * @return int 1 if file exists. 0 if doesn't.
 */
int getSourcePath(char *path, struct dataExercise exer)
{
    char sep[] = SEPARATOR;
    return sprintf(path, "%s%s%s%s%s%s%s%s%s%s%s%s",
                   "book",
                   sep, exer.chapter,
                   sep, exer.section,
                   sep, exer.exercise,
                   sep, "src",
                   sep, exer.exercise, ".c");
}

/**
 * @brief Get the executable path of a exercise and return if it exists.
 * 
 * @param path the string where the path will be stored.
 * @param exer Data of exercise
 * @return int 1 if file exists. 0 if doesn't.
 */
int getBinPath(char *path, struct dataExercise exer)
{
    char sep[] = SEPARATOR;

    return sprintf(path, "%s%s%s%s%s%s%s%s%s%s%s%s",
                   "book",
                   sep, exer.chapter,
                   sep, exer.section,
                   sep, exer.exercise,
                   sep, "bin",
                   sep, exer.exercise, ".exe");
}
/**
 * @brief Get the output path of a exercise execution and return if it exists. For test.
 * 
 * @param path the string where the path will be stored.
 * @param exer Data of exercise
 * @return int 1 if file exists. 0 if doesn't.
 */
int getInputPath(char *inputPath, struct dataExercise exer)
{
    char sep[] = SEPARATOR;
    mkExerciseTestFolder(exer);

    return sprintf(inputPath, "%s%s%s%s%s%s%s%s%s%s%s%s",
                   "test", sep, "book",
                   sep, exer.chapter,
                   sep, exer.section,
                   sep, "docTest",
                   sep, exer.exercise,
                   sep);
    ;
}
/**
 * @brief Get the output path of a exercise execution and return if it exists. For test.
 * 
 * @param path the string where the path will be stored.
 * @param exer Data of exercise
 * @return int 1 if file exists. 0 if doesn't.
 */
int getOutputActualPath(char *path, struct dataExercise exer)
{
    char sep[] = SEPARATOR;
    mkExerciseTestFolder(exer);

    return sprintf(path, "%s%s%s%s%s%s%s%s%s%s%s%s%s",
                   "test", sep, "book",
                   sep, exer.chapter,
                   sep, exer.section,
                   sep, "docTest",
                   sep, exer.exercise,
                   sep, "actual.txt");
}
/**
 * @brief Get the source path of file with the expected output of exercise execution and return if it exists.
 * 
 * @param path The string where the path will be stored.
 * @param exer Data of exercise
 * @return int 1 if file exists. 0 if doesn't.
 */
int getTestFolder(char *path, struct dataExercise exer)
{
    char sep[] = SEPARATOR;

    return sprintf(path, "%s%s%s%s%s%s%s%s%s%s%s%s",
                   "test", sep, "book",
                   sep, exer.chapter,
                   sep, exer.section,
                   sep, "docTest",
                   sep, exer.exercise,
                   sep);
}

/**
 * @brief Create the folder for files used in exercise tests. For test.
 * 
 * @param exer Data of exercise
 * @return int 1 if folder is created. 0 if not.
 */
int mkExerciseTestFolder(struct dataExercise exer)
{
    char sep[] = SEPARATOR;
    char path[PATHMAX];
    sprintf(path, "%s%s%s%s%s%s%s%s%s%s%s",
            "test", sep, "book",
            sep, exer.chapter,
            sep, exer.section,
            sep, "docTest",
            sep, exer.exercise);
    return createFolder(path);
}

/**
 * @brief Create the folder for executable file of exercise.
 * 
 * @param exer Data of exercise
 * @return int 1 if folder is created. 0 if not.
 */
int mkExerciseBinFolder(struct dataExercise exer)
{
    char sep[] = SEPARATOR;
    char path[PATHMAX];
    sprintf(path, "%s%s%s%s%s%s%s%s%s",
            "book",
            sep, exer.chapter,
            sep, exer.section,
            sep, exer.exercise,
            sep, "bin");
    return createFolder(path);
}

/**
 * @brief Create the folder for executable file of exercise. It´s up to system.
 * Work in Windows-Powershell, Windows-cmd, Linux-bash
 * 
 * @param path system path of folder to create
 * @return int 1 if folder is created. 0 if not.
 */
int createFolder(char *path)
{
#if defined(_WIN32)
    CreateDirectory(path, NULL);

#else
    mkdir(path, 0700);
#endif
    return 1;
}

/**
 * @brief Check if a file exist and its permisssion. 
 * 
 * @param path Path to file to check
 * @param permission Permission to check
 * @return int 
 */
int fileExists(char *path, char *permission)
{
    FILE *f;
    if ((f = fopen(path, permission))) {
        fclose(f);
        return 1;
    }
    return 0;
}
