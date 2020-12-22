#pragma once
#include <stdbool.h>

typedef struct Date {
	int day;
	int month;
	int year;
} Date;

// Returns true if first date greater than second
bool compareDate(Date* first, Date* second);

// Assigns source to the destination
void assignDate(Date* destination, Date* source);

// Reads date from file, returns maximum of them
Date* getMaximumDate(char* filename);