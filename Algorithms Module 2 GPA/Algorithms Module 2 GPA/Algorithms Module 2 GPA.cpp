// Algorithms Module 2 GPA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <queue>
#include <vector>
#include <iostream>
using namespace std;

void move(int coordinateX, int coordinateY, queue<int> & Qx,
	queue<int> & Qy, vector<vector<char> > & graph,
	vector<vector<bool> > & visited, vector <char> & answer) {

	if (graph[coordinateX][coordinateY] == 't') {
		return;
	}
	
	while (graph[coordinateX][coordinateY] != 't') {
		
		if (coordinateY + 1 != 3) { //look right
			if ((visited[coordinateX][coordinateY + 1] == false) && (graph[coordinateX][coordinateY + 1] != 'x')) {
				cout << "right" << endl;
				Qx.push(coordinateX);
				Qy.push(coordinateY + 1);

				visited[coordinateX][coordinateY + 1] = true;
				answer.push_back(graph[coordinateX][coordinateY + 1]);
			}
		}
		if (coordinateX + 1 != 2) { //look down
			if ((visited[coordinateX + 1][coordinateY] == false) && (graph[coordinateX + 1][coordinateY] != 'x')) {
				cout << "down" << endl;
				Qx.push(coordinateX + 1);
				Qy.push(coordinateY);

				visited[coordinateX + 1][coordinateY] = true;
				answer.push_back(graph[coordinateX + 1][coordinateY]);
			}
		}
		if (coordinateY - 1 != -1) { //look left
			if ((visited[coordinateX][coordinateY - 1] == false) && (graph[coordinateX][coordinateY - 1] != 'x')) { 
				cout << "left" << endl;
				Qx.push(coordinateX);
				Qy.push(coordinateY - 1);

				visited[coordinateX][coordinateY - 1] = true;
				answer.push_back(graph[coordinateX][coordinateY - 1]);
			}
		}
		if (coordinateX - 1 != -1) { //look up
			if ((visited[coordinateX - 1][coordinateY] == false) && (graph[coordinateX - 1][coordinateY] != 'x')) {
				cout << "up" << endl;
				Qx.push(coordinateX - 1);
				Qy.push(coordinateY);

				visited[coordinateX - 1][coordinateY] = true;
				answer.push_back(graph[coordinateX - 1][coordinateY]);
			}
		}
		cout << endl;
		Qx.pop(); Qy.pop();
		coordinateX = Qx.front();
		coordinateY = Qy.front();
	}
}

int main() {

}