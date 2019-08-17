#pragma once
#include <iostream>

// arrayList�� ���� ū ������ ����� �����Ǿ� �ִٴ���.
const int MAX_SIZE = 10;

class ArrayList
{
private:
	// int�� �迭�� ��Ҵ�. ���ø��� ����ϸ� ���ǿ� ������ ���ľ��ϱ� ������ ���ŷο�.
	int arrList[MAX_SIZE] = { -1 };
	// ������ 0�̴�. �ִ� MAX_SIZE �������� ��������.
	int length;
public:
	/* ADT */

	// �⺻ ������
	ArrayList() { length = 0; }
	// ����
	void Insert(const int& pos, const int& item);
	// ����
	void Remove(const int& pos);
	// �б�
	int GetEntry(const int& pos);
	// �˻�
	int Find(const int& item);
	// ����á����
	bool IsFull();
	// �������
	bool IsEmpty();
	// ���� �������?
	int GetSize();
	// ���
	void Print();
};

