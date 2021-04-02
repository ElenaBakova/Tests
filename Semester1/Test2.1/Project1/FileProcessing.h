#pragma once
#include "List.h"

// Reads integers from file. Returns sorted list
List* readFile(char* filename);

// Prints to file numbers less than a, between a and b and others
void printToFile(char* filename, int a, int b, List* list);