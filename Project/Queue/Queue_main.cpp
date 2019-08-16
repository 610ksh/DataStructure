#include "ArrayQueue.h"

/*
	2019. August, 16.
	ArrayQueue complete.

	¡Ø Notice
	(rear + 1) % MAX_SIZE)
*/

int main()
{
	ArrayQueue arrQueue;
	arrQueue.Print(); // empty
	arrQueue.Dequeue(); // empty
	arrQueue.Peek(); // empty

	arrQueue.Enqueue(1); // enqueue 1
	arrQueue.Enqueue(2); // enqueue 2
	arrQueue.Enqueue(3); // enqueue 3
	arrQueue.Enqueue(4); // enqueue 4

	arrQueue.Print(); // 1 2 3 4
	std::cout << "Current size of queue is : " << arrQueue.Size() << std::endl; // 4
	arrQueue.Dequeue(); // dequeue 1
	std::cout << "Current front is : " << arrQueue.Peek() << std::endl; // 2
	arrQueue.Print(); // 2 3 4
	std::cout << "Current size of queue is : " << arrQueue.Size() << std::endl; // 3


	return 0;
}