#include "AdjList.h"

AdjList::AdjList()
{
	size = 0;
	vNode.reserve(MAX_VERTEX2);

	// vertex �̸� ����
	for (int i = 0; i < MAX_VERTEX2; ++i)
		vertices[i] = '*'; // ���°� * ǥ��
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
	// ��á���� �˻�
	if (IsFull())
		return;

	// ����Ʈ�� �����Ҵ��Ͽ� �����͸� �Ѱ���
	vNode.push_back(std::vector<int>());
	vNode[size].reserve(MAX_VERTEX2); // ����Ʈ ������ְ�, reserve

	vertices[size] = vertexName; // �̸� �־��ֱ�
	visited.push_back(-1); // �̹湮�� -1
	size++;
	
}

void AdjList::DeleteVertex(int v)
{
	// ������ �ִ���(��ȿ����)
	if (v >= MAX_VERTEX2 || vertices[v] == '*')
		return;
	
	// �ش� ���� ��带 ���鼭 ��� ������ ����
	while (vNode[v].size() != 0)
	{
		DeleteEdge(v, vNode[v][0]);
	}

	// �����̸��� �ٲٱ�
	vertices[v] = '*';

	// ������� �׳� ���д� => �߰� ���� �ϴ� �Ұ���(������ ���� ��Ȱ��x)
}

// ������̶�� ����
void AdjList::InsertEdge(int u, int v)
{
	/// ����ó��
	// �ش� ������ ������
	if (vertices[u] == '*' || vertices[v] == '*')
		return;

	/// ���� �ߺ� �˻�
	// �̹� ������ ������ �ִٸ� ����ó��(O(e))
	std::vector<int>::iterator it;
	it = std::find(vNode[u].begin(), vNode[u].end(), v);
	if (it != vNode[u].end())
		return;

	// u ��° �ε��� ������ v��° �ε��� ������ �����϶�
	vNode[u].push_back(v);
	vNode[v].push_back(u);
}

// vector�� erase �Լ��� �����(����)
void AdjList::DeleteEdge(int u, int v)
{
	/// ����ó��
	// �ش� ������ ������
	if (vertices[u] == '*' || vertices[v] == '*')
		return;

	// ������ ���ٸ� ��ŵ
	std::vector<int>::iterator it = std::find(vNode[u].begin(), vNode[u].end(), v);
	if (it == vNode[u].end())
		return;

	// ó������ �����ؼ� �߰��� �ε����� ���� O(N)
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
		// ������ �̸� ���
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
	// ����ó��
	if (visited.size() < start + 1)
		return;

	// �������� üũ
	visited[start] = 1;
	
	// �̹� �湮�Ѱ� x
	// ���� ������ �־����
	


	int next = vNode[start][0];
	// ����� ������ �ִٸ� ��� �̵�.
	while (visited[next]!=-1)
	{
		// �̹� �湮�� ���̶�� ��ŵ
			
		//

		DFS(vNode[start][0]);
	}
}