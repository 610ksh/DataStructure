#include "AdjMatrix.h"

AdjMatrix::AdjMatrix()
{
	size = 0;
	// 배열 초기화
	for (int i = 0; i < MAX_VERTEX; ++i)
		for (int j = 0; j < MAX_VERTEX; ++j)
			adj[i][j] = 0;

	for (int i = 0; i < MAX_VERTEX; ++i)
	{
		vertices[i] = 'X';
		visited[i] = false; // for dfs
		found[i] = false;
	}
}

bool AdjMatrix::IsEmpty()
{
	return size == 0;
}

bool AdjMatrix::IsFull()
{
	return size >= MAX_VERTEX;
}

void AdjMatrix::InsertVertex(const char & v)
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

void AdjMatrix::DeleteVertex(const int & v)
{
	printf("\n%d번째 정점 제거\n", v);

	// v번째 정점을 삭제
	vertices[v] = 'X';

	// 정점과 연결된 모든 간선 삭제
	for (int i = 0; i < MAX_VERTEX; ++i)
	{
		if (i == v)
		{
			for (int j = 0; j < v - 1; ++j)
				adj[i][j] = 0;
		}

		adj[i][v] = 0;
	}
	size--;
}

void AdjMatrix::InsertEdge(const int & u, const int & v)
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

void AdjMatrix::DeleteEdge(const int & u, const int & v)
{
	printf("\nadj[%d][%d] 간선 제거\n", u, v);
	adj[u][v] = 0;
	adj[v][u] = 0;
}

void AdjMatrix::Print()
{
	// 1. 정점의 개수 출력
	printf("정점의 개수 : %d\n", size);
	printf("    ");
	for (int i = 0; i < size; ++i)
		printf("%3c", vertices[i]);
	printf("\n");

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

void AdjMatrix::DFS(int now)
{
	/*
		<pseudocode>
		방문 체크
		for(해당 정점 모두 돌면서)
			if(방문하지 않은 점이라면)
			DFS 재귀
	*/

	// 범위 초과 에러
	if (size <= now)
		return;

	// 방문체크
	visited[now] = true;

	// 갯수 전체를 돈다
	for (int i = 0; i < size; ++i)
	{
		// ★ 연결되지 않은 간선이면 skip
		if (adj[now][i] == 0)
			continue;
		// 방문한 지점이라면 skip
		if (visited[i])
			continue;

		printf("now : %d, next : %d\n", now, i);
		DFS(i);
	}
}

void AdjMatrix::BFS(int start)
{
	/*
		<pseudocode>

		발견 표시
		큐에 넣고
		while(큐가 빌때까지)
			큐에서 꺼냄
			for(해당 정점을 모두 돌면서)
				if(발견하지 않은점)
					큐에 넣고 발견표시
	*/

	// 범위 초과 exception
	if (start >= size)
		return;

	parent.reserve(size);
	parent.assign(size, -1);

	found[start] = true;
	queue.push(start);
	parent[start] = start;

	while (queue.size() > 0)
	{
		//큐에서 꺼냄
		int now = queue.front();
		queue.pop();

		for (int next = 0; next < size; ++next)
		{
			// 간선이 아니라면 스킵
			if (adj[now][next] == 0)
				continue;

			// 이미 방문한 지점이라면 스킵
			if (found[next])
				continue;

			// 큐에 넣기
			queue.push(next);
			// 발견 표시
			found[next] = true;
			// 이전 경로 지정
			parent[next] = now;
		}
	}

}