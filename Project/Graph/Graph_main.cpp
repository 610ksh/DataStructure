#include "AdjMatrix.h"
/*
	Graph ����
	April 1, 2020

	������ : �߰� vertex�� ������ �� ����. ������ ������ �ȵ�.
	���� : �߰� ������ �����ϸ� ������ ������ ���� ������ �̵����Ѿ���.
*/

int main()
{
	AdjMatrix AdjMatrix;

	for (int i = 0; i < 4; ++i)
		AdjMatrix.InsertVertex('A' + i);

	AdjMatrix.InsertEdge(0, 1);
	AdjMatrix.InsertEdge(0, 3);
	AdjMatrix.InsertEdge(1, 2);
	AdjMatrix.InsertEdge(1, 3);
	AdjMatrix.InsertEdge(2, 3);

	AdjMatrix.Print();

	AdjMatrix.DeleteVertex(3);
	AdjMatrix.Print();
	
	AdjMatrix.DeleteEdge(1, 2);
	AdjMatrix.Print();


	return 0;
}