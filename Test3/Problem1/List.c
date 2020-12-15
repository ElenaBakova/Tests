#include "List.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct ListElement {
	int value;
	int frequency;
	struct ListElement* next;
} ListElement;

typedef struct List {
	ListElement* head;
} List;

bool isEmpty(List* list)
{
	return (list == NULL || list->head == NULL);
}

int getTheValue(List *list)
{
	if (isEmpty(list))
	{
		return -INT_MAX;
	}
	return list->head->value;
}

int getFrequency(List* list)
{
	if (isEmpty(list))
	{
		return -INT_MAX;
	}
	return list->head->frequency;
}


void nextItem(List* list)
{
	if (!isEmpty(list))
	{
		list->head = list->head->next;
	}
}

List* makeList(void)
{
	return calloc(1, sizeof(List));
}

void addItem(List* list, const int value)
{
	if (list == NULL)
	{
		list = makeList();
	}
	ListElement* newElement = malloc(sizeof(ListElement));
	if (newElement == NULL)
	{
		return;
	}
	if (list->head == NULL)
	{
		newElement->value = value;
		newElement->frequency = 1;
		newElement->next = NULL;
		list->head = newElement;
		return;
	}
	ListElement* pointer = list->head;
	while (pointer->next != NULL && pointer->next->value <= value)
	{
		pointer = pointer->next;
	}
	if (pointer->value == value)
	{
		pointer->frequency++;
		free(newElement);
		return;
	}
	newElement->value = value;
	newElement->frequency = 1;
	if (pointer == list->head && pointer->value > value)
	{
		newElement->next = list->head;
		list->head = newElement;
		return;
	}
	newElement->next = pointer->next;
	pointer->next = newElement;
}

bool removeValue(List* list, const int value)
{
	if (isEmpty(list))
	{
		return true;
	}
	ListElement* pointer = list->head;
	if (pointer->value == value)
	{
		list->head = list->head->next;
		free(pointer);
		return false;
	}
	while (pointer->next != NULL && pointer->next->value != value)
	{
		pointer = pointer->next;
	}
	if (pointer->next == NULL && pointer->value != value)
	{
		return true;
	}
	if (pointer->next != NULL) 
	{
		ListElement* oldElement = pointer->next;
		pointer->next = pointer->next->next;
		free(oldElement);
	}
	else 
	{
		pointer = NULL;
	}
	return false;
}

void freeList(List** list)
{
	while (!isEmpty(*list))
	{
		removeValue(*list, (*list)->head->value);
	}
	free(*list);
	*list = NULL;
}

void printList(List *list)
{
	if (isEmpty(list))
	{
		printf("List is empty\n");
		return;
	}
	printf("Number - frequency\n");
	ListElement* pointer = list->head;
	while (pointer != NULL)
	{
		printf("%i - %i\n", pointer->value, pointer->frequency);
		pointer = pointer->next;
	}
}
