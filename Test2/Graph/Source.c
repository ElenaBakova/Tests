#include "Graph.h"
#include "Tests.h"
#include <stdio.h>

int main()
{
	if (!tests())
	{
		printf("Tests failed");
		return 1;
	}
	printf("Tests succeed");
	Graph* graph = makeGraph("input.txt");
	transitiveClosure(&graph);
	printGraph(graph, "output.txt");
	deleteGraph(&graph);

	return 0;
}