#pragma once

#include <iostream>
#include <vector> // for 연결리스트
#include <queue> // for BFS

#define MAX_VERTEX2 26 // 영어 알파벳 개수만큼

class AdjList
{
	int size; // 정점의 개수(삭제 포함)
	char vertices[MAX_VERTEX2]; // 정점의 이름을 부여해봄(없어도 큰 문제는 없음)
	std::vector<std::vector<int>> vNode; // 리스트 배열 (헤더 포인터라고 부름)

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

