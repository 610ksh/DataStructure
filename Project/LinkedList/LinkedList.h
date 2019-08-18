#pragma once
#include <iostream>
#include <list> // 이중 연결 리스트

struct Node {
	// 실제 데이터
	int data;
	// 다음 노드 주소를 가리키는 변수
	Node* next;
};

// 단방향 연결리스트
class LinkedList
{
private:
	// 머리위치
	Node* head;
	//Node* tail;
	int size;

public:
	// 삽입
	void Insert(const int& pos, const int& item);
	void Push_back(const int & item);
	// 삭제
	void Remove(const int& pos);
	// 읽기
	int GetEntry(const int& pos);
	// 검색
	int Find(const int& item);
	// 비었는지
	bool IsEmpty();
	// 현재 사이즈는?
	int GetSize();
	// 출력
	void Print();

public:
	LinkedList();
	~LinkedList();
};

