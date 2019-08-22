#include "BinarySearchTree.h"


void BinarySearchTree::Insert(const int & data)
{
	BTreeNode* NewNode = new BTreeNode;
	NewNode->data = data;
	NewNode->left = nullptr;
	NewNode->right = nullptr;

	// 트리가 비었으면 루트 노드로 고정
	if (IsEmpty())
		SetRootNode(NewNode);

	BTreeNode* parent = root;

	// 노드 탐색 O(logN)
	while (parent != nullptr) {
		// 만약 이미 같은거라면 중단
		if (parent->data == data) return;
		// 작은것은 왼쪽
		else if (parent->data > data) {
			// 다음 노드가 존재한다면 이동
			if (parent->left != nullptr) {
				parent = parent->left;
			}
			// 다음 노드가 비었다면 거기에 삽입
			else {
				parent->left = NewNode;
				return;
			}
		}
		// 큰것은 오른쪽
		else {
			// 다음 노드가 존재한다면 이동
			if (parent->right != nullptr)
				parent = parent->right;
			// 다음 노드가 비었다면 거기에 삽입
			else {
				parent->right = NewNode;
				return;
			}
		}
	}
}

void BinarySearchTree::Remove(const int & data)
{
	// 트리가 비었다면
	if (IsEmpty()) return;

	// 삭제할 노드가 없으면 생략
	if (!Search(data)) return;

	// 먼저 삭제할 노드와 부모 노드를 찾는다.
	BTreeNode* parentN = nullptr;
	BTreeNode* removeN = root;
	// 같을때까지 찾는다
	while (!(removeN->data == data)) {
		// 현재 노드보다 왼쪽에 있다면
		if (removeN->data > data) {
			// 부모를 기억
			parentN = removeN;
			// 왼쪽 이동
			removeN = removeN->left;
		}
		// 현재 노드보다 오른쪽에 있다면
		else {
			parentN = removeN;
			removeN = removeN->right;
		}
	}// 끝나면 다 찾음

	// 1. 삭제할 노드가 단말노드일때
	if (removeN->left == nullptr && removeN->right == nullptr) {

		// 루트 노드를 대체할때
		if (parentN == nullptr) {
			delete removeN;
			root = nullptr;
			return;
		}
		// 부모의 왼쪽에 달린거면
		if (parentN->left == removeN) {
			parentN->left = nullptr;
			delete removeN;
		}
		else {
			parentN->right = nullptr;
			delete removeN;
		}
	}

	// 2. 삭제할 노드가 자식 1개만 가질때
	else if (removeN->left == nullptr || removeN->right == nullptr) {
		// 자식 노드를 찾아야함.

		// 루트 노드를 대체할때
		if (parentN == nullptr) {
			// root 재설정
			if (root->left != nullptr)
				root = removeN->left;
			else
				root = removeN->right;
			delete removeN;
			return;
		}

		// 자식이 왼쪽에 있을때
		if (removeN->left != nullptr) {
			// 삭제 노드가 부모의 왼쪽 자식에 있을때
			if (parentN->left == removeN) {
				// 삭제 노드의 자식과 삭제 노드의 부모를 연결
				parentN->left = removeN->left;
				delete removeN;
			}
			// 삭제 노드가 부모의 오른쪽 자식에 있을때
			else {
				// 삭제 노드의 자식과 삭제 노드의 부모를 연결
				parentN->right = removeN->left;
				delete removeN;
			}
		}
		// 자식이 오른쪽에 있을때
		else {
			// 삭제 노드가 부모의 왼쪽 자식에 있을때
			if (parentN->left == removeN) {
				// 삭제 노드의 자식과 삭제 노드의 부모를 연결
				parentN->left = removeN->right;
				delete removeN;
			}
			// 삭제 노드가 부모의 오른쪽 자식에 있을때
			else {
				// 삭제 노드의 자식과 삭제 노드의 부모를 연결
				parentN->right = removeN->right;
				delete removeN;
			}
		}
	}

	// 3. 삭제할 노드가 자식 2개를 가질때.
	else {
		// 오른쪽 가장 작은값으로 대체
		BTreeNode* replaceN = removeN->right;
		BTreeNode* replaceParentN = nullptr;

		// 오른쪽 가장 큰값과 그 값의 부모를 찾기.
		while (replaceN->left != nullptr) {
			replaceParentN = replaceN;
			replaceN = replaceN->left;
		}


		// 대체노드와 삭제노드의 나머지 노드를 연결 (항상 왼쪽)
		replaceN->left = removeN->left;

		// 삭제 부모노드가 따로 없을때
		if (replaceParentN == nullptr) {

			// 루트 노드를 대체할때
			if (parentN == nullptr) {
				delete removeN;
				// root 재설정
				root = replaceN;
				return;
			}

			// 삭제 노드가 삭제 부모 노드의 왼쪽에 있을때
			if (parentN->left == removeN) {
				// 부모노드와 대체노드를 연결
				parentN->left = replaceN;
				// 삭제 노드 해제
				delete removeN;
			}
			// 삭제 노드가 삭제 부모 노드의 오른쪽에 있을때
			else {
				// 부모노드와 대체노드를 연결
				parentN->right = replaceN;
				// 삭제 노드 해제
				delete removeN;
			}
		}
		// 삭제 부모 노드가 따로 존재할때
		else {
			// 대체노드의 부모노드 연결 해제 (항상 왼쪽임)
			replaceParentN->left = nullptr;
			// 대체노드의 오른쪽도 연결
			replaceN->right = removeN->right;

			if (parentN == nullptr) {
				delete removeN;
				// root 재설정
				root = replaceN;
				return;
			}

			// 삭제 노드가 삭제 부모 노드의 왼쪽에 있을때
			if (parentN->left == removeN) {
				// 부모노드와 대체노드를 연결
				parentN->left = replaceN;
				// 삭제 노드 해제
				delete removeN;
			}
			// 삭제 노드가 삭제 부모 노드의 오른쪽에 있을때
			else {
				// 부모노드와 대체노드를 연결
				parentN->right = replaceN;
				// 삭제 노드 해제
				delete removeN;
			}
		}
	}
}

bool BinarySearchTree::Search(const int & data)
{
	// 만약 빈 트리라면
	if (IsEmpty()) return false;

	BTreeNode* parent = root;

	// 자신이 null이 되기 전까지
	while (parent != nullptr) {
		if (parent->data == data) return true;
		// 작은건 왼쪽
		else if (parent->data > data) {
			parent = parent->left;
		}
		// 큰건 오른쪽
		else {
			parent = parent->right;
		}
	}
	return false;
}