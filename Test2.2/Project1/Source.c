#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Date {
	int day;
	int month;
	int year;
} Date;

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
	Date* date = calloc(1, sizeof(Date));
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

bool test()
{
	Date* answer = getMaximumDate("test1.txt");
	bool result = answer->day == 1;
	result &= answer->month == 8;
	result &= answer->year == 2001;
	answer = getMaximumDate("test2.txt");
	result &= answer->day == 9;
	result &= answer->month == 11;
	result &= answer->year == 2009;

	free(answer);
	answer = NULL;
	return result;
}

int main()
{
	if (!test())
	{
		printf("Test failed");
		return 1;
	}
	printf("Test succeed\n");
	Date* answer = getMaximumDate("input.txt");
	printf("Maximum date: %0.2d.%0.2d.%0.4d", answer->day, answer->month, answer->year);

	free(answer);
	answer = NULL;
	return 0;
}