#pragma once
#include <iostream>
#include <queue> // for bfs
#include <vector> // for bfs

#define MAX_VERTEX 256

/*
	1. Adjacency Matrix (���� ���) ����� �׷��� ����
	Adjacency List (���� ����Ʈ) ����� ��������� ����.
*/

class AdjMatrix
{ 
private:
	int size; // ������ ���� = �׷��� ������
	int adj[MAX_VERTEX][MAX_VERTEX]; // edge�� ������ ��Ÿ���ٸ� bool������ �ص� �ȴ�.

	/// �ʼ����� ������ �ƴϴ�. �ʿ信 ���� �߰��� �� �ִ� ����.
	char vertices[MAX_VERTEX]; // ������ �̸�

	bool visited[MAX_VERTEX]; // for dfs

	bool found[MAX_VERTEX]; // for bfs
	std::queue<int> queue;
	std::vector<int> parent;
	
public:
	AdjMatrix();
	bool IsEmpty(); // �׷����� �������
	bool IsFull(); // ������ ������ �ʰ��ؼ� ������ �߰��ϴ��� �˻�

	void InsertVertex(const char& v); // vertex �߰�, v�� ���� ������ �ǹ�
	void DeleteVertex(const int& v); //  vertex ����, v�� �ε����� �ǹ�(���°)

	void InsertEdge(const int& u, const int& v); // edge �߰�, u��° ������ v��° ������ ����
	void DeleteEdge(const int& u, const int& v); // edge ����, u��° ������ v��° ������ ������ edge ����
	
	//int* Adjacent(int v); // v��° ���� �ݳ��Ѵ�.
	void Print();

	void DFS(int now);
	void BFS(int start);
};