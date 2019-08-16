#include "DFS.h"

void DFS::SetStartPosition(const int & r, const int & c)
{
	// ��ġ ��ü ����
	Location2D entry(r, c);
	// ���ÿ� �߰�
	stackPos.push(entry);
}

bool DFS::StartMazeSearch()
{
	// stack�� �������� ����
	while (stackPos.empty() == false) {
		// ���ÿ� ����� top �κ��� ����(���������)
		Location2D currentPos = stackPos.top();
		// ���� ��ġ ���
		printf("(%d,%d) ", currentPos.row, currentPos.col);
		int r = currentPos.row;
		int c = currentPos.col;

		// ���ÿ��� ����
		stackPos.pop();

		// ���� ��ġ�� ���������̶�� ����
		if (maze[r][c] == 'x') {
			std::cout << "Success to search for maze" << std::endl;
			return true;
		}
		// �װ� �ƴ϶�� �� �� �� �� ���� Ȯ���� ��� ���ÿ� ������� �ֱ�
		else {
			// �����±� ��ŷ
			maze[r][c] = '.';

			// ��
			if (currentPos.isValied(r - 1, c)) {
				stackPos.push(Location2D(r - 1, c));
			}
			// ��
			if (currentPos.isValied(r + 1, c)) {
				stackPos.push(Location2D(r + 1, c));
			}
			// ��
			if (currentPos.isValied(r, c - 1)) {
				stackPos.push(Location2D(r, c - 1));
			}
			// ��
			if (currentPos.isValied(r, c + 1)) {
				stackPos.push(Location2D(r, c + 1));
			}
		}
	}

	// ���ÿ��� ���������� ã�����߱� ������ false
	std::cout << "Fail to search for maze" << std::endl;
	return false;
}
