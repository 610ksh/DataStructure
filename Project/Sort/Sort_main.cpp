#include "SelectionSort.h"
#include "BubbleSort.h"


/*
	June 22, Mon
	- Selection sort
	- Bubble sort



	Copyright 2020, SungHoon Kim, All rights reserved.
*/

int main()
{
	int arr[5]{ 5,3,6,1,4 };

	SelectionSort(arr, 5);
	BubbleSort(arr, 5);

	return 0;
}