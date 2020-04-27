#include "AdjMatGraph.h"

AdjMatGraph::AdjMatGraph()
{
	size = 0;
	// �迭 �ʱ�ȭ
	for (int i = 0; i < MAX_VERTEX; ++i)
		for (int j = 0; j < MAX_VERTEX; ++j)
			adj[i][j] = 0;

	for (int i = 0; i < MAX_VERTEX; ++i)
		vertices[i] = 'X';
}

bool AdjMatGraph::IsEmpty()
{
	return size == 0;
}

bool AdjMatGraph::IsFull()
{
	return size >= MAX_VERTEX;
}

void AdjMatGraph::InsertVertex(const char & v)
{
	// �ִ�ġ�� �����ߴ��� ����
	if (IsFull())
	{
		std::cout << "�׷��� ũ�Ⱑ �Ѱ�ġ�� �����߽��ϴ�" << std::endl;
		return;
	}
	vertices[size] = v;
	size++;
}

void AdjMatGraph::DeleteVertex(const int & v)
{
	printf("\n%d��° ���� ����\n", v);

	// v��° ������ ����
	vertices[v] = 'X';
	
	// ������ ����� ��� ���� ����
	for (int i = 0; i < MAX_VERTEX; ++i)
	{
		if (i == v)
		{
			for (int j = 0; j < v-1; ++j)
				adj[i][j] = 0;
		}

		adj[i][v] = 0;
	}
	size--;
}

void AdjMatGraph::InsertEdge(const int & u, const int & v)
{
	// ����ó��
	if (u > MAX_VERTEX || v > MAX_VERTEX)
		return;
	if (vertices[u] == 'X' || vertices[v] == 'X')
		return;

	// u �������� v ���� ���̿� ������ (������ �׷���)
	adj[u][v] = 1;
	adj[v][u] = 1;
}

void AdjMatGraph::DeleteEdge(const int & u, const int & v)
{
	printf("\nadj[%d][%d] ���� ����\n",u,v);
	adj[u][v] = 0;
	adj[v][u] = 0;
}

void AdjMatGraph::Print()
{
	// 1. ������ ���� ���
	printf("������ ���� : %d\n", size);
	// 2. �׷��� ���� ���
	for (int i = 0; i < size; ++i)
	{
		//// ���� �߰� ������ ������ �ִٸ� �Ѿ
		//if (vertices[i] == 'X')
		//	continue;

		// ������ �̸� ���
		printf("%c : ", vertices[i]);
		for (int j = 0; j < size; ++j)
		{
			//// ���� �߰� ������ ������ �ִٸ� �Ѿ
			//if (vertices[j] == 'X')
			//	continue;

			// ���� ���� ���
			printf("%3d", adj[i][j]);
		}
		printf("\n");
	}
}