#include "Stack.h"


void Stack::Push(int item)
{
	// not full
	if (!isFull()) {
		// 추가
		++top;
		stack[top] = item;
	}
	else
	{
		std::cout << "추가하지 못함" << std::endl;
	}
}

int Stack::Pop()
{
	if (!isEmpty())
		return stack[top--];
	else
		return NULL;
}

int Stack::Peek()
{
	if (!isEmpty())
		return stack[top];
	else
		return NULL;
}

bool Stack::isEmpty()
{
	if (top < 0)
		return true;
	else
		return false;
}

bool Stack::isFull()
{
	if (top >= MAX_STACK_SIZE)
		return true;
	else
		return false;
}

void Stack::Print()
{
	if (!isEmpty())
	{
		for (int i = 0; i <= top; ++i)
			std::cout << stack[i] << " ";
		std::cout << std::endl;
	}
	else {
		std::cout << "not element" << std::endl;
	}
}
