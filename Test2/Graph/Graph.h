#pragma once

typedef struct Graph Graph;

Graph* makeGraph(const char* filename);

void transitiveClosure(Graph** graph);

void printGraph(const Graph* graph);

void deleteGraph(Graph** graph);