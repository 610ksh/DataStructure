#pragma once

#include <iostream>

// array max size
const int MAX_SIZE = 10;

class ArrayQueue
{
private:
	int queue[MAX_SIZE] = {0};
	int front; // ¾Õ
	int rear; // ²¿¸®(tail)

	int size;

public:
	ArrayQueue();
	~ArrayQueue();

	void Enqueue(const int& data);
	void Dequeue();
	int Peek();
	bool isEmpty();
	bool isFull();
	void Print();
	const int& Size();

};

