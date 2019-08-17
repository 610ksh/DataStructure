#pragma once
#include <iostream>

// arrayList의 가장 큰 단점은 사이즈가 고정되어 있다는점.
const int MAX_SIZE = 10;

class ArrayList
{
private:
	// int형 배열로 잡았다. 템플릿을 사용하면 정의와 구현을 합쳐야하기 때문에 번거로움.
	int arrList[MAX_SIZE] = { -1 };
	// 시작은 0이다. 최대 MAX_SIZE 이전까지 생성가능.
	int length;
public:
	/* ADT */

	// 기본 생성자
	ArrayList() { length = 0; }
	// 삽입
	void Insert(const int& pos, const int& item);
	// 삭제
	void Remove(const int& pos);
	// 읽기
	int GetEntry(const int& pos);
	// 검색
	int Find(const int& item);
	// 가득찼는지
	bool IsFull();
	// 비었는지
	bool IsEmpty();
	// 현재 사이즈는?
	int GetSize();
	// 출력
	void Print();
};

