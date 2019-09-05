#include "RecursiveFunction.h"

uint32_t RecursiveFunction::Fibonacci(const uint32_t & input)
{
	//// base case(��������)
	//if (input == 0)
	//	return 0;
	//if (input == 1)
	//	return 1;

	// ���� �ΰ��� ��ģ��.
	if (input <= 1)
		return input;

	return Fibonacci(input - 1) + Fibonacci(input - 2);
}


uint32_t RecursiveFunction::Factorial(const uint32_t & input)
{
	// base case(��������)
	if (input <= 1)
		return 1;

	return input * Factorial(input - 1);
}

uint32_t RecursiveFunction::GCD(uint32_t a, uint32_t b)
{
	if (b == 0)
		return a;
	return GCD(b, a%b);
}