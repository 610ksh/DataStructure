#include "AdjMatrix.h"
#include "AdjList.h"
/*
	Graph ����
	April 1, 2020

	������ : �߰� vertex�� ������ �� ����. ������ ������ �ȵ�.
	���� : �߰� ������ �����ϸ� ������ ������ ���� ������ �̵����Ѿ���.
*/

int main()
{
	/*
	AdjMatrix adjMatrix;

	for (int i = 0; i < 4; ++i)
		adjMatrix.InsertVertex('A' + i);

	adjMatrix.InsertEdge(0, 1);
	adjMatrix.InsertEdge(0, 3);
	adjMatrix.InsertEdge(1, 2);
	adjMatrix.InsertEdge(1, 3);
	adjMatrix.InsertEdge(2, 3);

	adjMatrix.Print();

	adjMatrix.DeleteVertex(3);
	adjMatrix.Print();
	
	adjMatrix.DeleteEdge(1, 2);
	adjMatrix.Print();
	*/

	AdjList adjList;
	for (int i = 0; i < 6; ++i)
		adjList.InsertVertex('A' + i);

	adjList.InsertEdge(0, 1);
	adjList.InsertEdge(0, 3);
	adjList.InsertEdge(1, 2);
	adjList.InsertEdge(1, 3);
	adjList.InsertEdge(3, 4);
	adjList.InsertEdge(4, 5);
	adjList.Print();
	//
	//adjList.DeleteVertex(3);
	//adjList.Print();
	//
	//adjList.DeleteEdge(0, 1);
	//adjList.Print();

	//adjList.DeleteVertex(27);
	//adjList.DeleteVertex(8);

	//adjList.Print();

	adjList.DFS(0);

	return 0;
}