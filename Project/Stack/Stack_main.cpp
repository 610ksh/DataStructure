#include "Stack.h"

int main()
{
	Stack stack;
	std::cout << stack.Peek() << std::endl;
	stack.Push(10);
	std::cout << stack.Peek() << std::endl;
	stack.Print();
	std::cout << stack.Pop() << std::endl;
	std::cout << stack.Peek() << std::endl;
	stack.Print();
	return 0;
}