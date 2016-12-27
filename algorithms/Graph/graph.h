
#ifndef GRAPH_H
#define GRAPH_H

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 100

// for adjacency matrix
struct MGraph
{
	VertexType vexs[MAXVEX];
	EdgeType arc[MAXVEX][MAXVEX];
	int numVertexes, numEdges;
};

// for adjacency list
typedef struct EdgeNode
{
	int adjvex; // index for this Vertex
	EdgeType weight;
	struct EdgeNode* next;
} EdgeNode;

typedef struct VertexNode 
{
	VertexType data;
	EdgeNode* firstedge;
} VertexNode, AdjList[MAXVEX];

#endif