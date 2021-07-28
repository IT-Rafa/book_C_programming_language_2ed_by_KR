#include "CuTest/CuTest.h"
#include "../../src/includes/createString.h"

void TestCreateString(CuTest *tc)
{
	char *actual = createString();
	char *expected = "hello, world";
	CuAssertStrEquals(tc, expected, actual);
}

CuSuite *StrUtilGetSuite()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, TestCreateString);
	return suite;
}