#include "CuTest.h"
#if defined(_WIN32)
#define SEPARATOR "\\"
#include <windows.h>
#else
#define SEPARATOR "/"
#include <sys/stat.h>
#include <sys/types.h>
#endif
//GENERAL 
// SYMBOLIC CONSTANTS
#define NAMEFILEMAX 50
#define PATHMAX 250
#define FULLPATHMAX (PATHMAX + NAMEFILEMAX)
#define COMMANDMAX 1024
#define OUTPUTMAX 1024
#define SEPARATORMAX 3
/**
 * @enum store the referencial data to identify a exercise 
 */
struct dataExercise
{
    char chapter[NAMEFILEMAX];
    char section[NAMEFILEMAX];
    char exercise[NAMEFILEMAX];
};
int runExercise(CuTest *tc, char *inputPath, char *outputPath, struct dataExercise exer);

void testOnlyMainExercise(CuTest *tc, char *testName, struct dataExercise exer);
int txtFileToSt(char *st, char *fileName);
int compileExercise(struct dataExercise exer);
int getSourcePath(char *st, struct dataExercise exer);
int getBinPath(char *st, struct dataExercise exer);
int getInputPath(char *inputPath, struct dataExercise exer);
int getTestFolder(char *st, struct dataExercise exer);
int mkExerciseBinFolder(struct dataExercise exer);
int mkExerciseTestFolder(struct dataExercise exer);
int createFolder(char *path);
int fileExists(char *path, char *permission);
