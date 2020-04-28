#pragma once

#include <iostream>
#include <vector> // 연결리스트를 활용

#define MAX_VERTEX 256

/*
	2. Adjacency List (인접 리스트 방식)

*/

class AdjList
{
	int size;
	char vertices[MAX_VERTEX];
	std::vector<std::vector<int>> vNode; // 리스트 배열 (헤더 포인터라고 부름)

public:
	AdjList();
	bool IsEmpty();
	bool IsFull();
	void InsertVertex(char v);
	void DeleteVertex(int v);
	void InsertEdge(int u, int v);
	void DeleteEdge(int u, int v);
	std::vector<int> Adjacent(int v);
	void Print();
};