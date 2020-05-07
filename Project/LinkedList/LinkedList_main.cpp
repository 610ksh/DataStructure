#include "LinkedList.h"

/*
	���� ���Ḯ��Ʈ
	#include <list> // ���� ���� ����Ʈ
	Dummy Node�� �ְ� ���� �Ѵ� ����������,
	���� ������ �ּ�ó���ϰ� ���� ��� �ִ°��� Ȱ��ȭ
	
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