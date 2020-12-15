#include "List.h"
#include "TestList.h"
#include <stdio.h>

int main()
{
	if (!listTests())
	{
		printf("List tests failed");
		return 1;
	}
	printf("List tests succeed\n");
	
	printf("Please enter numbers: ");
	List* list = makeList();
	while (true)
	{
		int number = 0;
		scanf("%i", &number);
		if (number == 0)
		{
			break;
		}
		addItem(list, number);
	}
	printList(list);

	freeList(&list);
	return 0;
}