#include "Graph.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct Graph
{
	int **matrix;
	int vertices;
} Graph;

int sizeOfGraph(const Graph* graph)
{
	return graph->vertices;
}

int getValue(const Graph* graph, const int i, const int j)
{
	return graph->matrix[i][j];
}

Graph* makeGraph(const char* filename)
{
	Graph* newGraph = calloc(1, sizeof(Graph));
	FILE* input = fopen(filename, "r");
	if (input == NULL || newGraph == NULL) {
		return NULL;
	}
	int countVertices = 0;
	fscanf(input, "%i", &countVertices);
	newGraph->matrix = calloc(countVertices, sizeof(int*));
	for (int i = 0; i < countVertices; i++)
	{
		newGraph->matrix[i] = calloc(countVertices, sizeof(int));
		for (int j = 0; j < countVertices; j++)
		{
			fscanf(input, "%i", &(newGraph->matrix[i][j]));
		}
	}
	newGraph->vertices = countVertices;
	fclose(input);
	return newGraph;
}

void transitiveClosure(Graph** graph)
{
	const int size = (*graph)->vertices;
	for (int k = 0; k < size; k++)
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				if (i == j)
				{
					continue;
				}
				if ((*graph)->matrix[i][j] != 1 && (*graph)->matrix[i][k] + (*graph)->matrix[k][j] == 2)
				{
					(*graph)->matrix[i][j] = 1;
				}
			}
		}
	}
}

void printGraph(const Graph* graph, const char* filename)
{
	FILE* output = fopen(filename, "w");
	if (output == NULL) {
		return;
	}
	const int size = graph->vertices;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			fprintf(output, "%i ", graph->matrix[i][j]);
		}
		fprintf(output, "\n");
	}
	fclose(output);
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