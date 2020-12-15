#pragma once
#include "Queue.h"

typedef struct Graph Graph;

// Reads graph from 'filename' file. Creates graph
Graph* makeGraph(const char* filename);

void printGraph(const Graph* graph);

void deleteGraph(Graph** graph);

Queue* bfs(Graph* graph, int start);

Queue* dfs(Graph* graph, int start);