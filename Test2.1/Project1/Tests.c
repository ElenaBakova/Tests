#include "Tests.h"
#include "List.h"
#include "FileProcessing.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool checkPrint(void)
{
	FILE* output = fopen("Test1.1.txt", "r");
	if (output == NULL)
	{
		return false;
	}
	FILE* answer = fopen("Answer1.txt", "r");
	if (output == NULL)
	{
		return false;
	}

	bool result = true;
	char outputString[1000] = "";
	char answerString[1000] = "";
	while (!feof(output) && !feof(answer))
	{
		fgets(outputString, 1000, output);
		fgets(answerString, 1000, answer);
		result &= strcmp(outputString, answerString) == 0;
	}

	fclose(output);
	fclose(answer);
	return result;
}

bool tests()
{
	int a = 1;
	int b = 90;
	List* list = readFile("Test1.txt");
	printToFile("Test1.1.txt", a, b, list);

	freeList(&list);
	return checkPrint();
}