#include "AdjMatGraph.h"
/*
	Graph 기초
	April 1, 2020

	문제점 : 중간 vertex를 삭제할 수 없다. 데이터 관리가 안됨.
	이유 : 중간 정점을 삭제하면 나머지 정점과 간선 정보를 이동시켜야함.
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