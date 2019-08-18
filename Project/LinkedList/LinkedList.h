#pragma once
#include <iostream>
#include <list> // ���� ���� ����Ʈ

struct Node {
	// ���� ������
	int data;
	// ���� ��� �ּҸ� ����Ű�� ����
	Node* next;
};

// �ܹ��� ���Ḯ��Ʈ
class LinkedList
{
private:
	// �Ӹ���ġ
	Node* head;
	//Node* tail;
	int size;

public:
	// ����
	void Insert(const int& pos, const int& item);
	void Push_back(const int & item);
	// ����
	void Remove(const int& pos);
	// �б�
	int GetEntry(const int& pos);
	// �˻�
	int Find(const int& item);
	// �������
	bool IsEmpty();
	// ���� �������?
	int GetSize();
	// ���
	void Print();

public:
	LinkedList();
	~LinkedList();
};

