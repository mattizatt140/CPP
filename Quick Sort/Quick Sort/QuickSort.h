#pragma once
#include <vector>
#include <thread>
#include <ctime>
#include <cstdlib>

template <class T> class QuickSort {

private:
	
	int vecSize; //amount of elements vec will hold
	int high; //vectors are base 0
			  //max element position = (number of elements - 1)

	int low = 0;
	bool flag = false; //stop fill function

public:
	
	std::exception e_obj;
	std::vector<T> classVec;

	QuickSort();
	
	~QuickSort();

	void swap(T *a, T *b);

	int partition(std::vector<T> &vec, int low, int high);

	void quickSort(std::vector<T> &vec, int low, int high); //main func to be called

	void setVecVals(); //setting values of classVec
					  //size of classVec set in this function

	int getVecSize(); //returns size of classVec

	int getHigh();

	int getLow();

	void switchFlag();

	void setVecRandom();

	void randWait();

	void wait(); //sends filler message during sorting

	std::thread randThread();

	std::thread waitThread();

	std::exception except;

};

template <class T> QuickSort<T>::QuickSort() {}

template <class T> QuickSort<T>::~QuickSort() {}

template <class T> void QuickSort<T>::swap(T *a, T *b) {
	T temp = *a;
	*a = *b;
	*b = temp;
	return;
}

template <typename T> int QuickSort<T>::partition(std::vector<T> &vec, int low, int high) {
	T pivot = classVec[high];    // pivot
	int i = (low - 1);  // Index of smaller element

	try {
		for (int j = low; j < high; j++)
		{
			// If current element is smaller than
			// equal to pivot
			if (classVec[j] <= pivot)
			{
				i++;    // increment index of smaller element
				swap(&vec[i], &vec[j]);
			}
		}
		if (vec[i + 1] == NULL || vec[high] == NULL) { throw this->e_obj; }
		swap(&vec[i + 1], &vec[high]);
		return (i + 1);
	}
	catch (std::exception &e) {
		throw e;
	}
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

template <class T> void QuickSort<T>::setVecVals() {
	T vecVal;
	std::cout << "Vector size: "; std::cin >> vecSize;

	for (int i = 0; i < vecSize; i++) {
		std::cout << "Element " << "[" << i << "]: "; std::cin >> vecVal;
		classVec.push_back(vecVal);
	}

	high = (vecSize - 1);
}

template <class T> int QuickSort<T>::getHigh() {
	return high;
}

template <class T> int QuickSort<T>::getLow() {
	return low;
}

template <class T> int QuickSort<T>::getVecSize() {
	return vecSize;
}

template <class T> void QuickSort<T>::switchFlag() {
	flag = !flag;
}

template <class T> void QuickSort<T>::setVecRandom() {

	std::cout << "Vector size: "; std::cin >> vecSize;
	
	std::thread randThread = this->randThread();
	srand(time(0));
	for (int i = 0; i < vecSize; i++) {
		int random = (rand() % 100) + 1;
		classVec.push_back(random);
	}
	this->switchFlag();
	randThread.join();
	this->switchFlag();

	high = (vecSize - 1);
}

template <class T> void QuickSort<T>::wait() {
	using namespace std::literals::chrono_literals;

	while (!this->flag) {
		std::cout << "Sorting..." << std::endl;
		std::this_thread::sleep_for(7s);
	}
}

template <class T> void QuickSort<T>::randWait() {
	using namespace std::literals::chrono_literals;

	while (!this->flag) {
		std::cout << "Generating Elements..." << std::endl;
		std::this_thread::sleep_for(4s);
	}
}

template <class T> std::thread QuickSort<T>::waitThread() {
	return std::thread([=] { wait(); });
}

template <class T> std::thread QuickSort<T>::randThread() {
	return std::thread([=] { randWait(); });
}