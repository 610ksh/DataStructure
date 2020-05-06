#include "AdjList.h"

AdjList::AdjList()
{
	size = 0;
	vNode.reserve(MAX_VERTEX2);

	// vertex 이름 지정
	for (int i = 0; i < MAX_VERTEX2; ++i)
		vertices[i] = '*'; // 없는건 * 표기
}

AdjList::~AdjList()
{
	for (int i = 0; i < size; ++i)
		if (!vNode[i].empty())
			vNode[i].clear();
	size = 0;
}

bool AdjList::IsEmpty()
{
	return size == 0;
}

bool AdjList::IsFull()
{
	return size >= MAX_VERTEX2;
}

void AdjList::InsertVertex(char vertexName)
{
	// 꽉찼는지 검사
	if (IsFull())
		return;

	// 리스트를 동적할당하여 포인터를 넘겨줌
	vNode.push_back(std::vector<int>());
	vNode[size].reserve(MAX_VERTEX2); // 리스트 만들어주고, reserve

	vertices[size] = vertexName; // 이름 넣어주기
	visited.push_back(false); // 미방문은 -1

	found.push_back(false); // 미방문은 -1
	size++;

}

void AdjList::DeleteVertex(int v)
{
	// 정점이 있는지(유효한지)
	if (v >= MAX_VERTEX2 || vertices[v] == '*')
		return;

	// 해당 정점 노드를 돌면서 모든 간선을 제거
	while (vNode[v].size() != 0)
	{
		DeleteEdge(v, vNode[v][0]);
	}

	// 정점이름도 바꾸기
	vertices[v] = '*';

	// 사이즈는 그냥 놔둔다 => 중간 삽입 일단 불가능(삭제된 정점 재활용x)
}

// 양방향이라고 전제
void AdjList::InsertEdge(int u, int v)
{
	/// 예외처리
	// 해당 정점이 없을때
	if (vertices[u] == '*' || vertices[v] == '*')
		return;

	/// 간선 중복 검사
	// 이미 간선을 가지고 있다면 예외처리(O(e))
	std::vector<int>::iterator it;
	it = std::find(vNode[u].begin(), vNode[u].end(), v);
	if (it != vNode[u].end())
		return;

	// u 번째 인덱스 정점과 v번째 인덱스 정점을 연결하라
	vNode[u].push_back(v);
	vNode[v].push_back(u);
}

// vector의 erase 함수를 사용함(땡김)
void AdjList::DeleteEdge(int u, int v)
{
	/// 예외처리
	// 해당 정점이 없을때
	if (vertices[u] == '*' || vertices[v] == '*')
		return;

	// 간선이 없다면 스킵
	std::vector<int>::iterator it = std::find(vNode[u].begin(), vNode[u].end(), v);
	if (it == vNode[u].end())
		return;

	// 처음부터 조사해서 발견한 인덱스는 제거 O(N)
	for (int i = 0; i < vNode[u].size(); ++i)
	{
		if (vNode[u][i] == v)
			vNode[u].erase(vNode[u].begin() + i);
	}
	// O(N)
	for (int i = 0; i < vNode[v].size(); ++i)
	{
		if (vNode[v][i] == u)
			vNode[v].erase(vNode[v].begin() + i);
	}
}

void AdjList::Print()
{
	for (int i = 0; i < size; ++i)
	{
		// 정점의 이름 출력
		printf("%c :", vertices[i]);
		for (int j = 0; j < vNode[i].size(); ++j)
		{
			printf("%3d", vNode[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void AdjList::DFS(int now)
{
	// 예외처리
	if (visited.size() < now + 1)
		return;

	// 시작지점 체크
	visited[now] = true;

	for (int i = 0; i < vNode[now].size(); ++i)
	{
		int next = vNode[now][i];

		// 이미 방문한 지역이라면
		if (visited[next])
			continue;
		// 재귀호출
		printf("now : %d, next : %d\n", now, next);
		DFS(next);
	}
	
	#pragma region 범위기반 for문(DFS, C++11)
	/*
	for (int next : vNode[now])
	{
		// 이미 방문한 지역이라면
		if (visited[next])
			continue;
		// 재귀호출
		printf("now : %d, next : %d\n", now, next);
		DFS(next);
	}
	*/
	#pragma endregion
}

void AdjList::BFS(int start)
{
	/*

		Pseudocode(슈도코드)
		
		now 방문 표시
		큐에 now 등록
		while(큐가 빌때까지)
			큐에서 꺼냄
			for(모든 리스트를 돌면서)
				if(방문하지 않은 정점이 있다면)
				방문하지 않은 모든 정점들을 큐에 등록
			다음 방문지(next)를 방문표시하고,
			now를 next로 업데이트.

	*/

	// 이전 경로 변수 초기화
	parent.reserve(size);
	parent.assign(size, -1);

	// 시작지점 발견 표시
	found[start] = true;
	queue.push(start);

	parent[start] = start;

	while (queue.size() > 0)
	{
		// 큐에서 꺼냄.
		int now = queue.front();
		queue.pop();

		// 정점을 돌면서 큐에 넣기
		for (int i = 0, next; i < vNode[now].size(); ++i)
		{
			// 연결된 정점
			next = vNode[now][i];

			// 방문하지 않은 정점이라면 skip
			if (found[next])
				continue;

			// 새로 발견한 정점은 큐에 넣기
			queue.push(next);
			// 발견 표시
			found[next] = true;
			parent[next] = now;
		}
	}
}