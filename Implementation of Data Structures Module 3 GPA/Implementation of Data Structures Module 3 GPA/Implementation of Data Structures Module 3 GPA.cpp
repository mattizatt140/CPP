// Implementation of Data Structures Module 3 GPA.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "header.h"
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//-----Add new functions here(if any)-----
void lookRight(int coordinateX, int coordinateY, queue<int> & Qx,
			   queue<int> & Qy, vector<vector<char> > & graph,
		       vector<vector<bool> > & visited, vector <char> & answer) {
	
	if ((coordinateY + 1 > 9) || visited[coordinateX][coordinateY + 1] || 
		graph[coordinateX][coordinateY + 1] == 'x') {
		return;
	}
	else {
		Qx.push(coordinateX);
		Qy.push(coordinateY+1);
		visited[coordinateX][coordinateY + 1] = true;
		answer.push_back(graph[coordinateX][coordinateY+1]);
	}
}

void lookDown(int coordinateX, int coordinateY, queue<int> & Qx,
	queue<int> & Qy, vector<vector<char> > & graph,
	vector<vector<bool> > & visited, vector <char> & answer) {
	
	if ((coordinateX + 1 > 9) || visited[coordinateX + 1][coordinateY] ||
		graph[coordinateX + 1][coordinateY] == 'x') {
		return;
	}
	else {
		Qx.push(coordinateX+1);
		Qy.push(coordinateY);
		visited[coordinateX+1][coordinateY] = true;
		answer.push_back(graph[coordinateX+1][coordinateY]);
	}
}

void lookLeft(int coordinateX, int coordinateY, queue<int> & Qx,
	queue<int> & Qy, vector<vector<char> > & graph,
	vector<vector<bool> > & visited, vector <char> & answer) {
	
	if ((coordinateY - 1 < 0) || visited[coordinateX][coordinateY - 1] ||
		graph[coordinateX][coordinateY - 1] == 'x') {
		return;
	}
	else {
		Qx.push(coordinateX);
		Qy.push(coordinateY - 1);
		visited[coordinateX][coordinateY - 1] = true;
		answer.push_back(graph[coordinateX][coordinateY - 1]);
	}
}

void lookUp(int coordinateX, int coordinateY, queue<int> & Qx,
	queue<int> & Qy, vector<vector<char> > & graph,
	vector<vector<bool> > & visited, vector <char> & answer) {
	
	if ((coordinateX - 1 < 0) || visited[coordinateX - 1][coordinateY]) {
		return;
	}
	else if (graph[coordinateX - 1][coordinateY] != 'x') {
		Qx.push(coordinateX - 1);
		Qy.push(coordinateY);
		visited[coordinateX - 1][coordinateY] = true;
		answer.push_back(graph[coordinateX - 1][coordinateY]);
	}
}

//-----New functions end here-----

/* You need to write the implementation of the given function.
( You may write any additional helper functions you want in the specified region only.
Do not change the signature of the function already given)
For detailed explanation of the question refer to the Description part)
*/

void move(int coordinateX, int coordinateY, queue<int> & Qx,
	      queue<int> & Qy, vector<vector<char> > & graph, 
		  vector<vector<bool> > & visited, vector <char> & answer)
{   // DO NOT CHANGE THIS!
	/*
	coordinateX, coordinateY are your current coordinates
	Qx,Qy are the queues where you have to store the coordinates of x and y for the valid blocks
	graph is the matrix representation for the city as a 2D vector
	*/
	// start your code below this line
	visited[0][0] = true;
	Qx.push(0); Qy.push(0);
	answer.push_back(graph[0][0]);
	while (graph[coordinateX][coordinateY] != 't') {
		lookRight(coordinateX, coordinateY, Qx, Qy, graph, visited, answer);
		lookDown(coordinateX, coordinateY, Qx, Qy, graph, visited, answer);
		lookLeft(coordinateX, coordinateY, Qx, Qy, graph, visited, answer);
		lookUp(coordinateX, coordinateY, Qx, Qy, graph, visited, answer);
		coordinateX = Qx.front();
		coordinateY = Qy.front();
		Qx.pop(); Qy.pop();
	}
}

int main() {
	int cX = 0, cY = 0;
	queue<int> Qx, Qy;
	vector<vector<char> > graph = { {0,2,5,6}, {5,'x',8,'t'}, {9, 1, 0, 8} };
	vector<vector<bool> > visited(4, vector<bool>(3));
	vector <char> answer;
	move(cX, cY, Qx, Qy, graph, visited, answer);
	//for (int i = 0; i < answer.size(); i++) {
	//	cout << answer.at(i) << " ";
	//}
								   
}