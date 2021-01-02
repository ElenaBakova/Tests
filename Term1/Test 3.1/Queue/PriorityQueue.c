#include "PriorityQueue.h"
#include <stdlib.h>

const int heapSize = 4e8;

typedef struct HeapElement {
	int value;
	int priority;
} HeapElement;

typedef struct Queue {
	int size;
	int maxSize;
	struct HeapElement** heap;
} Queue;

void swap(int* a, int* b)
{
	const int temp = *a;
	*a = *b;
	*b = temp;
}

Queue* createQueue()
{
	return calloc(1, sizeof(Queue));
}

void siftDown(Queue* queue, int i)
{
	while (2 * i + 1 < queue->size)
	{
		int left = 2 * i + 1;
		int right = 2 * i + 2;
		int maxIndex = left;
		if (right < queue->size && queue->heap[right]->priority > queue->heap[left]->priority)
		{
			maxIndex = right;
		}
		if (queue->heap[i]->priority >= queue->heap[maxIndex]->priority)
		{
			break;
		}
		swap(&queue->heap[i]->priority, &queue->heap[maxIndex]->priority);
		i = maxIndex;
	}
}

void siftUp(Queue* queue, int i)
{
	while (i > 0 && queue->heap[i]->priority > queue->heap[(i - 1) / 2]->priority)
	{
		swap(&queue->heap[i]->priority, &queue->heap[(i - 1) / 2]->priority);
		i = (i - 1) / 2;
	}
}

int dequeue(Queue* queue)
{
	int maximum = queue->heap[0]->value;
	queue->heap[0] = queue->heap[queue->size - 1];
	queue->size--;
	siftUp(queue, 0);
	return maximum;
}

void enqueue(Queue* queue, const int value, const int priority)
{
	if (queue == NULL)
	{
		return;
	}
	if (queue->heap == NULL)
	{
		queue->heap = calloc(heapSize, sizeof(HeapElement*));
	}
	queue->heap[queue->size]->value = value;
	queue->heap[queue->size]->priority = priority;
	queue->size++;
	queue->maxSize = queue->size > queue->maxSize ? queue->size : queue->maxSize;
	siftUp(queue, queue->size - 1);
}

void deleteQueue(Queue** queue)
{
	if (queue == NULL)
	{
		return;
	}
	free((*queue)->heap);
	free(*queue);
	*queue = NULL;
}