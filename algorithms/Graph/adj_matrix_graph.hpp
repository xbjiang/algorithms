#include "Graph.h"
#include <iostream>
#include <stdio.h>
#include <assert.h>
#include <unordered_map>
#include <queue>
#include <algorithm>

#ifndef __ADJ_MATRIX_GRAPH_HPP__
#define __ADJ_MATRIX_GRAPH_HPP__

class AdjMatrixGraph : public Graph
{
public:
    explicit AdjMatrixGraph(int v);
    AdjMatrixGraph(const AdjMatrixGraph&) = delete;
    AdjMatrixGraph& operator=(const AdjMatrixGraph&) = delete;
    virtual ~AdjMatrixGraph() override;
    virtual int addEdge(int i, int j, EdgeType w = 1) override;
    virtual void DFSTraverse() override;
	virtual int getVertexId(VertexType vex) override;
    virtual void BFSTraverse() override;
    virtual void Prim() override;
    virtual void Krustal() override;
    virtual void Dijkstra(int vbegin, int vend) override;
private:
    int numVertex;
    int numEdge;
    VertexType* vexs;
	std::unordered_map<VertexType, int> vex2idx;
    EdgeType** arc;
    bool* visited;
    PathMatrix pathMat; // store the index of precursor vertex for each node
    ShortestPathTable spTable; // store the total weight of shortest path

    void DFS(int i);
    int Find(const std::vector<int>& parent, int f);
    void Dijkstra();
};

AdjMatrixGraph::AdjMatrixGraph(int v) : numVertex(v), numEdge(0)
{
    arc = new EdgeType*[v];
    for (int i = 0; i < v; i++)
        arc[i] = new EdgeType[v]();
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            if (i == j)
                arc[i][j] = 0;
            else
                arc[i][j] = INF;
        }
    }
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
    if (arc[i][j] > 0 && arc[i][j] < INF) return 1;
    arc[i][j] = w;
    arc[j][i] = w; // this is for undirected graph
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
        if (!visited[j] &&
            arc[i][j] > 0 && arc[i][j] < INF)
            DFS(j);
}

void AdjMatrixGraph::BFSTraverse()
{
	std::queue<int> Q;
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
                    if (arc[found][j] > 0 && arc[found][j] < INF && !visited[j])
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

void AdjMatrixGraph::Prim()
{
    std::vector<int> adjvex(numVertex, 0);
    std::vector<EdgeType> lowcost(numVertex, 0);

    for (int i = 1; i < numVertex; i++)
        lowcost[i] = arc[0][i];

    for (int i = 1; i < numVertex; i++)
    {
        EdgeType min_cost = INF;
        int min_idx;
        for (int j = 1; j < numVertex; j++)
        {
            if (lowcost[j] != 0 && lowcost[j] < min_cost)
            {
                min_cost = lowcost[j];
                min_idx = j;
            }
        }
        std::cout << adjvex[min_idx] << " "
            << min_idx << std::endl;
        lowcost[min_idx] = 0;

        for (int j = 1; j < numVertex; j++)
        {
            if (lowcost[j] != 0 && arc[min_idx][j] < lowcost[j])
            {
                lowcost[j] = arc[min_idx][j];
                adjvex[j] = min_idx;
            }
        }
    }
}

void AdjMatrixGraph::Krustal()
{
    std::vector<int> parent(numVertex, 0);
    std::vector<Edge> edges;
    for (int i = 0; i < numVertex - 1; i++)
    {
        for (int j = i + 1; j < numVertex; j++)
        {
            if (arc[i][j] > 0 && arc[i][j] < INF)
                // edges.push_back(Edge(i, j, arc[i][j]));
                edges.emplace_back(i, j, arc[i][j]);
        }
    }

    assert(edges.size() == numEdge);

    std::sort(edges.begin(), edges.end(), [](Edge e1, Edge e2) { return e1.weight < e2.weight; });

    for (int i = 0; i < numEdge; i++)
    {
        int n = Find(parent, edges[i].begin);
        int m = Find(parent, edges[i].end);

        if (n != m)
        {
            parent[n] = m;
            printf("(%d, %d) %d\n", edges[i].begin, edges[i].end, edges[i].weight);
        }
    }
}

int AdjMatrixGraph::Find(const std::vector<int>& parent, int f)
{
    while (parent[f] != 0)
        f = parent[f];
    return f;
}

void AdjMatrixGraph::Dijkstra(int vbegin, int vend)
{
	if (pathMat.empty())
		Dijkstra();
	std::vector<int> path;
	int passing = vend;

	path.push_back(passing);
	while (passing != vbegin)
	{
		passing = pathMat[vbegin][passing];
		path.push_back(passing);
	}

	std::cout << "Shortest Path: ";
	for (int i = path.size() - 1; i >= 0; --i)
		std::cout << vexs[path[i]] << " ";
	std::cout << std::endl;
	std::cout << "Total weight: " 
              << spTable[vbegin][vend] 
              << std::endl;
}

void AdjMatrixGraph::Dijkstra()
{
    pathMat.resize(numVertex, std::vector<int>(numVertex, 0));
    spTable.resize(numVertex, std::vector<EdgeType>(numVertex, 0));

    for (int vbegin = 0; vbegin < numVertex; ++vbegin)
    {
        std::vector<int>& pathVec = pathMat[vbegin];   // precursor vertex
        std::vector<EdgeType>& spVec = spTable[vbegin]; // shortest path
        std::vector<bool> final(numVertex, false);

        for (int i = 0; i < numVertex; ++i)
        {
            spVec[i] = arc[vbegin][i];
        }
		final[vbegin] = true;

		for (int i = 1; i < numVertex; ++i)
		{
			EdgeType min = INF;
			int min_idx;
			for (int j = 0; j < numVertex; ++j)
			{
				if (!final[j] && spVec[j] < min)
				{
					min = spVec[j];
					min_idx = j;
				}
			}

			final[min_idx] = true;

			for (int k = 0; k < numVertex; ++k)
			{
				if (!final[k] && (min + arc[min_idx][k] < spVec[k]))
				{
					spVec[k] = min + arc[min_idx][k];
					pathVec[k] = min_idx;
				}
			}
		}
    }
}
#endif __ADJ_MATRIX_GRAPH_HPP__