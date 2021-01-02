#include "Tests.h"
#include "Graph.h"
#include <stdbool.h>

bool compareGraph(Graph* graph)
{
	Graph* answerGraph = makeGraph("TestAnswer.txt");
	const int size = sizeOfGraph(graph);
	bool result = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result &= getValue(graph, i, j) == getValue(answerGraph, i, j);
		}
	}
	deleteGraph(&answerGraph);
	return result;
}

bool tests()
{
	Graph* graph = makeGraph("Tests.txt");
	transitiveClosure(&graph);
	bool result = compareGraph(graph);
	
	deleteGraph(&graph);
	return result;
}