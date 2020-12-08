#include "List.h"
#include "TestList.h"
#include "Tests.h"
#include "FileProcessing.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	if (!listTests())
	{
		printf("List tests failed");
		return 1;
	}
	printf("List tests succeed\n");
	if (!tests())
	{
		printf("Tests failed");
		return 1;
	}
	printf("Tests succeed\n");


	int a = 0;
	int b = 0;
	printf("Please enter a and b - integers: ");
	scanf("%i %i", &a, &b);
	List* list = readFile("input.txt");
	printToFile("output.txt", a, b, list);

	freeList(&list);
	return 0;
}