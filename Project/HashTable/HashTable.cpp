#include "HashTable.h"

HashTable::HashTable()
{
	Reset();
}

void HashTable::Reset()
{
	for (auto i : table)
		i.Reset();
}

void HashTable::Print()
{
	for (int i = 0; i < TABLE_SIZE;++i) {
		printf("[%2d] ", i);
		table[i].Print();
	}
}

// Ű �߰�
void HashTable::AddLinearProb(const std::string& key, const std::string& value)
{
	int i, hashValue;
	hashValue = i = HashFunction(key);
	
	// ���ڸ��� ���ö����� �ݺ�
	while (table[i].IsEmpty() == false) {
		// ���� �ڸ��� �����ϴ� Ž��key�� �����ϴٸ� �ߴ�
		if (table[i].IsEqual(key)) {
			printf("[%s] Ž��Ű�� �ߺ��Ǿ����ϴ�.\n", key.c_str());
			return;
		}
		/// ���� �����
		// + 1 ĭ �̵�
		 i = (i + 1) % TABLE_SIZE;
		
		
		// �̵��Ѱ� ���ڸ���� �ߴ�
		if (i == hashValue) {
			printf("[%s] ���̺��� ����á���ϴ�.\n", key.c_str());
			return;
		}
	}
	table[i].SetRecord(key, value);
}

Record* HashTable::SearchLinearProb(const std::string & key)
{
	int i, hashValue;
	hashValue = i = HashFunction(key);
	// ���̺��� ��������
	while (table[i].IsEmpty() == false) {
		// ���� �ش��ϴ� ���̺��� key���� �����ϴٸ�
		if (table[i].IsEqual(key)) {
			printf("[%s] Ž������[%d]", key.c_str(), i);
			table[i].Print();
			return table + i;
		}
		// + 1 ĭ �̵�
		i = (i + 1) % TABLE_SIZE;
		// �̵��Ѱ� ���ڸ��� ���ƿԴٸ� �ߴ�
		if (i == hashValue) break;
	}
	// ���� ���Ҵµ� �߰����� ���ߴٸ�
	printf("[%s] Ž�� ���� : ã�� ���� ���̺� ����\n", key.c_str());
	return nullptr;
}