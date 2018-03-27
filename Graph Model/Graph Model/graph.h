#pragma once
#include <vector>
#include <list>
#include <algorithm>

template <class T> class graph {
private:
	std::vector<std::list<T> > vectorList;
	int size;
public:
	void createGraphNodes(int a, T vertex[]);
	bool addEdge(T source, T destination);
	bool removeEdge(T source, T destination);
	void getVertices(T c[]);
	void DFS(T a);
	void BFS(T a);
	void printOutgoing();
	void printIncoming();
};


template <class T>
void graph<T>::createGraphNodes(int a, T vertex[]) {
	size = a;
	vectorList.resize(a);
	int arrayIndex = 0;
	typename std::vector<std::list<T> >::iterator it = vectorList.begin();

	for (it; it != vectorList.end(); it++, arrayIndex++) {
		(*it).push_back(vertex[arrayIndex]);
	}
}

template <class T>
bool graph<T>::addEdge(T source, T destination) {
	bool foundDestination = false;

	typename std::vector<std::list<T> >::iterator vectorIterator = vectorList.begin();

	for ( ; vectorIterator != vectorList.end(); vectorIterator++) {

		typename std::list<T>::iterator listIterator = (*vectorIterator).begin();
		if ((*listIterator) == source) {
			listIterator++;
			for (; listIterator != (*vectorIterator).end(); listIterator++) {
				if (*listIterator == destination) {
					foundDestination = true;
					break;
				}
			}
			if (foundDestination == false) {
				(*vectorIterator).push_back(destination);
				return true;
			}
			else {
				return false;
			}
		break;
		}
	}
}

template <class T>
bool graph<T>::removeEdge(T source, T destination) {
	bool foundDestination = false;
	typename std::vector<std::list<T> >::iterator vectorIterator = vectorList.begin();

	for ( ; vectorIterator != vectorList.end(); vectorIterator++) {

		typename std::list<T>::iterator listIterator = (*vectorIterator).begin();

		if ((*listIterator) == source) {
			listIterator++;
			for (; listIterator != (*vectorIterator).end(); listIterator++) {
				if (*listIterator == destination) {
					foundDestination = true;
					(*vectorIterator).remove(destination);
					return true;
				}
			}
			if (foundDestination == false) {
				return false;
			}
			break;
		}
	}
}

template<class T>
void graph<T>::getVertices(T c[]) {
	int index = 0;
	typename std::vector<std::list<T> >::iterator vectorIterator = vectorList.begin();
	
	for ( ; vectorIterator != vectorList.end(); vectorIterator++, index++) {
		typename std::list<T>::iterator listIterator = (*vectorIterator).begin();
		c[index] = (*listIterator);
	}
}

template<class T>
void graph<T>::DFS(T a) {
	T *c = new T[size]; 
	getVertices(c); 
	bool *visited = new bool[size];

	for (int i = 0; i < size; i++) {
		visited[i] = false;
	}
	std::list<T> s; s.push_back(a);

	while (s.size() > 0) {
		T node = s.back();
		s.pop_back();
		int positionOfNode = std::find(c, c + size, node) - c;
	
		if (visited[positionOfNode] == false) {
			visited[positionOfNode] = true;
			std::cout << "Visiting: " << node << endl;
			typename std::vector<std::list<T> >::iterator vectorIterator = vectorList.begin();
			for (; vectorIterator != vectorList.end(); vectorIterator++) {
				typename std::list<T>::iterator listIterator = (*vectorIterator).begin();
				if ((*listIterator) == node) {
					listIterator++;
					for (; listIterator != (*vectorIterator).end(); listIterator++) {
						s.push_back((*listIterator));
					}
					break;
				}
			}
		}
	}
}

template<class T>
void graph<T>::BFS(T a) {
	T *c = new T[size];
	getVertices(c);
	bool *visited = new bool[size];

	for (int i = 0; i < size; i++) {
		visited[i] = false;
	}
	std::list<T> s; s.push_back(a);

	while (s.size() > 0) {
		T node = s.front();
		s.pop_front();
		int positionOfNode = std::find(c, c + size, node) - c;

		if (visited[positionOfNode] == false) {
			visited[positionOfNode] = true;
			std::cout << "Visiting: " << node << endl;
			
			typename std::vector<std::list<T> >::iterator vectorIterator = vectorList.begin();
			for (; vectorIterator != vectorList.end(); vectorIterator++) {
				typename std::list<T>::iterator listIterator = (*vectorIterator).begin();
				if ((*listIterator) == node) {
					listIterator++;
					for (; listIterator != (*vectorIterator).end(); listIterator++) {
						s.push_back((*listIterator));
					}
					break;
				}
			}
		}
	}
}

template <class T>
void graph<T>::printOutgoing() {

	typename std::vector<std::list<T> >::iterator vectorIterator = vectorList.begin();
	for (vectorIterator; vectorIterator != vectorList.end(); vectorIterator++) {
		typename std::list<T>::iterator listIterator = (*vectorIterator).begin();
		std::cout << (*listIterator) << ": ";
		listIterator++;
		for (; listIterator != (*vectorIterator).end(); listIterator++) {
			std::cout << (*listIterator) << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <class T>
void graph<T>::printIncoming() {
	typename std::vector<std::list<T> >::iterator vectorIterator = vectorList.begin();
	for (vectorIterator; vectorIterator != vectorList.end(); vectorIterator++) {

		typename std::list<T>::iterator listIterator = (*vectorIterator).begin();
		std::cout << (*listIterator) << ": ";
	
		typename std::vector<std::list<T> >::iterator vlt = vectorList.begin();

		for (vlt; vlt != vectorList.end(); vlt++) {
			typename std::list<T>::iterator lst = (*vlt).begin();
			lst++;
			for (; lst != (*vlt).end(); lst++) {
				if (*lst == *listIterator) {
					std::cout << (*vlt).front() << " ";
					break;
				}
			}
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}