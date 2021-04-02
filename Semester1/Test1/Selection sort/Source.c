#include <stdio.h>
#include <limits.h>

void sort(int array[], const int size)
{
	for (int i = 0; i < size; i++)
	{
		int minIndex = 0;
		for (int j = i; j < size; j++)
		{
			if (array[minIndex] > array[j])
			{
				array[minIndex] = array[j];
				minIndex = j;
			}
		}
		const int temp = array[minIndex];
		array[minIndex] = array[i];
		array[i] = temp;
	}
}

int main()
{
	//Tests: (size = 4; array = 5 10 -5 16)
	// (size = 1; array = 44)
	// (size = 5; array = -5 -5 -5 -5 -5)
	// (size = 3; array = 1 2 3)
	int array[10];
	int size = 10;
	printf("Please enter size of array and array ");
	scanf("%i", &size);
	for (int i = 0; i < size; i++)
	{
		scanf("%i", &array[i]);
	}
	sort(array, size);
	printf("Sorted array: ");
	for (int i = 0; i < size; i++)
	{
		printf("%i ", array[i]);
	}

	return 0;
}