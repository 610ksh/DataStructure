#pragma once
#include <iostream>

#define MAX_VERTEX 256

/*
	1. Adjacency Matrix (인접 행렬) 방식의 그래프 구현
	Adjacency List (인접 리스트) 방식의 구현방법도 있음.
*/

class AdjMatGraph
{ 
private:
	int size; // 정점의 개수 = 그래프 사이즈
	int adj[MAX_VERTEX][MAX_VERTEX]; // edge의 유무만 나타낸다면 bool형으로 해도 된다.

	/// 필수적인 변수는 아니다. 필요에 따라 추가할 수 있는 변수.
	char vertices[MAX_VERTEX]; // 정점의 이름

public:
	AdjMatGraph();
	bool IsEmpty(); // 그래프가 비었는지
	bool IsFull(); // 정해진 범위를 초과해서 정점을 추가하는지 검사

	void InsertVertex(const char& v); // vertex 추가, v는 관련 정보를 의미
	void DeleteVertex(const int& v); //  vertex 제거, v는 인덱스를 의미(몇번째)

	void InsertEdge(const int& u, const int& v); // edge 추가, u번째 정점과 v번째 정점을 연결
	void DeleteEdge(const int& u, const int& v); // edge 삭제, u번째 정점과 v번째 정점을 연결한 edge 제거
	
	//int* Adjacent(int v); // v번째 열을 반납한다.
	void Print();
};