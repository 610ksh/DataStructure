#include "LinkedList.h"



LinkedList::LinkedList()
{
	// ��尡 NULL
	head = NULL;
	size = 0;
}


LinkedList::~LinkedList()
{
}

void LinkedList::Insert(const int & pos, const int & item)
{
	// 
}


void LinkedList::Push_back(const int & item)
{
	// �� �����
	if (IsEmpty()){
		//Node* newNode = new Node;
		head = new Node;
		head->data = item;
		head->next = NULL;
		++size;
	}
	else {
		Node* curNode = head;
		// ����-1 ��ŭ ��� �̵�
		for (int i = 0; i < size-1; ++i) {
			curNode = curNode->next;
		}
		curNode->next = new Node;
		curNode->next->data = item;
		curNode->next->next = NULL;
		++size;
	}
}

void LinkedList::Remove(const int & pos)
{

}

int LinkedList::GetEntry(const int & pos)
{
	return 0;
}

int LinkedList::Find(const int & item)
{
	return 0;
}

bool LinkedList::IsEmpty()
{
	if (head == NULL)
		return true;
	return false;
}

int LinkedList::GetSize()
{
	return 0;
}

void LinkedList::Print()
{

}