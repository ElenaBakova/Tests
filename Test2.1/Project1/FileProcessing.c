#include "List.h"
#include "FileProcessing.h"
#include <stdio.h>
#include <stdlib.h>

List* readFile(char* filename)
{
	FILE* input = fopen(filename, "r");
	if (input == NULL)
	{
		return NULL;
	}

	List* list = makeList();
	while (!feof(input))
	{
		int number = 0;
		fscanf(input, "%i", &number);
		addItem(list, number);
	}

	fclose(input);
	return list;
}

void printToFile(char* filename, int a, int b, List* list)
{
	FILE* output = fopen(filename, "w");
	if (output == NULL)
	{
		return;
	}

	int current = getTheValue(list);
	fprintf(output, "Numbers less than %i: ", a);
	while (current < a && !isEmpty(list))
	{
		fprintf(output, "%i ", current);
		nextItem(list);
		current = getTheValue(list);
	}
	fprintf(output, "\nNumbers between %i and %i: ", a, b);
	while (current >= a && current <= b && !isEmpty(list))
	{
		fprintf(output, "%i ", current);
		nextItem(list);
		current = getTheValue(list);
	}
	fprintf(output, "\nOther numbers: ");
	while (!isEmpty(list))
	{
		fprintf(output, "%i ", current);
		nextItem(list);
		current = getTheValue(list);
	}

	fclose(output);
}