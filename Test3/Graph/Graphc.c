#include "Graph.h"
#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
	int **matrix;
	int vertices;
} Graph;

Graph* makeGraph(const char* filename)
{
	FILE* input = fopen(filename, "r");
	if (input == NULL)
	{
		return NULL;
	}
	int countVertices = 0;
	int countEdges = 0;
	fscanf(input, "%d%d", &countVertices, &countEdges);
	int** array = calloc(countEdges, sizeof(int*));
	for (int i = 0; i < countVertices; i++)
	{
		array[i] = calloc(countVertices, sizeof(int));
		for (int j = 0; j < countVertices; j++)
		{
			fscanf(input, "%i", &array[i][j]);
		}
	}

	Graph* newGraph = calloc(1, sizeof(Graph));
	if (newGraph == NULL)
	{
		fclose(input);
		return NULL;
	}
	newGraph->matrix = calloc(countVertices, sizeof(int*));
	for (int i = 0; i < countVertices; i++)
	{
		newGraph->matrix[i] = calloc(countVertices, sizeof(int));
	}
	for (int i = 0; i < countEdges; i++)
	{
		int first = 0;
		int second = 0;
		for (int j = 0; j < countVertices; j++)
		{
			if (array[j][i] == 1 && first == 0)
			{
				first = j;
			}
			else if (array[j][i] == 1 && first == 1)
			{
				newGraph->matrix[j][first] = 1;
				newGraph->matrix[first][j] = 1;
				second = j;
			}
		}
		if (first == 1 && second == 0)
		{
			newGraph->matrix[first][first] = 1;
		}
	}
	newGraph->vertices = countVertices;
	fclose(input);
	return newGraph;
}

void printGraph(const Graph* graph)
{
	const int size = graph->vertices;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			/*if (graph->matrix[i][j] == 1) {
				printf("%i -- %i\n", i, j);
			}*/
			printf("%i ", graph->matrix[i][j]);
		}
		printf("\n");
	}
}

void deleteGraph(Graph** graph)
{
	for (int i = 0; i < (*graph)->vertices; i++)
	{
		free((*graph)->matrix[i]);
	}
	free((*graph)->matrix);
	free(*graph);
	*graph = NULL;
}

Queue* bfs(Graph* graph, int start)
{
	Queue* queue = initQueue();
	Queue* pathQueue = initQueue();
	enqueue(queue, start);
	bool* used = calloc(graph->vertices, sizeof(bool));
	while (!isEmpty(queue))
	{
		int v = dequeue(queue);
		if (used[v]) {
			continue;
		}
		used[v] = true;
		enqueue(pathQueue, v);
		for (int j = 0; j < graph->vertices; j++)
		{
			if (graph->matrix[v][j] == 1 && !used[j])
			{
				enqueue(queue, j);
			}
		}
	}
	free(used);
	deleteQueue(&queue);
	return pathQueue;
}
