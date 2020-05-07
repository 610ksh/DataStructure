#include <iostream>
#include <vector>

/*
	자료구조에 앞선 공지사항
	1) 자료구조 전체 공부방향성
	1. 특정 자료구조의 ADT를 정의해본다.
	2. ADT를 근거로 하여 해당 자료구조를 main함수에 먼저 정의해본다(사용해본다)
	3. ADT를 근거로 해당 자료구조를 구현해본다.
	
	※ ADT(Abstract Data Type) : 순수하게 기능(함수)이 무엇이 있는지 나열한것

2, 3번이 바뀌어 보일지 모르지만, 일부러 그런거다.
어떻게 사용되는지 실제 느껴보고, 실제 내부 구현을 확인해보는거다.
사용자에게 사용방법 이외의 불필요한 부분까지 알도록 부담을 주지 않기 위해서이다.

	※ ADT를 생각할때는 해당 자료구조의 특징을 통해
	제공해야하는 필수 기능을 생각해야한다.

	Copyright 2020. SungHoon Kim. All rights reserved.
	

*/

	using namespace std;
int main()
{
	std::cout << "Hello Data Structure"<<std::endl;
	

	vector<int> graphList[100];
	vector < vector<char>> test;

	test.push_back(vector<char>());
	test.push_back(vector<char>(4));
	test.push_back(vector<char>(5,1));
	test.push_back(vector<char>(10, 1));
	test.push_back(vector<char>(5, 1));
	test.push_back(vector<char>(3, 1));
	test.push_back(vector<char>());

	int* temp2;
	int** temp3;

	printf("%d, %d", sizeof(test), sizeof(test[3]));

	int n, m;
	//input
	scanf_s("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int s, e;
		scanf_s("%d%d", &s, &e);
		graphList[s].push_back(e);
		graphList[e].push_back(s);
	}
	//output
	printf("\n==인접리스트 구현 완료==\n");
	for (int i = 1; i <= n; i++) {
		printf("%d : ", i);
		for (int j = 0; j < graphList[i].size(); j++) {
			printf("%d ", graphList[i][j]);            //vector 배열은 이렇게 2차원 배열처럼[]연산자를 사용해서 표현가능
		}
		printf("\n");
	}


	return 0;
}