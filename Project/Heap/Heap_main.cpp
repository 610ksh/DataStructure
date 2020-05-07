#include "Heap.h"

/*
	Priority Queue(�켱���� ť)�� ���Ǵ� heap �ڷᱸ��.
	Min heap�� �������� ����.
	September 1, 2019
	Copyright 2019. SungHoon Kim. All rights reserved.
*/

int main()
{
	Heap heap;
	heap.Insert('A');
	heap.Insert('a');
	heap.Insert('A');
	heap.Insert('B');
	heap.Insert('C');
	heap.Insert('D');

	while (!heap.IsEmpty()) {
		printf("%c \n", heap.Delete());
	}

	std::cout << "Hello Heap" << std::endl;


	return 0;
}