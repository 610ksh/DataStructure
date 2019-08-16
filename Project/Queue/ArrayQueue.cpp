#include "ArrayQueue.h"

ArrayQueue::ArrayQueue()
{
	// 같은 곳을 가리키는게 핵심
	front = 0;
	rear = 0;
	size = 0;
}

ArrayQueue::~ArrayQueue()
{
}

void ArrayQueue::Enqueue(const int& data)
{
	// if full
	if (isFull()) {
		std::cout << "Queue is full" << std::endl;
		return;
	}

	// rear + 1, input data
	rear = (rear + 1) % MAX_SIZE;
	queue[rear] = data;
	size++;
	std::cout << "Data enqueue success : " << data << std::endl;
}

void ArrayQueue::Dequeue()
{
	// if Empty
	if (isEmpty()) {
		std::cout << "Queue is empty" << std::endl;
		return;
	}
	
	// front move to next
	front = (front + 1) % MAX_SIZE;
	std::cout << "Data dequeue success : " << queue[front] << std::endl;
	queue[front] = 0;
	size--;
}

int ArrayQueue::Peek()
{
	// if Empty
	if (isEmpty()) {
		std::cout << "Queue is empty" << std::endl;
		return -1;
	}

	return queue[(front + 1) % MAX_SIZE];
}

bool ArrayQueue::isEmpty()
{
	// f = r
	if (front == rear)
		return true;	
	return false;
}

bool ArrayQueue::isFull()
{
	// f = (r + 1) % MAX_SIZE
	if (front == (rear + 1) % MAX_SIZE)
		return true;
	return false;
}

void ArrayQueue::Print()
{
	// if Empty
	if (isEmpty()) {
		std::cout << "Queue is empty" << std::endl;
		return;
	}

	for (int i = front; i != rear; i = (i + 1) % MAX_SIZE)
	{
		std::cout << queue[(i + 1) % MAX_SIZE] << " ";
	}
	std::cout << std::endl;
}

const int& ArrayQueue::Size()
{
	return size;
}
