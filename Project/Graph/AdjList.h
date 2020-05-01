#pragma once

#include <iostream>
#include <vector> // ���Ḯ��Ʈ�� Ȱ��

#define MAX_VERTEX 26 // ���� ö��

/*
	2. Adjacency List (���� ����Ʈ ���)
*/

//class Node {
//private:
//	char id; // ������ �ε��� & �̸�
//	Node* link;
//public:
//	Node(int i, Node* l = NULL) : id(i), link(l) {}
//	~Node() { if (link != NULL) delete link; }
//	int GetId() { return id; }
//	Node* GetLink() { return link; }
//	void SetLink(Node* l) { link = l; }
//};

class AdjList
{
	int size; // ������ ����(���� ����)
	char vertices[MAX_VERTEX];
	std::vector<std::vector<int>> vNode; // ����Ʈ �迭 (��� �����Ͷ�� �θ�)

	// Node* adj[MAX_VERTEX];
	//std::vector<Node*> node;

public:
	AdjList();
	~AdjList();
	bool IsEmpty();
	bool IsFull();
	void InsertVertex(char v);
	void DeleteVertex(int v);
	void InsertEdge(int u, int v);
	void DeleteEdge(int u, int v);
	std::vector<int> Adjacent(int v);
	void Print();
};