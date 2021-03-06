// Graph Model.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "graph.h"
#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
	int size = 5;
	char vertex[] = { 'A', 'B', 'C', 'D', 'E' };
	graph<char> g;

	g.createGraphNodes(5, vertex);
	std::cout << "Creating graph nodes\n\n";
	g.addEdge('A', 'B');
	g.addEdge('A', 'C');
	g.addEdge('C', 'D');
	g.removeEdge('C', 'D');

	std::cout << "Outgoing..." << std::endl;
	g.printOutgoing();
	std::cout << "Incoming..." << std::endl;
	g.printIncoming();

	g.BFS('A');
}

