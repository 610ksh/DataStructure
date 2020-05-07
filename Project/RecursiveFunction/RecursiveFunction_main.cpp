#include "RecursiveFunction.h"

/*

	Copyright 2019. SungHoon Kim.All rights reserved.
*/

int main()
{
	std::cout << "This program is about recursive function" << std::endl << std::endl;
	RecursiveFunction test;

	std::cout << "Fibonacci 10	: " << test.Fibonacci(10) << std::endl;
	std::cout << "Factorial 5	: " << test.Factorial(5) << std::endl;

	return 0;
}