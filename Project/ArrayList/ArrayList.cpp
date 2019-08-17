#include "ArrayList.h"

void ArrayList::Insert(const int & pos, const int & item)
{
	/* ※삽입은 기본적으로 중간에 비는 공간이 없도록 한다. */
	
	// 삽입 위치가 전체 사이즈를 넘어갔다면, 에러메시지를 반환한다.
	if (pos > MAX_SIZE) {
		std::cout << "삽입 위치가 전체 배열 사이즈를 초과하므로 불가능 합니다." << std::endl;
		return;
	}
	
	// 삽입할 공간이 없다면, 에러메시지를 반환한다.
	if (IsFull()) {
		return;
	}

	// 삽입 위치가 length <= pos 라면 가장 끝 부분인 length에 삽입한다.
	if (length <= pos) {
		if(length<pos)
			std::cout << "삽입 위치를 자동 조절하여 끝부분에 추가합니다" << std::endl;
		arrList[length] = item;
		++length;
		return;
	}

	// 만약 length 미만의 중간 삽입을 한다면, pos부터 모든 배열을 한칸씩 뒤로 밀고 해당 위치에 넣는다.
	if (length > pos) {
		// 끝부분부터 하나씩 옮긴다.
		for (int i = length; i >= pos; --i) {
			arrList[i + 1] = arrList[i];
		}
		arrList[pos] = item;
		++length;
	}
}

void ArrayList::Remove(const int & pos)
{
	// 비어잇다면 삭제할게 없어 == length = 0 = pos
	if (IsEmpty()) {
		return;
	}

	// pos > length 제거할 대상이 없음 (pos>MAX_SIZE 포함됨)
	if (pos > length) {
		std::cout << "제거할 대상이 없습니다" << std::endl;
		return;
	}
	// pos == length 마지막 부분 제거하고(-1 대입으로함) length-- 하면 됨.
	if (pos == length) {
		arrList[pos] = -1; // 일종의 제거, 해제효과.
		--length;
		return;
	}
	// pos < length 중간 삭제라면 해당 부분을 덮어쓰기함. pos = pos+1;
	if (pos < length) {
		for (int i = pos; i < length; ++i) {
			arrList[i] = arrList[i + 1];
		}
		arrList[length] = -1;
		--length;
	}
}

int ArrayList::GetEntry(const int & pos)
{
	return arrList[pos];
}

int ArrayList::Find(const int & item)
{
	for (int i = 0; i < length; ++i) {
		if (arrList[i] == item){
			std::cout << "item을 발견했습니다 해당 인덱스는 : " << i << std::endl;
			return i;
		}
	}
	std::cout << "item을 발견하지 못했습니다" << std::endl;
	return -1;
}

bool ArrayList::IsFull()
{
	if (length >= MAX_SIZE) {
		std::cout << "공간이 모두 꽉차서 추가할 수 없습니다." << std::endl;
		return true;
	}
	return false;
}

bool ArrayList::IsEmpty()
{
	if (length == 0){
		std::cout << "공간이 비었습니다" << std::endl;
		return true;
	}
	return false;
}

int ArrayList::GetSize()
{
	return length;
}

void ArrayList::Print()
{
	for (int i = 0; i < length; ++i) {
		printf("[%d] ", arrList[i]);
	}
	printf("\n");
}
