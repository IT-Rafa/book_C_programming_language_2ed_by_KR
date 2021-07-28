#include "CuTest/CuTest.h"

#include <stdio.h>
void TestOutputMain(CuTest *tc)
{
	const char *fileName = "actual.txt";
	FILE *file;
	char actual[1000];
	char expected[1000] = "hello, world\n";

	// run main and store to file
	char callSystem[1000];
	sprintf(callSystem, ".\\bin\\helloWorld.exe > %s", fileName);
	system(callSystem);
	// Read file and store in string
	file = fopen(fileName, "r");
	fgets(actual, 1000, file);
	fclose(file);
	remove(fileName);
	CuAssertStrEquals(tc, expected, actual);
}

CuSuite *MainGetSuite()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestOutputMain);
	return suite;
}