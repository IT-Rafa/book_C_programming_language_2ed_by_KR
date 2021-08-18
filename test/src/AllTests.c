#include <stdio.h>
#include "CuTest/CuTest.h"

CuSuite* Section_1_02();
CuSuite* Section_1_03();
CuSuite* Section_1_05_1();

void RunAllTests(void)
{
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();

	CuSuiteAddSuite(suite, Section_1_02());
	CuSuiteAddSuite(suite, Section_1_03());
	CuSuiteAddSuite(suite, Section_1_05_1());
	
	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int main(void)
{
	RunAllTests();
}
