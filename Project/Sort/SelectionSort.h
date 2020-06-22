#pragma once

#include <iostream>

/*
	Notice
	- O(n^2)
	- bubble 다음으로 가장 느린 알고리즘

	Method
	1. 주어진 리스트중에 최소값을 갖는 인덱스를 찾는다
	2. 그 값을 맨 앞에 위치한 값과 교체한다.
	3. 맨 처음을 제외한 나머지를 다시 실행한다.
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
				// 주어진 리스트중에 최소값을 갖는 인덱스를 찾는다
				if (copyArr[minIndex] > copyArr[j])
					minIndex = j;
			}
			// 그 값을 맨 앞에 위치한 값과 교체한다.
			temp = copyArr[i];
			copyArr[i] = copyArr[minIndex];
			copyArr[minIndex] = temp;
			Print(copyArr, length);
			// 맨 처음을 제외한 나머지를 다시 실행한다.
		}

		// 최종 출력
		Print(copyArr, length);
		std::cout << "Selection Sort End\n\n";
		delete[] copyArr;
	}

	void Print(int arr[], const int& length)
	{
		// 출력
		for (int i = 0; i < length; ++i)
			std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
}