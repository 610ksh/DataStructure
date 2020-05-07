#include "AdjMatrix.h"



AdjMatrix::AdjMatrix()
{
	// 초기화
	for (int i = 0; i < 6; ++i)
	{
		visited[i] = false;
		distance[i] = 9999;
		parent[i] = -1;
	}
}


AdjMatrix::~AdjMatrix()
{
}

void AdjMatrix::Dijkstra(int start)
{
	/*
		<pseudocode>
		방문하지 않은 정점중 가장 가중치가 적은 정점을 찾는다
		그 정점을 방문 표시하고,
		그 정점과 연결된 모든 정점들의 최소 거리값을 계산후 비교하여
		distance 값을 갱신한다.
	*/

	// 출발점 할당
	distance[start] = 0; // 시작점의 거리는 0으로 한다
	parent[start] = start;

	while (true)
	{
		// 비교값 초기화
		int now = -1;
		int closest = 9999;

		// 인접한 정점중(distance)에서 가장 거리가 짧은 정점을 찾는다.
		for (int i = 0; i < 6; ++i)
		{
			// 이미 방문한곳 skip
			if (visited[i])
				continue;
			// 연결된 간선이 없는 곳일때 skip
			if (distance[i] == 9999)
				continue;
			// 찾아본 기존의 거리보다 크다면 skip
			if (distance[i] >= closest)
				continue;

			// 최소 거리 관련 데이터 갱신
			closest = distance[i]; // 실제 거리 크기값
			now = i; // 해당하는 인덱스
			
		}

		// 더이상 가장 짧은 distance를 찾을 수 없을때 빠져나옴
		if (now == -1)
			break;

		// 가장 짧은 정점으로 이동
		visited[now] = true;

		// 다시 현재 정점 기준으로 연결된 모든 간선에 대한 distance 갱신
		for (int i = 0; i < 6; ++i)
		{
			// 이미 방문한곳 skip
			if (visited[i])
				continue;
			// 연결되지 않은 간선 skip
			if (adj[now][i] == -1)
				continue;

			// 기존에 조사한 distance값과 (자신까지의 거리+해당 간선의 거리) 중에서 짧은것으로 distance 업데이트
			int newDistance = distance[now] + adj[now][i];
			if (newDistance < distance[i])
			{
				distance[i] = newDistance;
				parent[i] = now;
			}
		}
	}

}