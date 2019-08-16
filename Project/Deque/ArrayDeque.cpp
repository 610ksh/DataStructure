#include "ArrayDeque.h"



ArrayDeque::ArrayDeque()
{
	// 같은 곳을 가리키는게 핵심
	front = 0;
	rear = 0;
	size = 0;
}


ArrayDeque::~ArrayDeque()
{
}

void ArrayDeque::Push_back(const int & data)
{
	// if full
	if (isFull()) {
		std::cout << "Deque is full" << std::endl;
		return;
	}

	// rear + 1, input data
	rear = (rear + 1) % MAX_SIZE;
	deque[rear] = data;
	size++;
	std::cout << "Data push_back success : " << data << std::endl;
}

void ArrayDeque::Push_front(const int& data)
{
	// if full
	if (isFull()) {
		std::cout << "Deque is full" << std::endl;
		return;
	}

	// 현재 front에 input
	deque[front] = data;
	size++;
	// front 이동. front - 1
	front = (front - 1 + MAX_SIZE) % MAX_SIZE;
	std::cout << "Data push_front success : " << data << std::endl;
}

// stack's pop
void ArrayDeque::Pop_back()
{
	// if Empty
	if (isEmpty()) {
		std::cout << "Deque is empty" << std::endl;
		return;
	}
	
	// 먼저 해제 시키고
	std::cout << "Data pop_back success : " << deque[rear] << std::endl;
	deque[rear] = 0;
	size--;

	// rear move to previous
	rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
}

// same as dequeue
void ArrayDeque::Pop_front()
{
	// if Empty
	if (isEmpty()) {
		std::cout << "Deque is empty" << std::endl;
		return;
	}

	// front move to next
	front = (front + 1) % MAX_SIZE;
	std::cout << "Data pop_front success : " << deque[front] << std::endl;
	deque[front] = 0;
	size--;
}

int ArrayDeque::GetFront()
{
	// if Empty
	if (isEmpty()) {
		std::cout << "Deque is empty" << std::endl;
		return -1;
	}

	return deque[(front + 1) % MAX_SIZE];
}

int ArrayDeque::GetBack()
{
	// if Empty
	if (isEmpty()) {
		std::cout << "Deque is empty" << std::endl;
		return -1;
	}

	return deque[rear];
}

bool ArrayDeque::isEmpty()
{
	// f = r
	if (front == rear)
		return true;
	return false;
}

bool ArrayDeque::isFull()
{
	// f = (r + 1) % MAX_SIZE
	if (front == (rear + 1) % MAX_SIZE)
		return true;
	return false;
}

void ArrayDeque::Print()
{
	// if Empty
	if (isEmpty()) {
		std::cout << "Deque is empty" << std::endl;
		return;
	}

	for (int i = front; i != rear; i = (i + 1) % MAX_SIZE)
	{
		std::cout << deque[(i + 1) % MAX_SIZE] << " ";
	}
	std::cout << std::endl;
}

const int & ArrayDeque::Size()
{
	return size;
}
