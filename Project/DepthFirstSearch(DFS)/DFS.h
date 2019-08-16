#pragma once
#include <iostream>
#include <stack>
#include "Location2D.h"
/*
	DFS : 가장 최근에 저장한 경로를 확인(스택)
		- 한번 지나간 방을 다시 가지 않는다.
		- 첫번째 시작 위치를 스택에 넣어주면 탐색이 시작된다.
		- 우선순위에 따라 갈 수 있는 영역을 모두 스택에 순서대로 넣는다.
		- 현재의 위치가 출구와 같거나 더이상 갈 수 있는 위치가 없을때까지 계속된다.
		- 만약 스택이 공백 상태가 되면 미로를 빠져나갈 수 없다.실패
		- 만약 현재 위치(r, c)이 출구와 같다면 성공적으로 빠져나간다.성공
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

