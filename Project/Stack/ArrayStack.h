#pragma once

/*
	���ø��� .h�� .cpp�� ������ ����.

*/

#include <iostream>

const int MAX_STACK_SIZE = 10;

class ArrayStack
{
private:
	int stack[MAX_STACK_SIZE];
	int top = -1;
	
public:
	void Push(int item);
	int Pop();
	int Peek();
	bool isEmpty();
	bool isFull();
	void Print();
};