#include "ArrayList.h"
/*
	std::vector�� ���� �⺻ ������ �Ǵ°� ArrayList�ε�.
	����Ʈ�� ������ O(1)�̴�. �ε��� �������� �ٷ� ���� ����(=�迭)

	stack Ȥ�� queue�� ������ ����غ��̴µ�,
	���� ū ���̴� �߰� ����, �߰� ������ �����ϴٴ� ���̴�.
	stack�� ���Լ��� LIFO, queue�� ���Լ��� FIFO �����̴�.
	������ ��δ� ���� �迭�� �̿��߱⿡ ũ�⿡ �������̴�. ���� �Ұ���.
	
	����, ����Ʈ���� �� �κ��� �����Ҵ����� �Ѵٸ� ũ�� ������ �������.
	�� ���ư� IsFull �Լ��� ������ �������. ���� �����ϱ�.
	�� ��� ���ο� �޸𸮸� �� �Ҵ��ϴ� ������ �����ϰ�,
	������ �޸𸮸� �����ϴ� ������ �ʿ�� �Ѵ�.

	std::vector �� ���� ���� ���Ҵ� ������ ����Ǿ� �ִ�.

	����� �̷��� �߰������� ���Ҵ��ϴ� ������ �ƴ϶�,
	�Ź� ���ο� �����͸� �߰��Ҷ����� �߰� �����Ҵ��� �ϴ� ���°� ���Ḯ��Ʈ �����̴�.
	2019, August, 17.

	Copyright 2019. SungHoon Kim. All rights reserved.
*/

int main()
{
	ArrayList arrList;
	std::cout << "���� ����Ʈ ũ��� : " << arrList.GetSize() << std::endl;
	
	arrList.Insert(3, 5); // 5
	arrList.Insert(1, 1); // 5 1
	arrList.Insert(2, 3); // 5 1 3
	arrList.Print();
	arrList.Insert(0, 4); // 4 5 1 3

	arrList.Remove(2); // 4 5 3
	arrList.Remove(1); // 4 3
	arrList.Print();
	std::cout << "���� ����Ʈ ũ��� : " << arrList.GetSize() << std::endl;

	arrList.Find(3);
	arrList.Find(5);

	return 0;
}