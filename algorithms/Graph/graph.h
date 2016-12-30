#ifndef GRAPH_H
#define GRAPH_H

class Graph
{
public:
    typedef char VertexType;
    typedef int EdgeType;

    Graph() {}
    virtual ~Graph() {}
    virtual int addEdge(int i, int j, EdgeType w = 1) = 0;
    virtual int getVertexId(VertexType name) = 0;
    virtual void DFSTraverse() = 0;
    virtual void BFSTraverse() = 0;
};
#endif