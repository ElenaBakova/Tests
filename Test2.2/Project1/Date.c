#include "Date.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool isGreaterDate(Date* first, Date* second)
{
	bool result = first->year > second->year || first->year == second->year && first->month > second->month;
	result |= first->year == second->year && first->month == second->month && first->day > second->day;
	return result;
}

void assignDate(Date* destination, Date* source)
{
	destination->year = source->year;
	destination->month = source->month;
	destination->day = source->day;
}

Date* getMaximumDate(char* filename)
{
	FILE* input = fopen(filename, "r");
	if (input == NULL)
	{
		return NULL;
	}
	Date* answerDate = calloc(1, sizeof(Date));
	if (answerDate == NULL)
	{
		fclose(input);
		return NULL;
	}
	Date* date = calloc(1, sizeof(Date));
	if (date == NULL)
	{
		free(answerDate);
		fclose(input);
		return NULL;
	}
	while (!feof(input))
	{
		fscanf(input, "%d%*c%d%*c%d", &date->day, &date->month, &date->year);
		if (isGreaterDate(date, answerDate))
		{
			assignDate(answerDate, date);
		}
	}
	free(date);
	date = NULL;
	fclose(input);
	return answerDate;
}