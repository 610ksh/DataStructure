#pragma once

#include <iostream>

/*
	Notice
	- O(n^2)
	- ������ ���� ���� �˰���

	Method
	- ���� �ε����� ���� �ε����� ���ؼ�
	�������� ����, ū���� ���������� ��ü�ذ���.
	- �ѹ� ������ �����ϸ�, �� �����ʿ��� ���� ū ���� ����.
	- ������ �����Ҷ��� ������ �ϳ� �ٿ��� �ٽ� �����Ѵ�.
*/

void BubbleSort(int arr[], const int& length)
{
	std::cout << "Bubble Sort start\n";

	int temp = 0;
	for (int i = length - 1; i > 0; --i)
	{
		// ���� ������ ������. ���� i�� �̿��ؼ� ���ǹ��� ����
		for (int j = 0; j < i; ++j)
		{
			// ó������ 2���� ���ϸ鼭 �� �������� �߰��ϸ� ��ü 
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	// ���
	for (int i = 0; i < length; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;

	std::cout << "Bubble Sort End\n\n";
}