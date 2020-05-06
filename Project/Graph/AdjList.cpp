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
	visited.push_back(false); // �̹湮�� -1

	found.push_back(false); // �̹湮�� -1
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

void AdjList::DFS(int now)
{
	// ����ó��
	if (visited.size() < now + 1)
		return;

	// �������� üũ
	visited[now] = true;

	for (int i = 0; i < vNode[now].size(); ++i)
	{
		int next = vNode[now][i];

		// �̹� �湮�� �����̶��
		if (visited[next])
			continue;
		// ���ȣ��
		printf("now : %d, next : %d\n", now, next);
		DFS(next);
	}
	
	#pragma region ������� for��(DFS, C++11)
	/*
	for (int next : vNode[now])
	{
		// �̹� �湮�� �����̶��
		if (visited[next])
			continue;
		// ���ȣ��
		printf("now : %d, next : %d\n", now, next);
		DFS(next);
	}
	*/
	#pragma endregion
}

void AdjList::BFS(int start)
{
	/*

		Pseudocode(�����ڵ�)
		
		now �湮 ǥ��
		ť�� now ���
		while(ť�� ��������)
			ť���� ����
			for(��� ����Ʈ�� ���鼭)
				if(�湮���� ���� ������ �ִٸ�)
				�湮���� ���� ��� �������� ť�� ���
			���� �湮��(next)�� �湮ǥ���ϰ�,
			now�� next�� ������Ʈ.

	*/

	// ���� ��� ���� �ʱ�ȭ
	parent.reserve(size);
	parent.assign(size, -1);

	// �������� �߰� ǥ��
	found[start] = true;
	queue.push(start);

	parent[start] = start;

	while (queue.size() > 0)
	{
		// ť���� ����.
		int now = queue.front();
		queue.pop();

		// ������ ���鼭 ť�� �ֱ�
		for (int i = 0, next; i < vNode[now].size(); ++i)
		{
			// ����� ����
			next = vNode[now][i];

			// �湮���� ���� �����̶�� skip
			if (found[next])
				continue;

			// ���� �߰��� ������ ť�� �ֱ�
			queue.push(next);
			// �߰� ǥ��
			found[next] = true;
			parent[next] = now;
		}
	}
}