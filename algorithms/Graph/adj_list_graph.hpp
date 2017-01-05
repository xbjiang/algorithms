#include "Graph.h"
#include <vector>
#include <list>
#include <iostream>
#include <unordered_map>
#include <assert.h>
#include <algorithm>
#include <stdio.h>

#ifndef __ADJ_LIST_GRAPH_HPP__
#define __ADJ_LIST_GRAPH_HPP__

class AdjListGraph : public Graph
{
public:
    
    struct EdgeNode
    {
        int adjvexid;         // index of the adjacency Vertex
        EdgeType weight;
        EdgeNode(int id, EdgeType w) : adjvexid(id), weight(w) {}
    };
    struct VertexNode
    {
        VertexType name;
        std::list<EdgeNode> edgeList;
        VertexNode(VertexType n) : name(n) {}
    };

    explicit AdjListGraph(int v);
    virtual ~AdjListGraph() override;
    virtual int addEdge(int i, int j, EdgeType w = 1) override;
    virtual int getVertexId(VertexType) override;
    virtual void DFSTraverse() override;
    virtual void BFSTraverse() override;
    virtual void Prim() override;
    virtual void Krustal() override;
private:
    int numVertex;
    int numEdge;

    std::vector<VertexNode> adjList;
    std::unordered_map<VertexType, int> vex2idx;
    std::vector<bool> visited;

    void DFS(int i);
    int Find(std::vector<int>& parent, int f);
};

AdjListGraph::AdjListGraph(int v) : numVertex(v), numEdge(0)
{
    std::cout << "Input the name for each Vertex: " << std::endl;
    for (int i = 0; i < v; i++)
    {
        std::cout << "Vertex " << i << ": ";
        VertexType name;
        std::cin >> name;
        // std::cout << std::endl; // this line is unnecessary
        adjList.push_back(VertexNode(name));
        vex2idx[name] = i;
    }
    visited.resize(v, false);
}

AdjListGraph::~AdjListGraph()
{
}

int AdjListGraph::addEdge(int i, int j, EdgeType w)
{
    assert(i >= 0 && i < numVertex);
    assert(j >= 0 && j < numVertex);

    std::list<EdgeNode>& eli = adjList[i].edgeList;
    std::list<EdgeNode>::iterator iter = eli.begin();
    while (iter != eli.end())
    {
        if (iter->adjvexid == j)
            return 1;
        iter++;
    }
    eli.push_back(EdgeNode(j, w));
    std::list<EdgeNode>& elj = adjList[j].edgeList;
    elj.push_back(EdgeNode(i, w)); // this is for undirected graph
    numEdge++;
    return 0;
}

int AdjListGraph::getVertexId(VertexType name)
{
    return vex2idx[name];
}

void AdjListGraph::DFSTraverse()
{
    std::fill(visited.begin(), visited.end(), false);
    for (int i = 0; i < numVertex; i++)
        if (!visited[i])
            DFS(i);
    std::cout << std::endl;
}

void AdjListGraph::DFS(int i)
{
    visited[i] = true;
    std::cout << adjList[i].name << " ";
    std::list<EdgeNode>& eli = adjList[i].edgeList;
    std::list<EdgeNode>::iterator iter = eli.begin();
    while (iter != eli.end())
    {
        if (!visited[iter->adjvexid])
            DFS(iter->adjvexid);
        iter++;
    }
}

void AdjListGraph::BFSTraverse()
{
	std::queue<int> Q;
	std::fill(visited.begin(), visited.end(), false);
	for (int i = 0; i < numVertex; i++)
	{
		if (!visited[i])
		{
			Q.push(i);
			visited[i] = true;

			while (!Q.empty())
			{
				int found = Q.front();
				std::cout << adjList[found].name << " ";
				Q.pop();

				std::list<EdgeNode>& elf = adjList[found].edgeList;
				std::list<EdgeNode>::iterator iter = elf.begin();
				while (iter != elf.end())
				{
					if (!visited[iter->adjvexid])
					{
						visited[iter->adjvexid] = true;
						Q.push(iter->adjvexid);
					}
					iter++;
				}
			}
		}
	}
	std::cout << std::endl;
}

void AdjListGraph::Prim()
{
    std::vector<int> adjvex(numVertex, 0);
    std::vector<EdgeType> lowcost(numVertex, INF);
    lowcost[0] = 0;
    std::list<EdgeNode>& el = adjList[0].edgeList;
    std::list<EdgeNode>::iterator iter = el.begin();
    while (iter != el.end())
    {
        lowcost[iter->adjvexid] = iter->weight;
        iter++;
    }

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
        lowcost[min_idx] = 0;
        std::cout << adjvex[min_idx] << " "
            << min_idx << std::endl;

        std::list<EdgeNode>& el = adjList[min_idx].edgeList;
        std::list<EdgeNode>::iterator iter = el.begin();
        while (iter != el.end())
        {
            int id = iter->adjvexid;
            if (lowcost[id] != 0 && iter->weight < lowcost[id])
            {
                lowcost[id] = iter->weight;
                adjvex[id] = min_idx;
            }
            iter++;
        }
    }
}

void AdjListGraph::Krustal()
{
    std::vector<int> parent(numVertex, 0);
    std::vector<Edge> edges;
    for (int i = 0; i < numVertex - 1; i++)
    {
        for (auto& node : adjList[i].edgeList)
        {
            if (node.adjvexid <= i)
                continue;
            if (node.weight > 0 && node.weight < INF)
                // edges.push_back(Edge(i, node.adjvexid, node.weight));
                edges.emplace_back(i, node.adjvexid, node.weight);
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

int AdjListGraph::Find(std::vector<int>& parent, int f)
{
    while (parent[f] != 0)
        f = parent[f];
    return f;
}
#endif