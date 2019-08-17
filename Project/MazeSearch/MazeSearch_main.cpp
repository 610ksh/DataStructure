#include "DFS.h"
#include "BFS.h"
/*
	2019, August, 16

	Notice)
	1. Search priority : up > down > left > right
	2. All of position for maze consist of row and column

	DFS : stack
	BFS : queue
*/



int main()
{
	DFS dfs;
	dfs.SetStartPosition(1, 0);
	dfs.StartMazeSearch();

	BFS bfs;
	bfs.SetStartPosition(1, 0);
	bfs.StartMazeSearch();

	return 0;
}