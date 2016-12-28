#include "adj_matrix_graph.hpp"
#include <iostream>
using namespace std;

int main()
{
	int numVertex;
	int numEdge;
	cout << "Input number of vertexes: " << endl;
	cin >> numVertex;
	cout << "Input number of edges: " << endl;
	cin >> numEdge;

	AdjMatrixGraph g(numVertex);
	
	int k = 0;
	AdjMatrixGraph::VertexType vi, vj;
	while (k < numEdge)
	{
		cout << "Input names of two vertexes of edge (vi, vj): " << std::endl;
		cin >> vi >> vj;
		g.addEdge(g.getVertexId(vi), g.getVertexId(vj));
		k++;
	}
	cout << "result of depth first search: " << endl;
	g.DFSTraverse();
}

