#pragma once
#include <stdbool.h>

typedef struct List List;

// Returns value of the head item
int getTheValue(List *list);

// Returns frequency of the head item
int getFrequency(List* list);

// Changes pointer to the next item
void nextItem(List* list);

// Makes a new empty list
List* makeList(void);

// Add new element to its position or increase element frequency if it's already in the list
void addItem(List* list, const int value);

// Removes elment from the list. Recieves value of the element
bool removeValue(List* list, const int value);

// Returns 'true' if list is emty
bool isEmpty(List* list);

// Removes all list
void freeList(List** list);

// Prints all list
void printList(List* list);