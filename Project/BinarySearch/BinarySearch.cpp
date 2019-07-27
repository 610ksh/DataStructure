#include "BinarySearch.h"

void BinarySearch(std::vector<unsigned int> &vec)
{
	// first, last, mid, // 배열의 인덱스를 적음.
	unsigned int first = 0, last = vec.size() - 1, mid = 0;
	// 찾는 횟수 카운팅
	unsigned int count = 0;
	// 찾는 수 targit
	unsigned int targit = 0;
	// 찾는 수 검색
	std::cin >> targit;
	std::cout << "Length of array is " << vec.size() << std::endl << std::endl;

	// 역전될때까지
	while (first <= last)
	{
		// mid 수정
		mid = (first + last) / 2;

		// mid == targit
		if (vec[mid] == targit)
		{
			count++;
			std::cout << "Find it! count is " << count << std::endl;
			std::cout << "number of order is " << mid + 1 << std::endl;
			return;
		}
		// mid > targit
		else if (vec[mid] > targit)
		{
			// 탐색 카운트
			count++;
			// last 수정
			last = mid - 1;
		}
		// mid < targit
		else
		{
			// 탐색 카운트
			count++;
			// first 수정
			first = mid + 1;
		}
	}

	std::cout << "Not find targit" << std::endl;
	return;
}
