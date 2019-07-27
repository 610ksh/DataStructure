/*
	Binary Search (���� Ž��)
	Big O : O(logN)
	
	Notes
	1. �ݵ�� ������ �Ǿ� �־�� ��.
	=> Quick sort O(N*logN), worst case : N^2
	2. 
*/
#include "BinarySearch.h"

int main()
{
	// �־��� �迭
	std::vector<unsigned int> vec = { 5,7,1,6,8,9,10,15,3,4,2,11,15,13,19,14};
	// �ݵ�� ������ �������.
	std::sort(vec.begin(), vec.end());
	// Binary Search
	BinarySearch(vec);

	return 0;
}