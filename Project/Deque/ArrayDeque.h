#pragma once
#include <iostream>

// array max size
const int MAX_SIZE = 10;

class ArrayDeque
{
private:
	int deque[MAX_SIZE] = { 0 };
	int front; // ¾Õ
	int rear; // ²¿¸®(tail)

	int size;

public:
	ArrayDeque();
	~ArrayDeque();

	void Push_back(const int& data);
	void Push_front(const int& data);
	void Pop_back();
	void Pop_front();
	int GetFront();
	int GetBack();
	bool isEmpty();
	bool isFull();
	void Print();
	const int& Size();
};

