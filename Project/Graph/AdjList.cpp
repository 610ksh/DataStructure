#include "AdjList.h"

AdjList::AdjList()
{
	size = 0;
	
	for (int i = 0; i < MAX_VERTEX; ++i)
		vertices[i] = 'X';
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
	return size==0;
}

bool AdjList::IsFull()
{
	return size>=MAX_VERTEX;
}

void AdjList::InsertVertex(char vertexName)
{
	// 꽉찼는지 검사
	if (IsFull())
		return;

	// 리스트를 동적할당하여 포인터를 넘겨줌
	vNode.push_back(std::vector<int>());

	vertices[size] = vertexName;
	
	size++;
}

void AdjList::DeleteVertex(int v)
{

}

// 양방향이라고 전제
void AdjList::InsertEdge(int u, int v)
{
	/// 예외처리
	// 정점의 인덱스중 큰 숫자를 분별
	int max = u > v ? u : v;
	// 큰 인덱스가 node의 전체 크기를 넘어서면 예외처리
	if (vNode.size() < max + 1)
		return; // 없다.

	// 이미 있다면 예외처리 (중복)
	std::vector<int>::iterator it;
	it = std::find(vNode[u].begin(), vNode[u].end(), v);
	if (it == vNode[u].end())
		return;

	// u 번째 인덱스 정점과 v번째 인덱스 정점을 연결하라
	vNode[u].push_back(v);
	vNode[v].push_back(u);

}

void AdjList::DeleteEdge(int u, int v)
{
	// 정점의 인덱스중 큰 숫자를 분별
	int max = u > v ? u : v;
	// 큰 인덱스가 node의 전체 크기를 넘어서면 예외처리
	if (vNode.size() < max + 1)
		return; // 없다.
	
	vNode[u][v] = -1; // -1로 대체
	vNode[v][u] = -1;
}

std::vector<int> AdjList::Adjacent(int v)
{
	return std::vector<int>();
}

void AdjList::Print()
{
	//for (int i = 0; i < size; ++i)
	//{
	//	// 정점의 이름 출력
	//	printf("%c : ", vertices[i]);
	//	for (int j = 0; j < vNode[i].size; ++j)
	//	{
	//		printf("%3d", vNode[i][j]);
	//	}
	//}
}