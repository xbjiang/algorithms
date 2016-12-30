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
    g.BFSTraverse();
}

void test_with_fixed_graphs()
{
    Graph& g = AdjMatrixGraph(9);
    g.addEdge(0, 1);
    g.addEdge(0, 5);
    g.addEdge(1, 2);
    g.addEdge(1, 8);
    g.addEdge(1, 6);
    g.addEdge(5, 6);
    g.addEdge(2, 8);
    g.addEdge(2, 3);
    g.addEdge(3, 8);
    g.addEdge(3, 6);
    g.addEdge(6, 7);
    g.addEdge(4, 5);
    g.addEdge(3, 7);
    g.addEdge(3, 4);
    g.addEdge(4, 7);
    
    g.DFSTraverse();
    g.BFSTraverse();
}

int main()
{
    /*int numVertex;
    int numEdge;
    cout << "Input number of vertexes: " << endl;
    cin >> numVertex;
    cout << "Input number of edges: " << endl;
    cin >> numEdge;

    test(AdjListGraph(numVertex), numEdge);
    test(AdjMatrixGraph(numVertex), numEdge);*/

    test_with_fixed_graphs();
}

