// Threaded Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <windows.h>

#define SIZE (16*1024*1024)             // must be multiple of 4

static HANDLE hs0;                      // semaphore handles
static HANDLE hs1;
static HANDLE hs2;
static HANDLE hs3;
static HANDLE ht1;                      // thread handles
static HANDLE ht2;
static HANDLE ht3;

static DWORD WINAPI Thread0(LPVOID);    // thread functions
static DWORD WINAPI Thread1(LPVOID);
static DWORD WINAPI Thread2(LPVOID);
static DWORD WINAPI Thread3(LPVOID);

static int  *pa;                        // pointers to buffers
static int  *pb;

void BottomUpMergeSort(int a[], int b[], size_t n);
void BottomUpMerge(int a[], int b[], size_t ll, size_t rr, size_t ee);
void BottomUpCopy(int a[], int b[], size_t ll, size_t rr);
size_t GetPassCount(size_t n);

int main()
{
	int *array = new int[SIZE];
	int *buffer = new int[SIZE];
	clock_t ctTimeStart;                    // clock values
	clock_t ctTimeStop;
	pa = array;
	pb = buffer;
	for (int i = 0; i < SIZE; i++) {      // generate pseudo random data
		int r;
		r = (((int)((rand() >> 4) & 0xff)) << 0);
		r += (((int)((rand() >> 4) & 0xff)) << 8);
		r += (((int)((rand() >> 4) & 0xff)) << 16);
		r += (((int)((rand() >> 4) & 0x7f)) << 24);
		array[i] = r;
	}

	hs0 = CreateSemaphore(NULL, 0, 1, NULL);
	hs1 = CreateSemaphore(NULL, 0, 1, NULL);
	hs2 = CreateSemaphore(NULL, 0, 1, NULL);
	hs3 = CreateSemaphore(NULL, 0, 1, NULL);
	ht1 = CreateThread(NULL, 0, Thread1, 0, 0, 0);
	ht2 = CreateThread(NULL, 0, Thread2, 0, 0, 0);
	ht3 = CreateThread(NULL, 0, Thread3, 0, 0, 0);

	ctTimeStart = clock();
	ReleaseSemaphore(hs0, 1, NULL);     // start sorts
	ReleaseSemaphore(hs1, 1, NULL);
	ReleaseSemaphore(hs2, 1, NULL);
	ReleaseSemaphore(hs3, 1, NULL);
	Thread0((LPVOID)NULL);
	WaitForSingleObject(ht2, INFINITE);
	// merge 1st and 2nd halves
	BottomUpMerge(pb, pa, 0, SIZE >> 1, SIZE);
	ctTimeStop = clock();
	std::cout << "Number of ticks " << (ctTimeStop - ctTimeStart) << std::endl;

	for (int i = 1; i < SIZE; i++) {      // check result 
		if (array[i - 1] > array[i]) {
			std::cout << "failed" << std::endl;
		}
	}
	for (int i = 0; i < SIZE; i++) {
		std::cout << array[i] << " ";
	}
	CloseHandle(ht3);
	CloseHandle(ht2);
	CloseHandle(ht1);
	CloseHandle(hs3);
	CloseHandle(hs2);
	CloseHandle(hs1);
	CloseHandle(hs0);
	delete[] buffer;
	delete[] array;
	return 0;
}

static DWORD WINAPI Thread0(LPVOID lpvoid)
{
	WaitForSingleObject(hs0, INFINITE); // wait for semaphore
										// sort 1st quarter
	BottomUpMergeSort(pa + 0 * (SIZE >> 2), pb + 0 * (SIZE >> 2), SIZE >> 2);
	WaitForSingleObject(ht1, INFINITE); // wait for thead 1
										// merge 1st and 2nd quarter
	BottomUpMerge(pa + 0 * (SIZE >> 1), pb + 0 * (SIZE >> 1), 0, SIZE >> 2, SIZE >> 1);
	return 0;
}

static DWORD WINAPI Thread1(LPVOID lpvoid)
{
	WaitForSingleObject(hs1, INFINITE); // wait for semaphore
										// sort 2nd quarter
	BottomUpMergeSort(pa + 1 * (SIZE >> 2), pb + 1 * (SIZE >> 2), SIZE >> 2);
	return 0;
}

static DWORD WINAPI Thread2(LPVOID lpvoid)
{
	WaitForSingleObject(hs2, INFINITE); // wait for semaphore
										// sort 3rd quarter
	BottomUpMergeSort(pa + 2 * (SIZE >> 2), pb + 2 * (SIZE >> 2), SIZE >> 2);
	WaitForSingleObject(ht3, INFINITE); // wait for thread 3
										// merge 3rd and 4th quarter
	BottomUpMerge(pa + 1 * (SIZE >> 1), pb + 1 * (SIZE >> 1), 0, SIZE >> 2, SIZE >> 1);
	return 0;
}

static DWORD WINAPI Thread3(LPVOID lpvoid)
{
	WaitForSingleObject(hs3, INFINITE); // wait for semaphore
										// sort 4th quarter
	BottomUpMergeSort(pa + 3 * (SIZE >> 2), pb + 3 * (SIZE >> 2), SIZE >> 2);
	return 0;
}

void BottomUpMergeSort(int a[], int b[], size_t n)
{
	size_t s = 1;                               // run size 
	if (GetPassCount(n) & 1) {                // if odd number of passes
		for (s = 1; s < n; s += 2)           // swap in place for 1st pass
			if (a[s] < a[s - 1])
				std::swap(a[s], a[s - 1]);
		s = 2;
	}
	while (s < n) {                           // while not done
		size_t ee = 0;                      // reset end index
		while (ee < n) {                      // merge pairs of runs
			size_t ll = ee;                 // ll = start of left  run
			size_t rr = ll + s;               // rr = start of right run
			if (rr >= n) {                    // if only left run
				rr = n;
				BottomUpCopy(a, b, ll, rr); //   copy left run
				break;                      //   end of pass
			}
			ee = rr + s;                      // ee = end of right run
			if (ee > n)
				ee = n;
			BottomUpMerge(a, b, ll, rr, ee);
		}
		std::swap(a, b);                    // swap a and b
		s <<= 1;                            // double the run size
	}
}

void BottomUpMerge(int a[], int b[], size_t ll, size_t rr, size_t ee)
{
	size_t o = ll;                          // b[]       index
	size_t l = ll;                          // a[] left  index
	size_t r = rr;                          // a[] right index
	while (1) {                               // merge data
		if (a[l] <= a[r]) {                   // if a[l] <= a[r]
			b[o++] = a[l++];                //   copy a[l]
			if (l < rr)                      //   if not end of left run
				continue;                   //     continue (back to while)
			do                              //   else copy rest of right run
				b[o++] = a[r++];
			while (r < ee);
			break;                          //     and return
		}
		else {                            // else a[l] > a[r]
			b[o++] = a[r++];                //   copy a[r]
			if (r < ee)                      //   if not end of right run
				continue;                   //     continue (back to while)
			do                              //   else copy rest of left run
				b[o++] = a[l++];
			while (l < rr);
			break;                          //     and return
		}
	}
}

void BottomUpCopy(int a[], int b[], size_t ll, size_t rr)
{
	do                                      // copy left run
		b[ll] = a[ll];
	while (++ll < rr);
}

size_t GetPassCount(size_t n)               // return # passes
{
	size_t i = 0;
	for (size_t s = 1; s < n; s <<= 1)
		i += 1;
	return(i);
}