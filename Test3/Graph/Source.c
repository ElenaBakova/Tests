#include "Queue.h"
#include "Graph.h"
#include <stdio.h>

int main()
{
	Graph* graph = makeGraph("input.txt");
	printGraph(graph);
	Queue* queue = bfs(graph, 0);
	while (!isEmpty(queue))
	{
		printf("%i ", dequeue(queue) + 1);
	}
	printf("\n");
	
	deleteQueue(&queue);
	deleteGraph(&graph);
	return 0;
}