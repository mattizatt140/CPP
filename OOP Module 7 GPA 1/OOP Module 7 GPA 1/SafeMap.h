#pragma once
#include <list>
using namespace std;

class SafeMap {
public:

	int V;
	list<int> *adj;

	SafeMap(int V);

	void addSafeRoute(int v, int w);

	int isReachable(int s, int d);

};
