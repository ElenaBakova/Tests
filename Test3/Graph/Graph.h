#pragma once
#include "Queue.h"

typedef struct Graph Graph;

// Reads graph from 'filename' file. Creates graph
Graph* makeGraph(const char* filename);

// prints adjacency matrix
void printGraph(const Graph* graph);

// delete all graph
void deleteGraph(Graph** graph);

// Explores all of the graph nodes, returns path
Queue* bfs(Graph* graph, int start);