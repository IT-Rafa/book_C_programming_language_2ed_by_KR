/**
 * @file testutil.c
 * @brief Tests utils 
 * 
 * @author Rafael Martínez Costas (it-rafamartinez@outlook.es)
 * @version 1
 * @date 2021-08-10
 */

// LIBRARIES
// Needed to use printf
#include <stdio.h>
// Neede to run exercise compiled
#include <stdlib.h>
// Needed to create the instruction to system for save output
#include <string.h>
#include <stdio.h>

FILE *stream, *stream2;
/**
 * @brief 
 * 
 * @param exePath 
 * @param exeOutputPath 
 * @param expectedOutputPath 
 * @return int 
 * 		- 0: no exist;
 * 		- 1: exists;
 * 		- 2: exist + read;
 * 		- 3: exist + read + write; 
 * 		- 4: exist + read + write + executable
 */

int exeToFile(const char *exePath, const char *outputPath)
{
	char command[256];
	remove(outputPath);
	sprintf(command, "%s > %s", exePath, outputPath);
	return (system(command) == 0);
}

int fileToExe(const char *outputPath, const char *exePath)
{
	char command[256];
	sprintf(command, "%s > %s", outputPath, exePath);
	return system(command);
}

int fileToSt(const char *fileName, char *st)
{
	/*
		0 read ok but empty
		>0 read ok with content
		-1 fail to read
	*/
	FILE *f;
	int c, count;
	count = 0;
	f = fopen(fileName, "r");
	if (f)
	{
		while ((c = getc(f)) != EOF)
		{
			*st++ = c;
			count++;
		}
		*st = '\0';
		return count;
	}
	else
	{
		return -1;
	}
}

int writeInFile(const char *fileName, const char *text)
{
	errno_t err;
	// Open for write
	err = fopen_s(&stream2, fileName, "w+");
	if (err == 0)
	{
		fprintf_s(stream2, "%s", text);
		return 1;
	}
	return 0;
}
