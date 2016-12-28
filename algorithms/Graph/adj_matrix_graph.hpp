#include <iostream>
#include <assert.h>
#include <unordered_map>

#ifndef ADJ_MATRIX_GRAPH_HPP
#define ADJ_MATRIX_GRAPH_HPP

class AdjMatrixGraph
{
public:
    typedef char VertexType;
    typedef int EdgeType;
    AdjMatrixGraph(int v);
    ~AdjMatrixGraph();
    int addEdge(int i, int j);
    void DFSTraverse();
	int getVertexId(VertexType vex);
private:
    int numVertex;
    int numEdge;
    VertexType* vexs;
	std::unordered_map<VertexType, int> vex2idx;
    EdgeType** arc;
    bool* visited;

    void DFS(int i);
};

AdjMatrixGraph::AdjMatrixGraph(int v) : numVertex(v), numEdge(0)
{
    arc = new EdgeType*[v];
    for (int i = 0; i < v; i++)
        arc[i] = new EdgeType[v]();

    visited = new bool[v]();

    vexs = new VertexType[v];
    std::cout << "Input the information for each vertex: " << std::endl;
	for (int i = 0; i < v; i++)
	{
		std::cin >> vexs[i];
		vex2idx[vexs[i]] = i;
	}
}

AdjMatrixGraph::~AdjMatrixGraph()
{
    for (int i = 0; i < numVertex; i++)
        delete[] arc[i];
    delete[] arc;
    delete[] vexs;
    delete[] visited;
}

int AdjMatrixGraph::addEdge(int i, int j)
{
    assert(i >= 0 && i < numVertex);
    assert(j >= 0 && j < numVertex);
    if (arc[i][j] == 1) return 1;
    arc[i][j] = 1;
    arc[j][i] = 1;
    numEdge++;
    return 0;
}

int AdjMatrixGraph::getVertexId(VertexType vex)
{
	return vex2idx[vex];
}

void AdjMatrixGraph::DFSTraverse()
{
    for (int i = 0; i < numVertex; i++)
        visited[i] = false;
    for (int i = 0; i < numVertex; i++)
        if (!visited[i])
            DFS(i);
    std::cout << std::endl;
}

void AdjMatrixGraph::DFS(int i)
{
    visited[i] = true;
    std::cout << vexs[i] << " ";
    for (int j = 0; j < numVertex; j++)
        if (arc[i][j] == 1 && !visited[j])
            DFS(j);
}
#endif ADJ_MATRIX_GRAPH_HPP