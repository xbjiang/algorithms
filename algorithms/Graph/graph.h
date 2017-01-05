#ifndef GRAPH_H
#define GRAPH_H

#include <string>

#define INF 65536

class Graph
{
public:
    typedef std::string VertexType;
    typedef int EdgeType;
    struct Edge
    {
        int begin;
        int end;
        EdgeType weight;
        Edge(int b, int e, EdgeType w) : 
            begin(b), end(e), weight(w) {}
    };

    Graph() {}
    virtual ~Graph() {}
    virtual int addEdge(int i, int j, EdgeType w = 1) = 0;
    virtual int getVertexId(VertexType name) = 0;
    virtual void DFSTraverse() = 0;
    virtual void BFSTraverse() = 0;
    virtual void Prim() = 0;
    virtual void Krustal() = 0;
};
#endif