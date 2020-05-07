#include "ArrayStack.h"
/*

	Copyright 2019. SungHoon Kim.All rights reserved.
*/

int main()
{
	ArrayStack stack;
	std::cout << stack.Peek() << std::endl;
	stack.Push(10);
	std::cout << stack.Peek() << std::endl;
	stack.Print();
	std::cout << stack.Pop() << std::endl;
	std::cout << stack.Peek() << std::endl;
	stack.Print();
	return 0;
}