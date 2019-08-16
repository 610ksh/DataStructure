#include "DFS.h"

void DFS::SetStartPosition(const int & r, const int & c)
{
	// 위치 객체 생성
	Location2D entry(r, c);
	// 스택에 추가
	stackPos.push(entry);
}

bool DFS::StartMazeSearch()
{
	// stack이 빌때까지 진행
	while (stackPos.empty() == false) {
		// 스택에 저장된 top 부분을 뽑음(복사생성자)
		Location2D currentPos = stackPos.top();
		// 현재 위치 출력
		printf("(%d,%d) ", currentPos.row, currentPos.col);
		int r = currentPos.row;
		int c = currentPos.col;

		// 스택에서 뽑음
		stackPos.pop();

		// 현재 위치가 도착지점이라면 종료
		if (maze[r][c] == 'x') {
			std::cout << "Success to search for maze" << std::endl;
			return true;
		}
		// 그게 아니라면 상 하 좌 우 조건 확인후 모두 스택에 순서대로 넣기
		else {
			// 지나온길 마킹
			maze[r][c] = '.';

			// 상
			if (currentPos.isValied(r - 1, c)) {
				stackPos.push(Location2D(r - 1, c));
			}
			// 하
			if (currentPos.isValied(r + 1, c)) {
				stackPos.push(Location2D(r + 1, c));
			}
			// 좌
			if (currentPos.isValied(r, c - 1)) {
				stackPos.push(Location2D(r, c - 1));
			}
			// 우
			if (currentPos.isValied(r, c + 1)) {
				stackPos.push(Location2D(r, c + 1));
			}
		}
	}

	// 스택에서 빠져나오면 찾지못했기 때문에 false
	std::cout << "Fail to search for maze" << std::endl;
	return false;
}
