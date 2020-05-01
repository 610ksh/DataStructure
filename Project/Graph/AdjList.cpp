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
	visited.push_back(-1); // 미방문은 -1
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

void AdjList::DFS(int start)
{
	// 예외처리
	if (visited.size() < start + 1)
		return;

	// 시작지점 체크
	visited[start] = 1;
	
	// 이미 방문한곳 x
	// 다음 갈곳이 있어야함
	


	int next = vNode[start][0];
	// 연결된 간선이 있다면 계속 이동.
	while (visited[next]!=-1)
	{
		// 이미 방문한 곳이라면 스킵
			
		//

		DFS(vNode[start][0]);
	}
}