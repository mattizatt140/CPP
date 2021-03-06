// Implementation of Data Structures Module 3 GPA2.cpp : Defines the entry point for the console application.
// Program creates Queue which can track and delete middle elemenet

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

struct DLLNode {
	struct DLLNode *prev;
	int data;
	struct DLLNode *next;
};

struct myQueue {
	struct DLLNode *head;
	struct DLLNode *tail;
	struct DLLNode *mid;
	int count;
};

struct myQueue *createMyQueue() {
struct myQueue *mq = (struct myQueue*) malloc(sizeof(struct myQueue));
mq->count = 0;
mq->head = NULL;
mq->tail = NULL;
mq->mid = NULL;
return mq;
}; 

void push(struct myQueue *mq, int new_data) {

	struct DLLNode* new_DLLNode = (struct DLLNode*) malloc(sizeof(struct DLLNode));
	new_DLLNode->data = new_data;
	mq->count++;
	new_DLLNode->next = NULL;
	if (mq->head == NULL) { //link data together at construction
		mq->head = mq->mid = mq->tail = new_DLLNode;
		mq->mid->next = mq->tail;
		mq->mid->prev = mq->head;
		mq->tail->prev = mq->mid;
		return;
	}
	else { //link new node to tail and reasign tail
		mq->tail->next = new_DLLNode;
		new_DLLNode->prev = mq->tail;
		mq->tail = new_DLLNode;
	}
	if ((mq->count > 1) && (mq->count % 2 == 1)) { //if count is odd, then mid moves 1 over
		mq->mid = mq->mid->next;
	}
}

int pop(struct myQueue *mq) {

	struct DLLNode *head = mq->head;
	int item = head->data;
	if (mq->head == NULL) { //cancel function if no elements
		return 0;
	}
	mq->count--;
	if (mq->head == mq->tail) { //delete only item
		free(head);
		mq->head = NULL;
		return item;
	}
	else {
		mq->head = mq->head->next; //new head is previous 2nd element
	}
	if (mq->count % 2 == 1) { 
		mq->mid = mq->mid->next;
	}
	free(head);
	return item;
}

int findMiddle(struct myQueue *mq) {
	if (mq->count == 0) {
		return 0;
	}
	if (mq->count == 2) {
		mq->mid = mq->head;
	}
	return mq->mid->data;
}

int deleteMiddle(struct myQueue *mq) {
	int data;
	
	switch (mq->count) {
		case 0: {
			return 0;
		}
		case 1: {
			data = mq->head->data;
			delete mq->head;
		
			mq->head = mq->mid = mq->tail = NULL;
			
			mq->count--;
			return data;
		}
		case 2: {
			data = mq->head->data;
			mq->head = mq->mid = mq->tail;
			
			mq->head->prev = NULL;
			mq->head->next = mq->mid;
			mq->mid->prev = mq->head;
			mq->mid->next = mq->tail;
			mq->tail->prev = mq->mid;
			mq->tail->next = NULL;

			mq->count--;
			return data;
		}
		case 3: {
			data = mq->mid->data;
			mq->mid = mq->head;
			mq->mid->prev = NULL;
			mq->mid->next = mq->tail;

			mq->count--;
			return data;
		}
		default: {
			data = mq->mid->data;
			mq->mid->next->prev = mq->mid->prev;
			mq->mid->prev->next = mq->mid->next;
			
			if (mq->count % 2 == 1) {
				mq->mid = mq->mid->prev;
			}
			if (mq->count % 2 == 0) {
				mq->mid = mq->mid->next;
			}
			mq->count--;
			return data;
		}
	}
}

int main()
{
	myQueue *queue;
	queue = createMyQueue();
	push(queue, 1);
	push(queue, 2);
	push(queue, 3);
	push(queue, 4);
	push(queue, 5);
	push(queue, 6);
	push(queue, 7);

	cout << deleteMiddle(queue) << endl;
	cout << deleteMiddle(queue) << endl;
	delete queue;
}