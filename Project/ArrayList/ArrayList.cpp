#include "ArrayList.h"

void ArrayList::Insert(const int & pos, const int & item)
{
	/* �ػ����� �⺻������ �߰��� ��� ������ ������ �Ѵ�. */
	
	// ���� ��ġ�� ��ü ����� �Ѿ�ٸ�, �����޽����� ��ȯ�Ѵ�.
	if (pos > MAX_SIZE) {
		std::cout << "���� ��ġ�� ��ü �迭 ����� �ʰ��ϹǷ� �Ұ��� �մϴ�." << std::endl;
		return;
	}
	
	// ������ ������ ���ٸ�, �����޽����� ��ȯ�Ѵ�.
	if (IsFull()) {
		return;
	}

	// ���� ��ġ�� length <= pos ��� ���� �� �κ��� length�� �����Ѵ�.
	if (length <= pos) {
		if(length<pos)
			std::cout << "���� ��ġ�� �ڵ� �����Ͽ� ���κп� �߰��մϴ�" << std::endl;
		arrList[length] = item;
		++length;
		return;
	}

	// ���� length �̸��� �߰� ������ �Ѵٸ�, pos���� ��� �迭�� ��ĭ�� �ڷ� �а� �ش� ��ġ�� �ִ´�.
	if (length > pos) {
		// ���κк��� �ϳ��� �ű��.
		for (int i = length; i >= pos; --i) {
			arrList[i + 1] = arrList[i];
		}
		arrList[pos] = item;
		++length;
	}
}

void ArrayList::Remove(const int & pos)
{
	// ����մٸ� �����Ұ� ���� == length = 0 = pos
	if (IsEmpty()) {
		return;
	}

	// pos > length ������ ����� ���� (pos>MAX_SIZE ���Ե�)
	if (pos > length) {
		std::cout << "������ ����� �����ϴ�" << std::endl;
		return;
	}
	// pos == length ������ �κ� �����ϰ�(-1 ����������) length-- �ϸ� ��.
	if (pos == length) {
		arrList[pos] = -1; // ������ ����, ����ȿ��.
		--length;
		return;
	}
	// pos < length �߰� ������� �ش� �κ��� �������. pos = pos+1;
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
			std::cout << "item�� �߰��߽��ϴ� �ش� �ε����� : " << i << std::endl;
			return i;
		}
	}
	std::cout << "item�� �߰����� ���߽��ϴ�" << std::endl;
	return -1;
}

bool ArrayList::IsFull()
{
	if (length >= MAX_SIZE) {
		std::cout << "������ ��� ������ �߰��� �� �����ϴ�." << std::endl;
		return true;
	}
	return false;
}

bool ArrayList::IsEmpty()
{
	if (length == 0){
		std::cout << "������ ������ϴ�" << std::endl;
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
