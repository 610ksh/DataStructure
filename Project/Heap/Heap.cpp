#include "Heap.h"

// 전역 함수
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
	// 비었으면
	if (numOfData == 0)
		return true;
	// 하나라도 있으면
	return false;
}

void Heap::Insert(const char& data)
{
	// 삽입할 위치의 인덱스, 최초시작은 마지막부터
	int insertIDX = numOfData + 1;

	// 루트 노드까지 부모와 비교
	while (insertIDX != 1) {
		// 부모노드보다 우선순위가 더 높다면
		if (heapArr[GetParentIDX(insertIDX)] > data) {
			// 부모노드를 자식노드 인덱스로 교체(실질적으로 복사)
			heapArr[insertIDX] = heapArr[GetParentIDX(insertIDX)];
			insertIDX = GetParentIDX(insertIDX);
		}
		else
			break;
	}

	// 최종적으로 삽입
	heapArr[insertIDX] = data;
	++numOfData;
}

int Heap::Delete()
{
	// 마지막 노드를 루트 노드부터 검사
	int parentIDX = 1;
	int childIDX;
	// 삭제할 노드 데이터 반환을 위해 저장
	const int deleteData = heapArr[1];

	// 우선순위가 더 높은 자식 노드가 존재할때까지 계속 찾아감
	while (childIDX = GetHighPriChildIDX(parentIDX)) {
		// 만약 마지막 노드가 우선순위가 더 크다면 중단
		if (comp(heapArr[numOfData], heapArr[childIDX]) <= 0)
			break;
		// 자식노드의 값을 부모 노드로 교체(복사)
		heapArr[parentIDX] = heapArr[childIDX];
		parentIDX = childIDX;
	}

	// 마지막 데이터 삽입(복제)
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

// 우선순위가 더 높은 자식을 반환(더 작은수)
int Heap::GetHighPriChildIDX(const int & idx)
{
	// 자식 노드 x
	if (GetLChildIDX(idx) > numOfData)
		return 0;
	// 자식 노드 1
	else if (GetLChildIDX(idx) == numOfData)
		return GetLChildIDX(idx);
	// 자식 노드 2
	else {
		// 왼쪽 노드가 더 우선순위가 높다면
		if (comp(heapArr[GetLChildIDX(idx)], heapArr[GetRChildIDX(idx)]) > 0) {
			return GetRChildIDX(idx);
		}
		else
			return GetLChildIDX(idx);
	}
}