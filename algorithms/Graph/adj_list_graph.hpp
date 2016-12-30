#include "Graph.h"
#include <vector>
#include <list>
#include <iostream>
#include <unordered_map>
#include <assert.h>
#include <algorithm>

#ifndef ADJ_LIST_GRAPH_HPP
#define ADJ_LIST_GRAPH_HPP

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

    AdjListGraph(int v);
    virtual ~AdjListGraph() override;
    virtual int addEdge(int i, int j, EdgeType w = 1) override;
    virtual int getVertexId(VertexType) override;
    virtual void DFSTraverse() override;
    virtual void BFSTraverse() override;
private:
    int numVertex;
    int numEdge;

    std::vector<VertexNode> adjList;
    std::unordered_map<VertexType, int> vex2idx;
    std::vector<bool> visited;

    void DFS(int i);
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

}
#endif