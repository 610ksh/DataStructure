#include "AdjMatrix.h"
/*
	Graph 기초
	April 1, 2020

	문제점 : 중간 vertex를 삭제할 수 없다. 데이터 관리가 안됨.
	이유 : 중간 정점을 삭제하면 나머지 정점과 간선 정보를 이동시켜야함.
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