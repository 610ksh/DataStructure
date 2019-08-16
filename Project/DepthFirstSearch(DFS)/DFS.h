#pragma once
#include <iostream>
#include <stack>
#include "Location2D.h"
/*
	DFS : ���� �ֱٿ� ������ ��θ� Ȯ��(����)
		- �ѹ� ������ ���� �ٽ� ���� �ʴ´�.
		- ù��° ���� ��ġ�� ���ÿ� �־��ָ� Ž���� ���۵ȴ�.
		- �켱������ ���� �� �� �ִ� ������ ��� ���ÿ� ������� �ִ´�.
		- ������ ��ġ�� �ⱸ�� ���ų� ���̻� �� �� �ִ� ��ġ�� ���������� ��ӵȴ�.
		- ���� ������ ���� ���°� �Ǹ� �̷θ� �������� �� ����.����
		- ���� ���� ��ġ(r, c)�� �ⱸ�� ���ٸ� ���������� ����������.����
		-
*/

class DFS
{
private:
	std::stack<Location2D> stackPos;

public:
	void SetStartPosition(const int& r, const int& c);
	bool StartMazeSearch();
};

