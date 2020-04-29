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
	// ��á���� �˻�
	if (IsFull())
		return;

	// ����Ʈ�� �����Ҵ��Ͽ� �����͸� �Ѱ���
	vNode.push_back(std::vector<int>());

	vertices[size] = vertexName;
	
	size++;
}

void AdjList::DeleteVertex(int v)
{

}

// ������̶�� ����
void AdjList::InsertEdge(int u, int v)
{
	/// ����ó��
	// ������ �ε����� ū ���ڸ� �к�
	int max = u > v ? u : v;
	// ū �ε����� node�� ��ü ũ�⸦ �Ѿ�� ����ó��
	if (vNode.size() < max + 1)
		return; // ����.

	// �̹� �ִٸ� ����ó�� (�ߺ�)
	std::vector<int>::iterator it;
	it = std::find(vNode[u].begin(), vNode[u].end(), v);
	if (it == vNode[u].end())
		return;

	// u ��° �ε��� ������ v��° �ε��� ������ �����϶�
	vNode[u].push_back(v);
	vNode[v].push_back(u);

}

void AdjList::DeleteEdge(int u, int v)
{
	// ������ �ε����� ū ���ڸ� �к�
	int max = u > v ? u : v;
	// ū �ε����� node�� ��ü ũ�⸦ �Ѿ�� ����ó��
	if (vNode.size() < max + 1)
		return; // ����.
	
	vNode[u][v] = -1; // -1�� ��ü
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
	//	// ������ �̸� ���
	//	printf("%c : ", vertices[i]);
	//	for (int j = 0; j < vNode[i].size; ++j)
	//	{
	//		printf("%3d", vNode[i][j]);
	//	}
	//}
}