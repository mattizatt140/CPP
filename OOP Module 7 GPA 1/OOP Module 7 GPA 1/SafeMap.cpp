#include "stdafx.h"
#include "SafeMap.h"
#include <list>
#include <iostream>
using namespace std;

SafeMap::SafeMap(int V)
{
	this->V = V;
	adj = new list<int>[V];
}

void SafeMap::addSafeRoute(int v, int w)
{
	adj[v].push_back(w); // Add w to v's list.
}

// Function to check if S is safely reachable from D
int SafeMap::isReachable(int s, int d)
{
	// Mark all the vertices as not visited
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	list<int> queue;

	
	// Mark the current node as visited and enqueue it
	visited[s] = true;
	queue.push_back(s);

	// it will be used to get all adjacent vertices of a vertex accesible thru
	// a safe route
	
	list<int>::iterator i;
	
	//Write your code below this line
	if (s == d) { return 0; }
	for (i = adj[s].begin(); i != adj[s].end(); i++) {
		if (*i == d) {
			visited[d] = true;
			queue.push_back(d);
			return 1;
		}
	}
	return -1;
}