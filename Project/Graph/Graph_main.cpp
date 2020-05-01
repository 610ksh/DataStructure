#include "AdjMatrix.h"
#include "AdjList.h"
/*
	Graph 기초
	April 1, 2020

	문제점 : 중간 vertex를 삭제할 수 없다. 데이터 관리가 안됨.
	이유 : 중간 정점을 삭제하면 나머지 정점과 간선 정보를 이동시켜야함.
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
	for (int i = 0; i < 4; ++i)
		adjList.InsertVertex('A' + i);

	adjList.InsertEdge(0, 1);
	adjList.InsertEdge(0, 3);
	adjList.InsertEdge(1, 2);
	adjList.InsertEdge(1, 3);
	adjList.InsertEdge(2, 3);
	adjList.Print();
	
	adjList.DeleteVertex(3);
	//adjList.DeleteEdge(3, 1);
	adjList.Print();
	
	adjList.DeleteEdge(0, 1);
	adjList.Print();

	adjList.DeleteVertex(27);
	adjList.DeleteVertex(8);

	adjList.Print();

	return 0;
}