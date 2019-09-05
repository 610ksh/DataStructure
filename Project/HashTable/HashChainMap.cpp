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

// ���κп� �߰�.
void HashChainMap::AddRecord(const std::string& key, const std::string& value)
{
	// hash�� ����
	int hashValue = HashFunction(key);

	// ����ִ� key���̶��
	if (table[hashValue] == nullptr) {
		// create new node
		Node* initialNode = new Node(key,value);
		// table�� ���ο� ��带 �����Ѵ�.
		table[hashValue] = initialNode;
		return;
	}

	Node* tableNode = table[hashValue];
	// hash���� �̿��ؼ� ���̺� ����. ���̺��� �̹� �����Ѵٸ�
	if (tableNode->IsEqual(key)) {
		std::cout << "�ߺ��Ǵ� Ű���� �̹� �����մϴ�" << std::endl;
		return;
	}

	// table�� �Ⱥ���ٸ�
	while (tableNode->GetLink() != nullptr) {
		// ���� ���̺� �̹� Ű ���� �����ϸ� Ż��.
		if (tableNode->IsEqual(key)) {
			std::cout << "�ߺ��Ǵ� Ű���� �̹� �����մϴ�" << std::endl;
			return;
		}
		// ���� ���� �̵�
		tableNode = tableNode->GetLink();
	}
	// ���� ���̺� �ؽð��� �浹�� �߻��ϸ�, �ش� �ؽð��� �ش��ϴ� ���̺��� �ǵ� ��ũ�� �޾ƿ���. �׸��� ��� ���̱�.
	tableNode->SetLink(key, value);
}

Node* HashChainMap::SearchRecord(const std::string& key)
{
	// hash�� ����
	int hashValue = HashFunction(key);
	Node* tableNode = table[hashValue];

	if (tableNode == nullptr) {
		std::cout << "key���� �ش��ϴ� ���� �����ϴ�" << std::endl;
		return nullptr;
	}

	// �� ��Ŷ�� ��� ��ȸ�ϸ鼭 Ȯ���Ѵ�.
	while (tableNode->GetLink() != nullptr) {
		if (tableNode->GetKey() == key) {
			printf("[%s] Ž������", key.c_str());
			tableNode->Print();
			return tableNode->GetLink();
		}
		// ���� ���� �̵�.
		tableNode = tableNode->GetLink();
	} // ���������� �̵���

	// ���������� Ȯ�� 
	if (tableNode->GetKey() == key) {
		printf("[%s] Ž������[%d]", key.c_str(),hashValue);
		tableNode->Print();
		return tableNode->GetLink();
	}
	return nullptr;
}