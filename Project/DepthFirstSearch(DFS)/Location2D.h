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

// ���� ��ġ�� ����ϴ� Ŭ����
class Location2D
{
public:
	int row;
	int col;
	
public:
	Location2D(int r = 0, int c = 0)
		:row(r), col(c) {};
	
	// ���� ��ġ�� ��ȿ���� üũ
	bool isValied(const int& r, const int& c)
	{
		// MAZE �������� üũ
		if (r < 0 || c < 0 || r >= MAX_SIZE || c >= MAX_SIZE)
			return false;
		// ���ΰ� �´ٸ� �װ��� �� �� �ִ� ������ üũ
		else
			return maze[r][c] == '0' || maze[r][c] == 'x';
	}
};

