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
	//Graph& g = AdjListGraph(9);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 5, 11);
    g.addEdge(1, 2, 18);
    g.addEdge(1, 8, 12);
    g.addEdge(1, 6, 16);
    g.addEdge(5, 6, 17);
    g.addEdge(2, 8, 8);
    g.addEdge(2, 3, 22);
    g.addEdge(3, 8, 21);
    g.addEdge(3, 6, 24);
    g.addEdge(6, 7, 19);
    g.addEdge(4, 5, 26);
    g.addEdge(3, 7, 16);
    g.addEdge(3, 4, 20);
    g.addEdge(4, 7, 7);
    
    g.DFSTraverse();
    g.BFSTraverse();
    g.Prim();
    g.Krustal();
	g.Dijkstra(0, 1);
	g.Dijkstra(0, 2);
	g.Dijkstra(0, 3);
	g.Dijkstra(0, 4);
	g.Dijkstra(0, 5);
	g.Dijkstra(0, 6);
	g.Dijkstra(0, 7);
	g.Dijkstra(0, 8);
    g.clear();
    std::cout << std::endl;
    g.Floyd(0, 1);
    g.Floyd(0, 2);
    g.Floyd(0, 3);
    g.Floyd(0, 4);
    g.Floyd(0, 5);
    g.Floyd(0, 6);
    g.Floyd(0, 7);
    g.Floyd(0, 8);
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

