#pragma once

#include <iostream>
#include <vector> // for 연결리스트
#include <queue> // for BFS

#define MAX_VERTEX2 26 // 영어 알파벳 개수만큼

/*
	2. Adjacency List (인접 리스트 방식)
	- 정점이 많고 간선이 적을수록 유리함 (반대는 adjacency matrix가 유리)
	
	< Notices >
	- 최적화는 시키지 못함.
	- DeleteEdge 함수는 erase함수를 사용했음(땡김)
	- DeleteVertex 함수를 통해 정점을 삭제해도,
	- 실제 vector를 제거해서 땡기지는 않음.
	=> 그렇게 설계하면 vertices 까지도 모두 땡겨야하는 문제가 있어서 그냥 놔둠.
	
	May 1, 2020
*/

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