#pragma once

#include <iostream>
#include <vector> // for ���Ḯ��Ʈ
#include <queue> // for BFS

#define MAX_VERTEX2 26 // ���� ���ĺ� ������ŭ

class AdjList
{
	int size; // ������ ����(���� ����)
	char vertices[MAX_VERTEX2]; // ������ �̸��� �ο��غ�(��� ū ������ ����)
	std::vector<std::vector<int>> vNode; // ����Ʈ �迭 (��� �����Ͷ�� �θ�)

	std::vector<bool> visited; // for DFS

	std::vector<bool> found; // for BFS
	std::vector<int> parent;
	std::queue<int> queue;

public:
	AdjList();
	~AdjList();
	bool IsEmpty();
	bool IsFull();
	void InsertVertex(char v);
	void DeleteVertex(int v);
	void InsertEdge(int u, int v);
	void DeleteEdge(int u, int v);
	void Print();

	void DFS(int now);
	void BFS(int now);
};

