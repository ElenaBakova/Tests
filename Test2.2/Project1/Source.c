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

int main()
{
	FILE* input = fopen("input.txt", "r");
	if (input == NULL)
	{
		return 1;
	}
	Date *answerDate = calloc(1, sizeof(Date));
	Date *date = calloc(1, sizeof(Date));
	while (!feof(input))
	{
		fscanf(input, "%d%*c%d%*c%d", &date->day, &date->month, &date->year);
		if (compareDate(date, answerDate))
		{
			assignDate(answerDate, date);
		}
	}
	printf("Maximum date: %d.%d.%d", answerDate->day, answerDate->month, answerDate->year);

	free(answerDate);
	answerDate = NULL;
	free(date);
	date = NULL;
	fclose(input);
	return 0;
}