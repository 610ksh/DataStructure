#pragma once

#include <iostream>

/*
	Notice
	- O(n^2)
	- bubble �������� ���� ���� �˰���

	Method
	1. �־��� ����Ʈ�߿� �ּҰ��� ���� �ε����� ã�´�
	2. �� ���� �� �տ� ��ġ�� ���� ��ü�Ѵ�.
	3. �� ó���� ������ �������� �ٽ� �����Ѵ�.
*/

namespace selection
{
	void Print(int arr[], const int& length);

	void SelectionSort(const int arr[], const int& length)
	{
		// copy
		int* copyArr = new int[length];
		std::copy(arr, arr + length, copyArr);

		std::cout << "Selection Sort start\n";
		Print(copyArr, length);

		int minIndex = 0, temp = 0;
		for (int i = 0; i < length; ++i)
		{
			minIndex = i;
			for (int j = i + 1; j < length; ++j)
			{
				// �־��� ����Ʈ�߿� �ּҰ��� ���� �ε����� ã�´�
				if (copyArr[minIndex] > copyArr[j])
					minIndex = j;
			}
			// �� ���� �� �տ� ��ġ�� ���� ��ü�Ѵ�.
			temp = copyArr[i];
			copyArr[i] = copyArr[minIndex];
			copyArr[minIndex] = temp;
			Print(copyArr, length);
			// �� ó���� ������ �������� �ٽ� �����Ѵ�.
		}

		// ���� ���
		Print(copyArr, length);
		std::cout << "Selection Sort End\n\n";
		delete[] copyArr;
	}

	void Print(int arr[], const int& length)
	{
		// ���
		for (int i = 0; i < length; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
}