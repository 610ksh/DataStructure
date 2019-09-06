#pragma once
#include <iostream>

#define MAX_VERTEX 256


class AdjMatGraph
{ 
private:
	int size; // graph size
	int adj[MAX_VERTEX][MAX_VERTEX]; // 인접행렬(adjacency matrix)
	char vertices[MAX_VERTEX]; // 각 정점의 의미를 기록. 여기서는 이름을 기록

public:
	AdjMatGraph();
	bool IsEmpty();
	bool IsFull();
	void InsertVertex(const char& v); // 새로운 정점을 추가
	void DeleteVertex(const int& v); // v번째 정점을 삭제하라는 의미.
	void InsertEdge(const int& u, const int& v);
	void DeleteEdge(const int& u, const int& v);
	//int* Adjacent(int v); // v번째 열을 반납한다. 
	void Print();
};