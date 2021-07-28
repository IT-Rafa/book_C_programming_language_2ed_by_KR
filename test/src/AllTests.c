#include <stdio.h>

#include "CuTest/CuTest.h"

CuSuite* StrUtilGetSuite();
CuSuite* MainGetSuite();

void RunAllTests(void)
{
	CuString *output = CuStringNew();
	CuSuite* suite = CuSuiteNew();

	CuSuiteAddSuite(suite, StrUtilGetSuite());
	CuSuiteAddSuite(suite, MainGetSuite());

	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int main(void)
{
	RunAllTests();
}
