#include "Graph.h"
#include <stdio.h>

int main()
{
	Graph* graph = makeGraph("input.txt");
	transitiveClosure(&graph);
	printGraph(graph, "output.txt");
	deleteGraph(&graph);

	return 0;
}