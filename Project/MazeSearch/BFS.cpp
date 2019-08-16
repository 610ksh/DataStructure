#include "BFS.h"

void BFS::SetStartPosition(const int & r, const int & c)
{
	Location2D entry(r, c);
	queuePos.push(entry);
}

bool BFS::StartMazeSearch()
{
	// queue가 빌때까지 진행
	while (queuePos.empty() == false) {
		// 스택에 저장된 top 부분을 뽑음(복사생성자)
		Location2D currentPos = queuePos.front();
		// 현재 위치 출력
		printf("(%d,%d) ", currentPos.row, currentPos.col);
		int r = currentPos.row;
		int c = currentPos.col;

		// 스택에서 뽑음
		queuePos.pop();
		count++;

		// 현재 위치가 도착지점이라면 종료
		if (maze2[r][c] == 'x') {
			std::cout << "Success to search for maze" << std::endl;
			std::cout << "Search count is : " << count << std::endl;
			return true;
		}
		// 그게 아니라면 상 하 좌 우 조건 확인후 모두 스택에 순서대로 넣기
		else {
			// 지나온길 마킹
			maze2[r][c] = '.';

			// 상
			if (currentPos.isValied2(r - 1, c)) {
				queuePos.push(Location2D(r - 1, c));
			}
			// 하
			if (currentPos.isValied2(r + 1, c)) {
				queuePos.push(Location2D(r + 1, c));
			}
			// 좌
			if (currentPos.isValied2(r, c - 1)) {
				queuePos.push(Location2D(r, c - 1));
			}
			// 우
			if (currentPos.isValied2(r, c + 1)) {
				queuePos.push(Location2D(r, c + 1));
			}
		}
	}

	// 스택에서 빠져나오면 찾지못했기 때문에 false
	std::cout << "Fail to search for maze" << std::endl;
	return false;
}
