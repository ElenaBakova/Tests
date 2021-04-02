#include "TestList.h"
#include "List.h"
#include <stdbool.h>
#include <locale.h>

bool testAddItem(void)
{
	List *list = makeList();
	for (int i = 0; i < 6; i++)
	{
		addItem(list, i);
	}

	int k = 0;
	bool result = true;
	for (Position position = getFirst(list); !isEnd(position); position = nextItem(position))
	{
		int current = getValue(position);
		result &= current == k;
		k++;
	}

	freeList(&list);
	return result;
}

bool testRemove(void)
{
	List* list = makeList();
	for (int i = 0; i < 10; i++)
	{
		addItem(list, i);
	}

	bool result = true;
	for (int i = 0; i < 10; i++)
	{
		result &= !removeHeadElement(list);
	}

	freeList(&list);
	return result;
}

bool listTests()
{
	return testAddItem() && testRemove();
}