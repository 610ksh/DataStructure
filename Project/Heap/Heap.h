#pragma once
#include <iostream>


typedef int PriorityComp(const char& ch1, const char& ch2);

/*
	Min Heap�� ���� ����.
*/

class Heap
{
private:
	PriorityComp* comp;
	int numOfData;
	int heapArr[100];

public:
	Heap();

	bool IsEmpty();
	void Insert(const char& data);
	int Delete();

	int GetParentIDX(const int& idx);
	int GetLChildIDX(const int& idx);
	int GetRChildIDX(const int& idx);
	// �켱������ �� ���� �ڽ��� ��ȯ
	int GetHighPriChildIDX(const int& idx);
};