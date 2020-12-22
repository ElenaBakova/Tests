#include "Date.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

bool compareDate(Date* first, Date* second)
{
	return first->year > second->year || first->year == second->year && first->month > second->month || first->year == second->year && first->month == second->month && first->day > second->day;
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
		if (compareDate(date, answerDate))
		{
			assignDate(answerDate, date);
		}
	}
	free(date);
	date = NULL;
	fclose(input);
	return answerDate;
}