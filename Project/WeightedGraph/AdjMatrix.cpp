#include "AdjMatrix.h"



AdjMatrix::AdjMatrix()
{
	// �ʱ�ȭ
	for (int i = 0; i < 6; ++i)
	{
		visited[i] = false;
		distance[i] = 9999;
		parent[i] = -1;
	}
}


AdjMatrix::~AdjMatrix()
{
}

void AdjMatrix::Dijkstra(int start)
{
	/*
		<pseudocode>
		�湮���� ���� ������ ���� ����ġ�� ���� ������ ã�´�
		�� ������ �湮 ǥ���ϰ�,
		�� ������ ����� ��� �������� �ּ� �Ÿ����� ����� ���Ͽ�
		distance ���� �����Ѵ�.
	*/

	// ����� �Ҵ�
	distance[start] = 0; // �������� �Ÿ��� 0���� �Ѵ�
	parent[start] = start;

	while (true)
	{
		// �񱳰� �ʱ�ȭ
		int now = -1;
		int closest = 9999;

		// ������ ������(distance)���� ���� �Ÿ��� ª�� ������ ã�´�.
		for (int i = 0; i < 6; ++i)
		{
			// �̹� �湮�Ѱ� skip
			if (visited[i])
				continue;
			// ����� ������ ���� ���϶� skip
			if (distance[i] == 9999)
				continue;
			// ã�ƺ� ������ �Ÿ����� ũ�ٸ� skip
			if (distance[i] >= closest)
				continue;

			// �ּ� �Ÿ� ���� ������ ����
			closest = distance[i]; // ���� �Ÿ� ũ�Ⱚ
			now = i; // �ش��ϴ� �ε���
			
		}

		// ���̻� ���� ª�� distance�� ã�� �� ������ ��������
		if (now == -1)
			break;

		// ���� ª�� �������� �̵�
		visited[now] = true;

		// �ٽ� ���� ���� �������� ����� ��� ������ ���� distance ����
		for (int i = 0; i < 6; ++i)
		{
			// �̹� �湮�Ѱ� skip
			if (visited[i])
				continue;
			// ������� ���� ���� skip
			if (adj[now][i] == -1)
				continue;

			// ������ ������ distance���� (�ڽű����� �Ÿ�+�ش� ������ �Ÿ�) �߿��� ª�������� distance ������Ʈ
			int newDistance = distance[now] + adj[now][i];
			if (newDistance < distance[i])
			{
				distance[i] = newDistance;
				parent[i] = now;
			}
		}
	}

}