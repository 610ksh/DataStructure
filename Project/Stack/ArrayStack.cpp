#include "ArrayStack.h"


void ArrayStack::Push(int item)
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

int ArrayStack::Pop()
{
	if (!isEmpty())
		return stack[top--];
	else
		return NULL;
}

int ArrayStack::Peek()
{
	if (!isEmpty())
		return stack[top];
	else
		return NULL;
}

bool ArrayStack::isEmpty()
{
	if (top < 0)
		return true;
	else
		return false;
}

bool ArrayStack::isFull()
{
	if (top >= MAX_STACK_SIZE)
		return true;
	else
		return false;
}

void ArrayStack::Print()
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
