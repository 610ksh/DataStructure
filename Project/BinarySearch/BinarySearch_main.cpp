/*
	Binary Search (이진 탐색)
	Big O : O(logN)
	
	Notes
	1. 반드시 정렬이 되어 있어야 함.
	=> Quick sort O(N*logN), worst case : N^2
	2. 
*/
#include "BinarySearch.h"

int main()
{
	// 주어진 배열
	std::vector<unsigned int> vec = { 5,7,1,6,8,9,10,15,3,4,2,11,15,13,19,14};
	// 반드시 정렬을 해줘야함.
	std::sort(vec.begin(), vec.end());
	// Binary Search
	BinarySearch(vec);

	return 0;
}