#pragma once
#include "Location2D.h"
#include <iostream>
#include <queue>

class BFS
{
private:
	std::queue<Location2D> queuePos;
	int count = 0;

public:
	void SetStartPosition(const int& r, const int& c);
	bool StartMazeSearch();
};

