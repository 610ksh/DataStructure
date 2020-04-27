#include "AdjMatGraph.h"

AdjMatGraph::AdjMatGraph()
{
	size = 0;
	// 배열 초기화
	for (int i = 0; i < MAX_VERTEX; ++i)
		for (int j = 0; j < MAX_VERTEX; ++j)
			adj[i][j] = 0;

	for (int i = 0; i < MAX_VERTEX; ++i)
		vertices[i] = 'X';
}

bool AdjMatGraph::IsEmpty()
{
	return size == 0;
}

bool AdjMatGraph::IsFull()
{
	return size >= MAX_VERTEX;
}

void AdjMatGraph::InsertVertex(const char & v)
{
	// 최대치에 도달했는지 조사
	if (IsFull())
	{
		std::cout << "그래프 크기가 한계치에 도달했습니다" << std::endl;
		return;
	}
	vertices[size] = v;
	size++;
}

void AdjMatGraph::DeleteVertex(const int & v)
{
	printf("\n%d번째 정점 제거\n", v);

	// v번째 정점을 삭제
	vertices[v] = 'X';
	
	// 정점과 연결된 모든 간선 삭제
	for (int i = 0; i < MAX_VERTEX; ++i)
	{
		if (i == v)
		{
			for (int j = 0; j < v-1; ++j)
				adj[i][j] = 0;
		}

		adj[i][v] = 0;
	}
	size--;
}

void AdjMatGraph::InsertEdge(const int & u, const int & v)
{
	// 예외처리
	if (u > MAX_VERTEX || v > MAX_VERTEX)
		return;
	if (vertices[u] == 'X' || vertices[v] == 'X')
		return;

	// u 정점에서 v 정점 사이에 연결함 (무방향 그래프)
	adj[u][v] = 1;
	adj[v][u] = 1;
}

void AdjMatGraph::DeleteEdge(const int & u, const int & v)
{
	printf("\nadj[%d][%d] 간선 제거\n",u,v);
	adj[u][v] = 0;
	adj[v][u] = 0;
}

void AdjMatGraph::Print()
{
	// 1. 정점의 개수 출력
	printf("정점의 개수 : %d\n", size);
	// 2. 그래프 전부 출력
	for (int i = 0; i < size; ++i)
	{
		//// 만약 중간 삭제된 정점이 있다면 넘어감
		//if (vertices[i] == 'X')
		//	continue;

		// 정점의 이름 출력
		printf("%c : ", vertices[i]);
		for (int j = 0; j < size; ++j)
		{
			//// 만약 중간 삭제된 정점이 있다면 넘어감
			//if (vertices[j] == 'X')
			//	continue;

			// 간선 정보 출력
			printf("%3d", adj[i][j]);
		}
		printf("\n");
	}
}