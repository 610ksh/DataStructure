#include "BinarySearch.h"

void BinarySearch(std::vector<unsigned int> &vec)
{
	// first, last, mid, // �迭�� �ε����� ����.
	unsigned int first = 0, last = vec.size() - 1, mid = 0;
	// ã�� Ƚ�� ī����
	unsigned int count = 0;
	// ã�� �� targit
	unsigned int targit = 0;
	// ã�� �� �˻�
	std::cin >> targit;
	std::cout << "Length of array is " << vec.size() << std::endl << std::endl;

	// �����ɶ�����
	while (first <= last)
	{
		// mid ����
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
			// Ž�� ī��Ʈ
			count++;
			// last ����
			last = mid - 1;
		}
		// mid < targit
		else
		{
			// Ž�� ī��Ʈ
			count++;
			// first ����
			first = mid + 1;
		}
	}

	std::cout << "Not find targit" << std::endl;
	return;
}
