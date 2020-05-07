#include "Heap.h"

/*
	Priority Queue(우선순위 큐)에 사용되는 heap 자료구조.
	Min heap을 기준으로 만듦.
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