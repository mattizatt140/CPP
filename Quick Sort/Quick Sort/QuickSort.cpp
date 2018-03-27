#include "stdafx.h"
#include "QuickSort.h"
#include <vector>
#include <thread>

template <class T> void QuickSort<T>::swap(T *a, T *b) {
	T temp = *a;
	*a = *b;
	*b = temp;
	return;
}

template <typename T> int QuickSort<T>::partition(std::vector<T> &vec, int low, int high) {
	T pivot = classVec[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	for (int j = low; j < high - 1; j++)
	{
		// If current element is smaller than
		// equal to pivot
		if (classVec[j] <= pivot)
		{
			i++;    // increment index of smaller element
			swap(&vec[i], &vec[j]);
		}
	}
	swap(&vec[i + 1], &vec[high]);
	return (i + 1);
}

template <class T> void QuickSort<T>::quickSort(std::vector<T> &vec, int low, int high) {
	if (low < high)
	{
		// pi is partitioning index
		int pi = partition(vec, low, high);

		// Separately sort elements before
		// partition and after partition
		quickSort(vec, low, pi - 1);
		quickSort(vec, pi + 1, high);
	}
	return;
}

template <class T> void QuickSort<T>::copyClassVec(std::vector<T> &vec) {
	typename std::vector<T>::iterator it;
	for (it = classVec.begin(); it != classVec.end(); it++) {
		vec.push_back(*it);
	}
}

template <class T> void QuickSort<T>::setVecVals() {
	T vecVal;
	std::cout << "Vector size: "; std::cin >> vecSize;

	for (int i = 0; i < vecSize; i++) {
		std::cout << "Element " << "[" << i << "]: "; std::cin >> vecVal;
		classVec.push_back(vecVal);
	}
}

template <class T> int QuickSort<T>::getHigh() {
	return high;
}

template <class T> int QuickSort<T>::getLow() {
	return low;
}

template <class T> void QuickSort<T>::displayVec() {
	for (int i = 0; i < getVecSize(); i++) {
		if (i == 35) { std::cout << std::endl; }
	
		if (i == (getVecSize() - 1)) {
			std::cout << classVec.at(i) << "]" << std::endl;
			break;
		}
		if (i == 0) {
			std::cout << "[";
		}
		std::cout << classVec.at(i) << ", ";
	}
	return;
}

template <class T> int QuickSort<T>::getVecSize() {
	return vecSize;
}

template <class T> void QuickSort<T>::switchFlag() {
	flag = !flag;
}
template <class T> void QuickSort<T>::wait() {
	using namespace std::literals::chrono_literals;

	while (!this->flag) {
		std::cout << "Wait..." << std::endl;
		std::this_thread::sleep_for(1.5s);
	}
}

template <class T> std::thread QuickSort<T>::waitThread() {
	return std::thread([=] { fill(); });
}