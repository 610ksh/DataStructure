#include "HashChainMap.h"

HashChainMap::HashChainMap()
{
	for (int i = 0; i < TABLE_SIZE; ++i) {
		table[i] = nullptr;
	}
}

void HashChainMap::Print()
{
	for (int i = 0; i < TABLE_SIZE; ++i) {
		printf("[%2d] ", i);
		for (Node *j = table[i]; j != nullptr; j = j->GetLink())
			printf("%10s", j->GetKey().c_str());
		printf("\n");
	}
}

// 끝부분에 추가.
void HashChainMap::AddRecord(const std::string& key, const std::string& value)
{
	// hash값 생성
	int hashValue = HashFunction(key);

	// 비어있는 key값이라면
	if (table[hashValue] == nullptr) {
		// create new node
		Node* initialNode = new Node(key,value);
		// table과 새로운 노드를 연결한다.
		table[hashValue] = initialNode;
		return;
	}

	Node* tableNode = table[hashValue];
	// hash값을 이용해서 테이블 조사. 테이블이 이미 존재한다면
	if (tableNode->IsEqual(key)) {
		std::cout << "중복되는 키값이 이미 존재합니다" << std::endl;
		return;
	}

	// table이 안비었다면
	while (tableNode->GetLink() != nullptr) {
		// 만약 테이블에 이미 키 값이 존재하면 탈출.
		if (tableNode->IsEqual(key)) {
			std::cout << "중복되는 키값이 이미 존재합니다" << std::endl;
			return;
		}
		// 다음 노드로 이동
		tableNode = tableNode->GetLink();
	}
	// 만약 테이블 해시값이 충돌이 발생하면, 해당 해시값에 해당하는 테이블의 맨뒤 링크를 받아오기. 그리고 노드 붙이기.
	tableNode->SetLink(key, value);
}

Node* HashChainMap::SearchRecord(const std::string& key)
{
	// hash값 생성
	int hashValue = HashFunction(key);
	Node* tableNode = table[hashValue];

	if (tableNode == nullptr) {
		std::cout << "key값에 해당하는 노드는 없습니다" << std::endl;
		return nullptr;
	}

	// 한 버킷을 모두 순회하면서 확인한다.
	while (tableNode->GetLink() != nullptr) {
		if (tableNode->GetKey() == key) {
			printf("[%s] 탐색성공", key.c_str());
			tableNode->Print();
			return tableNode->GetLink();
		}
		// 다음 노드로 이동.
		tableNode = tableNode->GetLink();
	} // 마지막까지 이동함

	// 최종적으로 확인 
	if (tableNode->GetKey() == key) {
		printf("[%s] 탐색성공[%d]", key.c_str(),hashValue);
		tableNode->Print();
		return tableNode->GetLink();
	}
	return nullptr;
}