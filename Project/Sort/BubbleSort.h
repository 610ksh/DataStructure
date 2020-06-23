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

namespace bubble
{
	void Print(int arr[], const int& length);

	void BubbleSort(const int arr[], const int& length)
	{
		// copy
		int* copyArr = new int[length];
		std::copy(arr, arr + length, copyArr);

		std::cout << "Bubble Sort start\n";
		Print(copyArr, length);

		int temp = 0;
		for (int i = length - 1; i > 0; --i)
		{
			// ���� ������ ������. ���� i�� �̿��ؼ� ���ǹ��� ����
			for (int j = 0; j < i; ++j)
			{
				// ó������ 2���� ���ϸ鼭 �� �������� �߰��ϸ� ��ü 
				if (copyArr[j] > copyArr[j + 1])
				{
					temp = copyArr[j];
					copyArr[j] = copyArr[j + 1];
					copyArr[j + 1] = temp;
				}
			}
			Print(copyArr, length);
		}

		// ���� ���
		std::cout << "Result : ";
		Print(copyArr, length);

		std::cout << "Bubble Sort End\n\n";
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