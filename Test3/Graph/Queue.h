#pragma once
#include <stdbool.h>

typedef struct Queue Queue;

// Returns 'true' if queue is empty
bool isEmpty(Queue* queue);

// Add new item into the tail of the queue
void enqueue(Queue* queue, int value);

// Deletes item from head, returns its value
int dequeue(Queue* queue);

// Remove all queue
void deleteQueue(Queue** queue);

// Creates new emty queue 
Queue* initQueue(void);