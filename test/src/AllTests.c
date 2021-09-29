#include <stdio.h>
#include "CuTest.h"

CuSuite *Section_1_02();
CuSuite *Section_1_03();
CuSuite *Section_1_05_1();
CuSuite *Section_1_05_3();
CuSuite *Section_1_05_4();
CuSuite *Section_1_06();
CuSuite *Section_1_07();
CuSuite *Section_1_09();
CuSuite *Section_1_10();

CuSuite *Section_2_02();
CuSuite *Section_2_06();
CuSuite *Section_2_07();
CuSuite *Section_2_08();
CuSuite *Section_2_09();

void RunAllTests(void)
{
	CuString *output = CuStringNew();
	CuSuite *suite = CuSuiteNew();

	CuSuiteAddSuite(suite, Section_1_02());
	CuSuiteAddSuite(suite, Section_1_03());
	CuSuiteAddSuite(suite, Section_1_05_1());
	CuSuiteAddSuite(suite, Section_1_05_3());
	CuSuiteAddSuite(suite, Section_1_05_4());
	CuSuiteAddSuite(suite, Section_1_06());
	CuSuiteAddSuite(suite, Section_1_07());
	CuSuiteAddSuite(suite, Section_1_09());
	CuSuiteAddSuite(suite, Section_1_10());

	CuSuiteAddSuite(suite, Section_2_02());
	CuSuiteAddSuite(suite, Section_2_06());
	CuSuiteAddSuite(suite, Section_2_07());
	CuSuiteAddSuite(suite, Section_2_08());
	CuSuiteAddSuite(suite, Section_2_09());


	CuSuiteRun(suite);
	CuSuiteSummary(suite, output);
	CuSuiteDetails(suite, output);
	printf("%s\n", output->buffer);
}

int main(void)
{
	RunAllTests();
}
