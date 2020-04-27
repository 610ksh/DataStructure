#include "AdjMatGraph.h"
/*
	Graph ����
	April 1, 2020

	������ : �߰� vertex�� ������ �� ����. ������ ������ �ȵ�.
	���� : �߰� ������ �����ϸ� ������ ������ ���� ������ �̵����Ѿ���.
*/

int main()
{
	AdjMatGraph adjMatGraph;

	for (int i = 0; i < 4; ++i)
		adjMatGraph.InsertVertex('A' + i);

	adjMatGraph.InsertEdge(0, 1);
	adjMatGraph.InsertEdge(0, 3);
	adjMatGraph.InsertEdge(1, 2);
	adjMatGraph.InsertEdge(1, 3);
	adjMatGraph.InsertEdge(2, 3);

	adjMatGraph.Print();

	adjMatGraph.DeleteVertex(3);
	adjMatGraph.Print();
	
	adjMatGraph.DeleteEdge(1, 2);
	adjMatGraph.Print();


	return 0;
}