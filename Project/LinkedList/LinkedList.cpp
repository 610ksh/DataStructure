#include "LinkedList.h"


// �ʱ�ȭ
LinkedList::LinkedList()
{
	// ���̳�带 ����Ų��.
	head = new Node;
	head->next = nullptr;
	head->data = -9999999; // -1�� �׳� �ʱ�ȭ
	size = 0;
}

// ����
LinkedList::~LinkedList()
{
	// ����� �ƴϸ�, �����Ҷ� �տ������� �ϴ°� ������.
	for (int i = 0, j = size; i < j; ++i) {
		Remove(0);
	}
	delete head;
	head = nullptr;
}

void LinkedList::Push_back(const int & item)
{
	Node* preNode = head;
	// ������ ��� ������ �̵�
	while (!(preNode->next == nullptr)) {
		preNode = preNode->next;
	}
	// ���� ��忡 ���� ����
	preNode->next = new Node;
	preNode->next->data = item;
	preNode->next->next = nullptr;
	++size;

	/*
		���̳�尡 ������ �ڵ�
	*/
	//// �� �����
	//if (IsEmpty()) {
	//	//Node* newNode = new Node;
	//	head = new Node;
	//	head->data = item;
	//	head->next = nullptr;
	//	++size;
	//}
	//else {
	//	Node* curNode = head;
	//	// ����-1 ��ŭ ��� �̵�
	//	for (int i = 0; i < size - 1; ++i) {
	//		curNode = curNode->next;
	//	}
	//	curNode->next = new Node;
	//	curNode->next->data = item;
	//	curNode->next->next = nullptr;
	//	++size;
	//}
}

void LinkedList::Insert(const int & pos, const int & item)
{
	// ������ 
	if (pos < 0) {
		std::cout << "error, pos is not positive index" << std::endl;
		return;
	}
	// ������� ū ���� ����
	if (size <= pos) {
		Push_back(item);
		return;
	}
	else {
		Node* preNode = head;
		for (int i = 0; i < pos; ++i) {
			preNode = preNode->next;
		}
		// ���� ��� ����
		Node* insertNode = new Node;
		insertNode->data = item;
		// ���� ��带 ���� ���� ����
		insertNode->next = preNode->next;
		// ���� ��带 ���ο� ��忡 ����
		preNode->next = insertNode;
		++size;
	}

	/*
		���̳�尡 ������ �ڵ�
	*/
	//// �������
	//if (IsEmpty()) {
	//	std::cout << "list is empty" << std::endl;
	//	return;
	//}
	//// ��ü ������� ū ���� �����Ҷ�
	//if (size <= pos) {
	//	// �� �ڿ� �߰��Ѵ�.
	//	Push_back(item);
	//	return;
	//}
	//// 0��° ����
	//if (pos == 0) {
	//	Node* insertNode = new Node;
	//	insertNode->data = item;
	//	insertNode->next = head;
	//	head = insertNode;
	//	++size;
	//}
	//// �� �̻� ����
	//else {
	//	Node* insertNode = new Node;
	//	insertNode->data = item;
	//	Node* preNode = head; // ���� ���� ���
	//	for (int i = 0; i < pos - 1; ++i) {
	//		preNode = preNode->next;
	//	}
	//	insertNode->next = preNode->next;
	//	preNode->next = insertNode;
	//	++size;
	//}
}


void LinkedList::Remove(const int & pos)
{
	// ������ 
	if (pos < 0) {
		std::cout << "error, pos is not positive index" << std::endl;
		return;
	}
	// 
	if (size <= pos) {
		std::cout << "Out of range. current list size is : " << size << std::endl;
		return;
	}
	else {
		Node* preNode = head;
		for (int i = 0; i < pos; ++i) {
			preNode = preNode->next;
		}
		// ���� ��� ����
		Node* delNode = preNode->next;

		// ������ ��带 �����Ѵٸ�
		if (pos == size - 1) {
			preNode->next = nullptr;
		}
		else {
			preNode->next = delNode->next;
		}
		// ������� ���ķ� �翬��
		// ������� ����
		delete delNode;
		--size;
	}

	/*
		���̳�尡 ������ �ڵ�
	*/
	//// �������
	//if (IsEmpty()) {
	//	head = new Node;
	//	head->next = nullptr;
	//	--size;
	//	return;
	//}
	//if (size <= pos) {
	//	std::cout << "out of size. current list size is : " << size << std::endl;
	//	return;
	//}
	//// 0��° ����
	//if (pos == 0) {
	//	Node* preNode = head;
	//	head = head->next;
	//	delete preNode;
	//	--size;
	//}
	//// �� �̻� ����
	//else {
	//	Node* preNode = head;
	//	for (int i = 0; i < pos - 1; ++i) {
	//		preNode = preNode->next;
	//	}
	//	Node* deleteNode = preNode->next;
	//	if (!(deleteNode->next == nullptr)) {
	//		preNode->next = deleteNode->next;
	//		delete deleteNode;
	//	}
	//	else {
	//		preNode->next = nullptr;
	//		delete deleteNode;
	//	}
	//	--size;
	//}
}

int LinkedList::GetEntry(const int & pos)
{
	Node* preNode = head;
	for (int i = 0; i < pos; ++i) {
		preNode = preNode->next;
	}
	return preNode->next->data;
}

// ����Ž�� O(n)
bool LinkedList::Find(const int & item)
{
	Node* preNode = head;
	for (int i = 0; i < size; ++i) {
		if (preNode->next->data == item) {
			std::cout << "index : " << i << std::endl;
			return true;
		}
		preNode = preNode->next;
	}
	std::cout << "not exist" << std::endl;
	return false;

	/*
		���̳�尡 ������ �ڵ�
	*/
	//// ù��° �˻�
	//Node* curNode = head;
	//if (curNode->data == item) {
	//	std::cout << "Find it, index : 0" << std::endl;
	//	return true;
	//}
	//// �ι�°���� �˻�
	//for (int i = 0; i < size - 1; ++i) {
	//	curNode = curNode->next;
	//	if (curNode->data == item) {
	//		std::cout << "Find it, index : " << i + 1 << std::endl;
	//		return true;
	//	}
	//}
	//std::cout << "not exist" << std::endl;
	//return false;
}

bool LinkedList::IsEmpty()
{
	if (head->next == nullptr)
		return true;
	return false;
}

int LinkedList::GetSize()
{
	return size;
}

void LinkedList::Print()
{
	Node* preNode = head;
	for (int i = 0; i < size; ++i) {
		printf("[%d] ", preNode->next->data);
		preNode = preNode->next;
	}
	printf("\n");
}

void LinkedList::Clear()
{
	LinkedList::~LinkedList();
}
