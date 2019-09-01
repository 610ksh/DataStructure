#pragma once
#include <iostream>


typedef int PriorityComp(const char& ch1, const char& ch2);

/*
	Min Heap을 토대로 만듦.
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
	// 우선순위가 더 높은 자식을 반환
	int GetHighPriChildIDX(const int& idx);
};