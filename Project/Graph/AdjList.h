#pragma once

#include <iostream>
#include <vector> // ���Ḯ��Ʈ�� Ȱ��

#define MAX_VERTEX2 26 // ���� ���ĺ� ������ŭ

/*
	2. Adjacency List (���� ����Ʈ ���)
	- ����ȭ�� ��Ű�� ����.
	- DeleteEdge �Լ��� erase�Լ��� �������(����)
	- DeleteVertex �Լ��� ���� ������ �����ص�, ���� vector�� �����ؼ� �������� ����.
	=> �׷��� �����ϸ� vertices ������ ��� ���ܾ��ϴ� ������ �־ �׳� ����.

	May 1, 2020
*/

class AdjList
{
	int size; // ������ ����(���� ����)
	char vertices[MAX_VERTEX2]; // ������ �̸��� �ο��غ�(��� ū ������ ����)
	std::vector<std::vector<int>> vNode; // ����Ʈ �迭 (��� �����Ͷ�� �θ�)

	std::vector<int> visited; // �湮, -1�� �̹湮 1�� �湮���� ó��

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

	void DFS(int start);
};