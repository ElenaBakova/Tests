#include "Date.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool test()
{
	Date* answer = getMaximumDate("test1.txt");
	bool result = answer->day == 1;
	result &= answer->month == 8;
	result &= answer->year == 2001;
	free(answer);
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