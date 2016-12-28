#include "graph.h"
#include <iostream>

using namespace std;

bool visited[MAXVEX];

void DFS(MGraph* graph, int i)
{
	visited[i] = true;
	printf("%c", graph->vexs[i]);
	int j;
	for (j = 0; j < graph->numVertexes; j++)
	{
		if (graph->arc[i][j] == 1 && !visited[j])
			DFS(graph, j);
	}
}

void DFSTraverse(MGraph* graph)
{
	int i;
	for (i = 0; i < graph->numVertexes; i++)
	{
		visited[i] = false;
	}

	for (i = 0; i < graph->numVertexes; i++)
	{
		if (!visited[i])
			DFS(graph, i);
	}
}

void createMGraph(MGraph* graph)
{
    int i, j, k, w;
    cout << "Input the number of vertexes and edges: " << endl;
    cin >> graph->numVertexes >> graph->numEdges;
    cout << "Input the information of each vertex: " << endl;
    
    for (i = 0; i < graph->numVertexes; i++)
        cin >> graph->vexs[i];
    for (i = 0; i < graph->numVertexes; i++)
        for (j = 0; j < graph->numVertexes; j++)
            graph->arc[i][j] = 0;

    for (k = 0; k < graph->numEdges; k++)
    {
        cout << "Input the index i, j and weight w of edge (vi, vj): " << endl;
        cin >> i >> j >> w;
        graph->arc[i][j] = w;
        graph->arc[j][i] = w;
    }
}

int main()
{
    MGraph graph;
    createMGraph(&graph);
    DFSTraverse(&graph);
    cout << endl;
}