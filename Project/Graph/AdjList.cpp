#include "AdjList.h"

AdjList::AdjList()
{
	size = 0;
	
	for (int i = 0; i < MAX_VERTEX; ++i)
		vertices[i] = 'X';
}

bool AdjList::IsEmpty()
{
	return size==0;
}

bool AdjList::IsFull()
{
	return size>=MAX_VERTEX;
}

void AdjList::InsertVertex(char v)
{
	// 꽉찼는지 검사
	if (size >= MAX_VERTEX)
		return;

	// 리스트를 동적할당하여 포인터를 넘겨줌
	vNode.push_back(std::vector<int>());
	
	vertices[size] = v;
	size++;
}

void AdjList::DeleteVertex(int v)
{

}

// 양방향이라고 전제
void AdjList::InsertEdge(int u, int v)
{
	std::vector<int>::iterator it;
	it = std::find(vNode[u].begin(), vNode[u].end(), v);

	// 찾지 못했으면 간선을 추가
	if (it == vNode[u].end())
	{
		vNode[u].push_back(v);
		vNode[v].push_back(u);
	}
	// 이미 존재한다면,
	else
		return;
}

void AdjList::DeleteEdge(int u, int v)
{
}

std::vector<int> AdjList::Adjacent(int v)
{
	return std::vector<int>();
}

void AdjList::Print()
{
	for (int i = 0; i < size; ++i)
	{
		// 정점의 이름 출력
		printf("%c : ", vertices[i]);
		for (int j = 0; j < vNode[i].size; ++j)
		{
			printf("%3d", vNode[i][j]);
		}
	}
}