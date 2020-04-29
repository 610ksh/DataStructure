#pragma once

#include <iostream>
#include <vector> // 연결리스트를 활용

#define MAX_VERTEX 256

/*
	2. Adjacency List (인접 리스트 방식)
*/

class Node {
private:
	char id; // 정점의 인덱스 & 이름
	Node* link;
public:
	Node(int i, Node* l = NULL) : id(i), link(l) {}
	~Node() { if (link != NULL) delete link; }
	int GetId() { return id; }
	Node* GetLink() { return link; }
	void SetLink(Node* l) { link = l; }
};

class AdjList
{
	int size;
	char vertices[MAX_VERTEX];
	std::vector<std::vector<int>> vNode; // 리스트 배열 (헤더 포인터라고 부름)

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
	//void InsertEdge(char u, char v); // 이름으로 찾지 않는 이유는, 리스트(벡터)에서 해당 이름을 순회하면서 찾아야하기 때문. 검색시간 때문에
	void DeleteEdge(int u, int v);
	std::vector<int> Adjacent(int v);
	void Print();
};