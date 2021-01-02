#pragma once

typedef struct Queue Queue;

// Creates new emty queue
Queue* createQueue();

// Adds new element to the queue
void enqueue(Queue* queue, const int value, const int priority);

// Returns value of the first element and deletes it
int dequeue(Queue* queue);