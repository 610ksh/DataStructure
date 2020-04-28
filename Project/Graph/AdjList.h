#pragma once

#include <iostream>
#include <vector> // ���Ḯ��Ʈ�� Ȱ��

#define MAX_VERTEX 256

/*
	2. Adjacency List (���� ����Ʈ ���)

*/

class AdjList
{
	int size;
	char vertices[MAX_VERTEX];
	std::vector<std::vector<int>> vNode; // ����Ʈ �迭 (��� �����Ͷ�� �θ�)

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