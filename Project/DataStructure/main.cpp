#include <iostream>
#include <vector>

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