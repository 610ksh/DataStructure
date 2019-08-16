#include "ArrayDeque.h"

/*
	2019. August, 16.
	ArrayQueue complete.

	¡Ø Notice
	(rear - 1 + MAX_SIZE) % MAX_SIZE;
*/

int main()
{
	ArrayDeque arrDeque;
	arrDeque.Print(); // empty
	arrDeque.Pop_back(); // empty
	arrDeque.Pop_front(); // empty
	arrDeque.GetBack(); // empty
	arrDeque.GetFront(); // empty

	arrDeque.Push_back(1); // enqueue 1
	arrDeque.Push_front(2); // enqueue 2
	arrDeque.Push_back(3); // enqueue 3
	arrDeque.Push_front(4); // enqueue 4

	arrDeque.Print(); // 4 2 1 3
	std::cout << "Current size of queue is : " << arrDeque.Size() << std::endl; // 4
	arrDeque.Pop_front(); // dequeue 4
	std::cout << "Current front is : " << arrDeque.GetFront() <<
		" Current back is : " << arrDeque.GetBack() << std::endl; // 2, 3
	arrDeque.Pop_back(); // dequeue 3
	arrDeque.Print(); // 2 1
	std::cout << "Current size of queue is : " << arrDeque.Size() << std::endl; // 2

	return 0;
}