#pragma once

typedef struct Graph Graph;

int sizeOfGraph(Graph* graph);

Graph* makeGraph(const char* filename);

int getValue(const Graph* graph, const int i, const int j);

void transitiveClosure(Graph** graph);

void printGraph(const Graph* graph);

void deleteGraph(Graph** graph);