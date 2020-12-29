#include "List.h"
#include "TestList.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

List* turnList(List* list)
{
	List* newList = makeList();
	for (Position position = getLast(list); !isEnd(position); position = previousItem(position))
	{
		addItem(newList, getValue(position));
	}
	freeList(&list);
	return newList;
}

List* fillList(List** list, int right, int left, int size)
{
	if (*list != NULL)
	{
		freeList(list);
	}
	*list = makeList();
	for (int i = 0; i < size; i++)
	{
		addItem(*list, rand() % (right - left) + left);
	}
	return *list;
}

bool commandProcessing(const int code, List **list)
{
	int size = 0;
	int left = 0;
	int right = 0;
	switch (code)
	{
	case 0:
		freeList(list);
		return true;
	case 1:
		printf("Please enter size of the list and the range of its values: ");
		scanf("%d%d%d", &size, &left, &right);
		if (right < left)
		{
			printf("Ivalid range\n");
			break;
		}
		*list = fillList(list, right, left, size);
		break;
	case 2:
		*list = turnList(*list);
		break;
	case 3:
		printList(*list);
		printf("\n");
		break;
	default:
		break;
	}
	return false;
}

int main()
{
	if (!listTests())
	{
		printf("List tests failed");
		return 1;
	}
	printf("List tests succeed\n");
	
	srand(time(NULL));
	printf("Commands:\n");
	printf("0 - exit\n");
	printf("1 - fill the list with random numbers\n");
	printf("2 - turn out the list\n");
	printf("3 - print the list\n");
	List* list = NULL;
	while (true)
	{
		int code = 0;
		printf("Enter command code: ");
		scanf("%d", &code);
		if (commandProcessing(code, &list)) {
			return 0;
		}
	}

	return 0;
}