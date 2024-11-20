// DataStructures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Queue.h"
#include <iostream>
#include <sstream>
#include <windows.h>

void initQueue(Queue* q, unsigned int size) {
	q->arr = new int[size];
	q->maxsize = size;
	q->size = 0;
}

void cleanQueue(Queue* q) {
	delete[] q->arr;
	q->arr = NULL;
}

void enqueue(Queue* q, unsigned int value) {
	if (q->maxsize > q->size) {
		int insert = q->size;
		q->arr[insert] = value;
		q->size++;
	}
}

int dequeue(Queue* q) {
	if (q->size == 0) return -1;

	int saved = q->arr[0];
	for (int i = 0; i < q->size -1; i++)
		q->arr[i] = q->arr[i + 1];

	q->size--;
	return saved;
}

bool isEmpty(Queue* q) {
	return q->size == 0;
}

bool isFull(Queue* q) {
	return q->size == q->maxsize;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
