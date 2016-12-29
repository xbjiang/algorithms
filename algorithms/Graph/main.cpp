#include "Graph.h"
#include "adj_matrix_graph.hpp"
#include "adj_list_graph.hpp"
#include <iostream>
using namespace std;

void test(Graph& g, int numEdge)
{
    int k = 0;
    Graph::VertexType vi, vj;
    cout << "Input names of two vertexes of edge (vi, vj): " << std::endl;
    while (k < numEdge)
    {
        cout << "edge " << k + 1 << ": ";
        cin >> vi >> vj;
        g.addEdge(g.getVertexId(vi), g.getVertexId(vj));
        k++;
    }
    cout << "result of depth first search: " << endl;
    g.DFSTraverse();
}

int main()
{
    int numVertex;
    int numEdge;
    cout << "Input number of vertexes: " << endl;
    cin >> numVertex;
    cout << "Input number of edges: " << endl;
    cin >> numEdge;

    test(AdjListGraph(numVertex), numEdge);
    test(AdjMatrixGraph(numVertex), numEdge);
    
}

