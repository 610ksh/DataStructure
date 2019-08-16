#pragma once
//#include <iostream>

const int MAX_SIZE = 6;

static char maze[MAX_SIZE][MAX_SIZE] = {
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
};

// 현재 위치를 기록하는 클래스
class Location2D
{
public:
	int row;
	int col;
	
public:
	Location2D(int r = 0, int c = 0)
		:row(r), col(c) {};
	
	// 현재 위치가 유효한지 체크
	bool isValied(const int& r, const int& c)
	{
		// MAZE 내부인지 체크
		if (r < 0 || c < 0 || r >= MAX_SIZE || c >= MAX_SIZE)
			return false;
		// 내부가 맞다면 그곳이 갈 수 있는 곳인지 체크
		else
			return maze[r][c] == '0' || maze[r][c] == 'x';
	}
};

