#include "Heap.h"

// ���� �Լ�
int DataPriorityComp(const char& ch1, const char& ch2)
{
	return ch1 - ch2;
}


Heap::Heap()
{
	numOfData = 0;
	comp = DataPriorityComp;
}

bool Heap::IsEmpty()
{
	// �������
	if (numOfData == 0)
		return true;
	// �ϳ��� ������
	return false;
}

void Heap::Insert(const char& data)
{
	// ������ ��ġ�� �ε���, ���ʽ����� ����������
	int insertIDX = numOfData + 1;

	// ��Ʈ ������ �θ�� ��
	while (insertIDX != 1) {
		// �θ��庸�� �켱������ �� ���ٸ�
		if (heapArr[GetParentIDX(insertIDX)] > data) {
			// �θ��带 �ڽĳ�� �ε����� ��ü(���������� ����)
			heapArr[insertIDX] = heapArr[GetParentIDX(insertIDX)];
			insertIDX = GetParentIDX(insertIDX);
		}
		else
			break;
	}

	// ���������� ����
	heapArr[insertIDX] = data;
	++numOfData;
}

int Heap::Delete()
{
	// ������ ��带 ��Ʈ ������ �˻�
	int parentIDX = 1;
	int childIDX;
	// ������ ��� ������ ��ȯ�� ���� ����
	const int deleteData = heapArr[1];

	// �켱������ �� ���� �ڽ� ��尡 �����Ҷ����� ��� ã�ư�
	while (childIDX = GetHighPriChildIDX(parentIDX)) {
		// ���� ������ ��尡 �켱������ �� ũ�ٸ� �ߴ�
		if (comp(heapArr[numOfData], heapArr[childIDX]) <= 0)
			break;
		// �ڽĳ���� ���� �θ� ���� ��ü(����)
		heapArr[parentIDX] = heapArr[childIDX];
		parentIDX = childIDX;
	}

	// ������ ������ ����(����)
	heapArr[parentIDX] = heapArr[numOfData];
	--numOfData;
	return deleteData;
}

int Heap::GetParentIDX(const int & idx)
{
	return idx / 2;
}

int Heap::GetLChildIDX(const int & idx)
{
	return idx * 2;
}

int Heap::GetRChildIDX(const int & idx)
{
	return idx * 2 + 1;
}

// �켱������ �� ���� �ڽ��� ��ȯ(�� ������)
int Heap::GetHighPriChildIDX(const int & idx)
{
	// �ڽ� ��� x
	if (GetLChildIDX(idx) > numOfData)
		return 0;
	// �ڽ� ��� 1
	else if (GetLChildIDX(idx) == numOfData)
		return GetLChildIDX(idx);
	// �ڽ� ��� 2
	else {
		// ���� ��尡 �� �켱������ ���ٸ�
		if (comp(heapArr[GetLChildIDX(idx)], heapArr[GetRChildIDX(idx)]) > 0) {
			return GetRChildIDX(idx);
		}
		else
			return GetLChildIDX(idx);
	}
}