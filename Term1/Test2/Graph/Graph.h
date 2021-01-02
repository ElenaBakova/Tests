#pragma once

typedef struct Graph Graph;

// Returns size of graph
int sizeOfGraph(const Graph* graph);

// Returns value in [i][j] cell
int getValue(const Graph* graph, const int i, const int j);

// Reads matrix from file and creates graph
Graph* makeGraph(const char* filename);

// Modifying graph -- makes transitive closure of it
void transitiveClosure(Graph** graph);

// Prints graph to the file
void printGraph(const Graph* graph, const char* filename);

// Deletes graph 
void deleteGraph(Graph** graph);