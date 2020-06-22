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

void SelectionSort(int arr[], const int& length)
{
	std::cout << "Selection Sort start\n";
	int minIndex = 0, temp = 0;

	for (int i = 0; i < length; ++i)
	{
		minIndex = i;
		for (int j = i + 1; j < length; ++j)
		{
			// �־��� ����Ʈ�߿� �ּҰ��� ���� �ε����� ã�´�
			if (arr[minIndex] > arr[j])
				minIndex = j;
		}
		// �� ���� �� �տ� ��ġ�� ���� ��ü�Ѵ�.
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;

		// �� ó���� ������ �������� �ٽ� �����Ѵ�.
	}

	// ���
	for (int i = 0; i < length; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout << "Selection Sort End\n\n";
}