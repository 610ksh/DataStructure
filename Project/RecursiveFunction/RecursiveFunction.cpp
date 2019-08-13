#include "RecursiveFunction.h"



RecursiveFunction::RecursiveFunction()
{
}


RecursiveFunction::~RecursiveFunction()
{
}

uint32_t RecursiveFunction::Fibonacci(const uint32_t & input)
{
	if (input == 1)
		return 1;
	if (input == 2)
		return 1;

	return Fibonacci(input - 1) + Fibonacci(input - 2);
}


uint32_t RecursiveFunction::Factorial(const uint32_t & input)
{
	if (input <= 1)
		return 1;

	return Factorial(input - 1) * input;
}