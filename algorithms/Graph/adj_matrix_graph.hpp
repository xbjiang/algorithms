#include "Graph.h"
#include <iostream>
#include <assert.h>
#include <unordered_map>
#include <queue>
#include <algorithm>

#ifndef ADJ_MATRIX_GRAPH_HPP
#define ADJ_MATRIX_GRAPH_HPP

class AdjMatrixGraph : public Graph
{
public:
    AdjMatrixGraph(int v);
    virtual ~AdjMatrixGraph() override;
    virtual int addEdge(int i, int j, EdgeType w = 1) override;
    virtual void DFSTraverse() override;
	virtual int getVertexId(VertexType vex) override;
    virtual void BFSTraverse() override;
private:
    int numVertex;
    int numEdge;
    VertexType* vexs;
	std::unordered_map<VertexType, int> vex2idx;
    EdgeType** arc;
    bool* visited;
    std::queue<int> Q;

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
        std::cout << "Vertex " << i << ": ";
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

int AdjMatrixGraph::addEdge(int i, int j, EdgeType w)
{
    assert(i >= 0 && i < numVertex);
    assert(j >= 0 && j < numVertex);
    if (arc[i][j] == 1) return 1;
    arc[i][j] = 1;
    arc[j][i] = 1; // this is for undirected graph
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

void AdjMatrixGraph::BFSTraverse()
{
    std::fill(visited, visited+numVertex, false);
    for (int i = 0; i < numVertex; i++)
    {
        if (!visited[i])
        {
            // One vertex is found when it is enqueued. And, at this time, it is only found and enqueued, not visited.
            // bool* visited for BFS doesn't need to be global. It can be a local array or set to record the found vertex.
            Q.push(i);
            visited[i] = true; 
            
            while (!Q.empty())
            {
                int found = Q.front();
                std::cout << vexs[found] << " "; // This is actually when one vertex is visited.
                Q.pop();

                for (int j = 0; j < numVertex; j++)
                {
                    if (arc[found][j] == 1 && !visited[j])
                    {
                        Q.push(j); // One vertex is found when it is enqueued.
                        visited[j] = true;
                    }
                }
            }
        }
    }
    std::cout << std::endl;
}
#endif ADJ_MATRIX_GRAPH_HPP