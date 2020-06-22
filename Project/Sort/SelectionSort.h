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

void SelectionSort(int arr[], const int& length)
{
	std::cout << "Selection Sort start\n";
	int minIndex = 0, temp = 0;

	for (int i = 0; i < length; ++i)
	{
		minIndex = i;
		for (int j = i + 1; j < length; ++j)
		{
			// 주어진 리스트중에 최소값을 갖는 인덱스를 찾는다
			if (arr[minIndex] > arr[j])
				minIndex = j;
		}
		// 그 값을 맨 앞에 위치한 값과 교체한다.
		temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;

		// 맨 처음을 제외한 나머지를 다시 실행한다.
	}

	// 출력
	for (int i = 0; i < length; ++i)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
	std::cout << "Selection Sort End\n\n";
}