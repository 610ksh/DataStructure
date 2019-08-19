#include "LinkedList.h"


// 초기화
LinkedList::LinkedList()
{
	// 더미노드를 가리킨다.
	head = new Node;
	head->next = nullptr;
	head->data = -9999999; // -1로 그냥 초기화
	size = 0;
}

// 해제
LinkedList::~LinkedList()
{
	// 양방향 아니면, 해제할때 앞에서부터 하는게 나을듯.
	for (int i = 0, j = size; i < j; ++i) {
		Remove(0);
	}
	delete head;
	head = nullptr;
}

void LinkedList::Push_back(const int & item)
{
	Node* preNode = head;
	// 마지막 노드 전까지 이동
	while (!(preNode->next == nullptr)) {
		preNode = preNode->next;
	}
	// 다음 노드에 새로 생성
	preNode->next = new Node;
	preNode->next->data = item;
	preNode->next->next = nullptr;
	++size;

	/*
		더미노드가 없을때 코드
	*/
	//// 빈 노드라면
	//if (IsEmpty()) {
	//	//Node* newNode = new Node;
	//	head = new Node;
	//	head->data = item;
	//	head->next = nullptr;
	//	++size;
	//}
	//else {
	//	Node* curNode = head;
	//	// 갯수-1 만큼 노드 이동
	//	for (int i = 0; i < size - 1; ++i) {
	//		curNode = curNode->next;
	//	}
	//	curNode->next = new Node;
	//	curNode->next->data = item;
	//	curNode->next->next = nullptr;
	//	++size;
	//}
}

void LinkedList::Insert(const int & pos, const int & item)
{
	// 음수로 
	if (pos < 0) {
		std::cout << "error, pos is not positive index" << std::endl;
		return;
	}
	// 사이즈보다 큰 곳에 삽입
	if (size <= pos) {
		Push_back(item);
		return;
	}
	else {
		Node* preNode = head;
		for (int i = 0; i < pos; ++i) {
			preNode = preNode->next;
		}
		// 삽입 노드 생성
		Node* insertNode = new Node;
		insertNode->data = item;
		// 삽입 노드를 다음 노드와 연결
		insertNode->next = preNode->next;
		// 이전 노드를 새로운 노드에 연결
		preNode->next = insertNode;
		++size;
	}

	/*
		더미노드가 없을때 코드
	*/
	//// 비었을때
	//if (IsEmpty()) {
	//	std::cout << "list is empty" << std::endl;
	//	return;
	//}
	//// 전체 사이즈보다 큰 곳에 삽입할때
	//if (size <= pos) {
	//	// 맨 뒤에 추가한다.
	//	Push_back(item);
	//	return;
	//}
	//// 0번째 삽입
	//if (pos == 0) {
	//	Node* insertNode = new Node;
	//	insertNode->data = item;
	//	insertNode->next = head;
	//	head = insertNode;
	//	++size;
	//}
	//// 그 이상에 삽입
	//else {
	//	Node* insertNode = new Node;
	//	insertNode->data = item;
	//	Node* preNode = head; // 삽입 이전 노드
	//	for (int i = 0; i < pos - 1; ++i) {
	//		preNode = preNode->next;
	//	}
	//	insertNode->next = preNode->next;
	//	preNode->next = insertNode;
	//	++size;
	//}
}


void LinkedList::Remove(const int & pos)
{
	// 음수로 
	if (pos < 0) {
		std::cout << "error, pos is not positive index" << std::endl;
		return;
	}
	// 
	if (size <= pos) {
		std::cout << "Out of range. current list size is : " << size << std::endl;
		return;
	}
	else {
		Node* preNode = head;
		for (int i = 0; i < pos; ++i) {
			preNode = preNode->next;
		}
		// 삭제 노드 지정
		Node* delNode = preNode->next;

		// 마지막 노드를 삭제한다면
		if (pos == size - 1) {
			preNode->next = nullptr;
		}
		else {
			preNode->next = delNode->next;
		}
		// 삭제노드 전후로 재연결
		// 삭제노드 해제
		delete delNode;
		--size;
	}

	/*
		더미노드가 없을때 코드
	*/
	//// 비었을때
	//if (IsEmpty()) {
	//	head = new Node;
	//	head->next = nullptr;
	//	--size;
	//	return;
	//}
	//if (size <= pos) {
	//	std::cout << "out of size. current list size is : " << size << std::endl;
	//	return;
	//}
	//// 0번째 삽입
	//if (pos == 0) {
	//	Node* preNode = head;
	//	head = head->next;
	//	delete preNode;
	//	--size;
	//}
	//// 그 이상에 삽입
	//else {
	//	Node* preNode = head;
	//	for (int i = 0; i < pos - 1; ++i) {
	//		preNode = preNode->next;
	//	}
	//	Node* deleteNode = preNode->next;
	//	if (!(deleteNode->next == nullptr)) {
	//		preNode->next = deleteNode->next;
	//		delete deleteNode;
	//	}
	//	else {
	//		preNode->next = nullptr;
	//		delete deleteNode;
	//	}
	//	--size;
	//}
}

int LinkedList::GetEntry(const int & pos)
{
	Node* preNode = head;
	for (int i = 0; i < pos; ++i) {
		preNode = preNode->next;
	}
	return preNode->next->data;
}

// 순차탐색 O(n)
bool LinkedList::Find(const int & item)
{
	Node* preNode = head;
	for (int i = 0; i < size; ++i) {
		if (preNode->next->data == item) {
			std::cout << "index : " << i << std::endl;
			return true;
		}
		preNode = preNode->next;
	}
	std::cout << "not exist" << std::endl;
	return false;

	/*
		더미노드가 없을때 코드
	*/
	//// 첫번째 검색
	//Node* curNode = head;
	//if (curNode->data == item) {
	//	std::cout << "Find it, index : 0" << std::endl;
	//	return true;
	//}
	//// 두번째부터 검색
	//for (int i = 0; i < size - 1; ++i) {
	//	curNode = curNode->next;
	//	if (curNode->data == item) {
	//		std::cout << "Find it, index : " << i + 1 << std::endl;
	//		return true;
	//	}
	//}
	//std::cout << "not exist" << std::endl;
	//return false;
}

bool LinkedList::IsEmpty()
{
	if (head->next == nullptr)
		return true;
	return false;
}

int LinkedList::GetSize()
{
	return size;
}

void LinkedList::Print()
{
	Node* preNode = head;
	for (int i = 0; i < size; ++i) {
		printf("[%d] ", preNode->next->data);
		preNode = preNode->next;
	}
	printf("\n");
}

void LinkedList::Clear()
{
	LinkedList::~LinkedList();
}
