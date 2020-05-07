#pragma once
#include <iostream>
class AdjMatrix
{
	int adj[6][6] =
	{
			{ -1, 15, -1, 35, -1, -1 },
			{ 15, -1,  5, 10, -1, -1 },
			{ -1,  5, -1, -1, -1, -1 },
			{ 35, 10, -1, -1,  5, -1 },
			{ -1, -1, -1,  5, -1,  5 },
			{ -1, -1, -1, -1,  5, -1 },
	};

	bool visited[6];
	int distance[6];
	int parent[6];

public:
	AdjMatrix();
	~AdjMatrix();

	void Dijkstra(int start);
};