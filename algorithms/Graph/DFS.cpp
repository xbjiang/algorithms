#include "graph.h"
#include <stdio.h>
bool visited[MAXVEX];

void GFS(MGraph graph, int i)
{
	visited[i] = true;
	printf("%c", graph.vexs[i]);
	int j;
	for (j = 0; j < graph.numVertexes; j++)
	{
		if (graph.arc[i][j] == 1 && !visited[j])
			GFS(graph, j);
	}
}

void GFSTraverse(MGraph graph)
{
	int i;
	for (i = 0; i < graph.numVertexes; i++)
	{
		visited[i] = false;
	}

	for (i = 0; i < graph.numVertexes; i++)
	{
		if (!visited[i])
			GFS(graph, i);
	}
}