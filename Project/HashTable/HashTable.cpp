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

// 키 추가
void HashTable::AddLinearProb(const std::string& key, const std::string& value)
{
	int i, hashValue;
	hashValue = i = HashFunction(key);
	
	// 빈자리가 나올때까지 반복
	while (table[i].IsEmpty() == false) {
		// 원래 자리에 존재하는 탐색key가 동일하다면 중단
		if (table[i].IsEqual(key)) {
			printf("[%s] 탐색키가 중복되었습니다.\n", key.c_str());
			return;
		}
		/// 선형 조사법
		// + 1 칸 이동
		 i = (i + 1) % TABLE_SIZE;
		
		
		// 이동한게 제자리라면 중단
		if (i == hashValue) {
			printf("[%s] 테이블이 가득찼습니다.\n", key.c_str());
			return;
		}
	}
	table[i].SetRecord(key, value);
}

Record* HashTable::SearchLinearProb(const std::string & key)
{
	int i, hashValue;
	hashValue = i = HashFunction(key);
	// 테이블이 빌때까지
	while (table[i].IsEmpty() == false) {
		// 만약 해당하는 테이블의 key값이 동일하다면
		if (table[i].IsEqual(key)) {
			printf("[%s] 탐색성공[%d]", key.c_str(), i);
			table[i].Print();
			return table + i;
		}
		// + 1 칸 이동
		i = (i + 1) % TABLE_SIZE;
		// 이동한게 제자리로 돌아왔다면 중단
		if (i == hashValue) break;
	}
	// 전부 돌았는데 발견하지 못했다면
	printf("[%s] 탐색 실패 : 찾는 값이 테이블에 없음\n", key.c_str());
	return nullptr;
}