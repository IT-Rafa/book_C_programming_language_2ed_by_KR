/**
 * @file Section_1.5.1_Test.c
 * @brief Tests for section 1.5.1 exercises
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-10
 */

// LIBRARIES
// Needed to tests
#include "..\..\..\..\CuTest\CuTest.h"
#include "..\..\..\..\testUtil\testUtil.h"

// FUNCTIONS

// TEST FUNCTIONS
/**
 * @brief  Test for exercise 1-6 from section 1.5.1
 * Check if output is as the expected
 * 
 * @pre the exercise 1-6 must be compiled
 * @return implicit int - state of program value
 */

void Exercise_1_6_Test(CuTest *tc)
{
	/*
		Enviar input con texto a ejecutable
		Comparar con salida

		Enviar input sin texto a ejecutable
		Comparar con salida
	*/
	char *exePath = "book\\chapter_1\\section_1.05\\section_1.05.1\\exercise_1-6\\bin\\exercise_1-6.exe";
	char *inputTxt = "test\\src\\chapter_1\\section_1.05\\section_1.05.1\\docTest\\textFile.txt";
	char *inputEmpty = "test\\src\\chapter_1\\section_1.05\\section_1.05.1\\docTest\\emptyFile.txt";
	char command[256];
	if (writeInFile(inputTxt, "1234"))
	{
		if (writeInFile(inputEmpty, ""))
		{	
			// Ejecutar archivo usando archivos de texto como entrada
			sprintf(command,"%s %s | %s", "echo ", inputTxt, exePath);
			CuAssert(tc, "No se seguir", 0);
		}
		else
		{
			CuAssert(tc, "Fail to create text file without text", 0);
		}
	}
	else
	{
		CuAssert(tc, "Fail to create text file with text", 0);
	}
}

/**
 * @brief  Test for exercise 1-7 from section 1.5.1
 * Check if output is as the expected
 * 
 * @pre the exercise 1-7 must be compiled
 * @return implicit int - state of program value
 */

void Exercise_1_7_Test(CuTest *tc)
{
	CuAssert(tc, "Pending test 1.7", 0);
}

// ADD CUTEST FUNCTION
CuSuite *Section_1_05_1()
{
	CuSuite *suite = CuSuiteNew();
	SUITE_ADD_TEST(suite, Exercise_1_6_Test);
	SUITE_ADD_TEST(suite, Exercise_1_7_Test);

	return suite;
}
