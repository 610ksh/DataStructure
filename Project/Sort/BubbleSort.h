#pragma once

#include <iostream>

/*
	Notice
	- O(n^2)
	- 실제로 가장 느린 알고리즘

	Method
	- 현재 인덱스와 다음 인덱스를 비교해서
	작은것은 왼쪽, 큰것은 오른쪽으로 교체해간다.
	- 한번 끝까지 진행하면, 맨 오른쪽에는 가장 큰 값이 지정.
	- 다음에 시작할때는 범위를 하나 줄여서 다시 진행한다.
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
			// 점점 범위를 좁혀감. 앞의 i를 이용해서 조건문을 만듦
			for (int j = 0; j < i; ++j)
			{
				// 처음부터 2개씩 비교하면서 더 작은값을 발견하면 교체 
				if (copyArr[j] > copyArr[j + 1])
				{
					temp = copyArr[j];
					copyArr[j] = copyArr[j + 1];
					copyArr[j + 1] = temp;
				}
			}
			Print(copyArr, length);
		}

		// 최종 출력
		std::cout << "Result : ";
		Print(copyArr, length);

		std::cout << "Bubble Sort End\n\n";
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