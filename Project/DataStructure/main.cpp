#include <iostream>
#include <vector>

/*
	�ڷᱸ���� �ռ� ��������
	1) �ڷᱸ�� ��ü ���ι��⼺
	1. Ư�� �ڷᱸ���� ADT�� �����غ���.
	2. ADT�� �ٰŷ� �Ͽ� �ش� �ڷᱸ���� main�Լ��� ���� �����غ���(����غ���)
	3. ADT�� �ٰŷ� �ش� �ڷᱸ���� �����غ���.
	
	�� ADT(Abstract Data Type) : �����ϰ� ���(�Լ�)�� ������ �ִ��� �����Ѱ�

2, 3���� �ٲ�� ������ ������, �Ϻη� �׷��Ŵ�.
��� ���Ǵ��� ���� ��������, ���� ���� ������ Ȯ���غ��°Ŵ�.
����ڿ��� ����� �̿��� ���ʿ��� �κб��� �˵��� �δ��� ���� �ʱ� ���ؼ��̴�.

	�� ADT�� �����Ҷ��� �ش� �ڷᱸ���� Ư¡�� ����
	�����ؾ��ϴ� �ʼ� ����� �����ؾ��Ѵ�.

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
	printf("\n==��������Ʈ ���� �Ϸ�==\n");
	for (int i = 1; i <= n; i++) {
		printf("%d : ", i);
		for (int j = 0; j < graphList[i].size(); j++) {
			printf("%d ", graphList[i][j]);            //vector �迭�� �̷��� 2���� �迭ó��[]�����ڸ� ����ؼ� ǥ������
		}
		printf("\n");
	}


	return 0;
}