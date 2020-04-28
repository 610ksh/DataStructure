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
	// ��á���� �˻�
	if (size >= MAX_VERTEX)
		return;

	// ����Ʈ�� �����Ҵ��Ͽ� �����͸� �Ѱ���
	vNode.push_back(std::vector<int>());
	
	vertices[size] = v;
	size++;
}

void AdjList::DeleteVertex(int v)
{

}

// ������̶�� ����
void AdjList::InsertEdge(int u, int v)
{
	std::vector<int>::iterator it;
	it = std::find(vNode[u].begin(), vNode[u].end(), v);

	// ã�� �������� ������ �߰�
	if (it == vNode[u].end())
	{
		vNode[u].push_back(v);
		vNode[v].push_back(u);
	}
	// �̹� �����Ѵٸ�,
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
		// ������ �̸� ���
		printf("%c : ", vertices[i]);
		for (int j = 0; j < vNode[i].size; ++j)
		{
			printf("%3d", vNode[i][j]);
		}
	}
}