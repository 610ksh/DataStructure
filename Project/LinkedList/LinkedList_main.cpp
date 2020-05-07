#include "LinkedList.h"

/*
	단일 연결리스트
	#include <list> // 이중 연결 리스트
	Dummy Node가 있고 없고 둘다 구현했으며,
	없는 로직은 주석처리하고 더미 노드 있는것을 활성화
	
									August 19 2019.
	Copyright 2019. SungHoon Kim. All rights reserved.
*/

int main()
{
	LinkedList list;
	list.Push_back(1); // 1
	list.Push_back(2); // 1 2
	list.Push_back(3); // 1 2 3
	list.Push_back(4); // 1 2 3 4
	list.Insert(0, 10); // 10 1 2 3 4 
	list.Insert(1, 11); // 10 11 1 2 3 4
	list.Insert(3, 12); // 10 11 1 12 2 3 4
	list.Insert(10, 13); // 10 11 1 12 2 3 4 13
	list.Find(13);
	list.Print();
	list.Find(4);
	list.Find(14);
	list.Remove(9); // out of range
	list.Remove(8); // out of range
	list.Remove(0); // 10
	list.Remove(2); // 12
	list.Print();
	list.Clear();
	return 0;
}