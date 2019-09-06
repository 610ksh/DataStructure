#pragma once
#include <iostream>

#define MAX_VERTEX 256


class AdjMatGraph
{ 
private:
	int size; // graph size
	int adj[MAX_VERTEX][MAX_VERTEX]; // �������(adjacency matrix)
	char vertices[MAX_VERTEX]; // �� ������ �ǹ̸� ���. ���⼭�� �̸��� ���

public:
	AdjMatGraph();
	bool IsEmpty();
	bool IsFull();
	void InsertVertex(const char& v); // ���ο� ������ �߰�
	void DeleteVertex(const int& v); // v��° ������ �����϶�� �ǹ�.
	void InsertEdge(const int& u, const int& v);
	void DeleteEdge(const int& u, const int& v);
	//int* Adjacent(int v); // v��° ���� �ݳ��Ѵ�. 
	void Print();
};