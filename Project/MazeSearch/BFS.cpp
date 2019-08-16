#include "BFS.h"

void BFS::SetStartPosition(const int & r, const int & c)
{
	Location2D entry(r, c);
	queuePos.push(entry);
}

bool BFS::StartMazeSearch()
{
	// queue�� �������� ����
	while (queuePos.empty() == false) {
		// ���ÿ� ����� top �κ��� ����(���������)
		Location2D currentPos = queuePos.front();
		// ���� ��ġ ���
		printf("(%d,%d) ", currentPos.row, currentPos.col);
		int r = currentPos.row;
		int c = currentPos.col;

		// ���ÿ��� ����
		queuePos.pop();
		count++;

		// ���� ��ġ�� ���������̶�� ����
		if (maze2[r][c] == 'x') {
			std::cout << "Success to search for maze" << std::endl;
			std::cout << "Search count is : " << count << std::endl;
			return true;
		}
		// �װ� �ƴ϶�� �� �� �� �� ���� Ȯ���� ��� ���ÿ� ������� �ֱ�
		else {
			// �����±� ��ŷ
			maze2[r][c] = '.';

			// ��
			if (currentPos.isValied2(r - 1, c)) {
				queuePos.push(Location2D(r - 1, c));
			}
			// ��
			if (currentPos.isValied2(r + 1, c)) {
				queuePos.push(Location2D(r + 1, c));
			}
			// ��
			if (currentPos.isValied2(r, c - 1)) {
				queuePos.push(Location2D(r, c - 1));
			}
			// ��
			if (currentPos.isValied2(r, c + 1)) {
				queuePos.push(Location2D(r, c + 1));
			}
		}
	}

	// ���ÿ��� ���������� ã�����߱� ������ false
	std::cout << "Fail to search for maze" << std::endl;
	return false;
}
