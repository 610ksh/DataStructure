#include "SelectionSort.h"
#include "BubbleSort.h"
#include "Shuffle.h"


/*
	June 22, Mon
	- Selection sort
	- Bubble sort



	Copyright 2020, SungHoon Kim, All rights reserved.
*/

int main()
{
	int arr[10]{ 1,2,3,4,5,6,7,8,9,10 };
	int length = sizeof(arr) / sizeof(int);
	Shuffle(arr, length); // 랜덤하게 셔플
	std::cout << "최초의 배열은 : ";
	Print(arr, length); // 출력
	
	selection::SelectionSort(arr, length);
	bubble::BubbleSort(arr, length);
	
	return 0;
}