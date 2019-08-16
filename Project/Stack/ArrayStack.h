#pragma once

/*
	템플릿은 .h와 .cpp를 나눌수 없다.

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