#pragma once

#include <iostream>
#include <random>

void Shuffle(int arr[], const int& length)
{
	std::random_device rd;
	std::mt19937 mersenne32(rd());
	std::uniform_int_distribution<> dice(0, length - 1);
	int ranNum1, ranNum2;

	// 30¹ø ¼¯±â
	for (int i = 0; i < 30; ++i)
	{
		ranNum1 = dice(mersenne32);
		ranNum2 = dice(mersenne32);
		std::swap(arr[ranNum1], arr[ranNum2]);
	}
}

void Print(int arr[], const int& length)
{
	// Ãâ·Â
	for (int i = 0; i < length; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}