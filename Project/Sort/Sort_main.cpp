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
	Shuffle(arr, length); // �����ϰ� ����
	std::cout << "������ �迭�� : ";
	Print(arr, length); // ���
	
	selection::SelectionSort(arr, length);
	bubble::BubbleSort(arr, length);
	
	return 0;
}