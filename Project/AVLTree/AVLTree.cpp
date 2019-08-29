#include "AVLTree.h"


// 현재 노드의 BF를 구한다
int AVLTree::GetBalanceFactor(BTreeNode * node)
{
	// 현재 노드가 null이라면
	if (node == nullptr) return 0;

	int left = GetHeight(node->left);
	int right = GetHeight(node->right);

	std::cout << "BF : " << left - right << std::endl;
	return left - right;
}

void AVLTree::Insert(const int & data)
{
	std::cout << "삽입 시작" << std::endl;
	std::cout << data << std::endl;
	Insert(root, data);
	std::cout << "삽입 끝" << std::endl << std::endl;
}

BTreeNode* AVLTree::Insert(BTreeNode* parent, const int& data)
{
	if (root == nullptr) {
		SetRootNode(MakeTreeNode(data));
	}
	// 빈 트리라면
	if (parent == nullptr) {
		parent = MakeTreeNode(data);
	}
	// 왼쪽
	else if (parent->data > data) {
		parent->left = Insert(parent->left, data);
		parent = Rebalance(parent);
	}
	// 오른쪽
	else if (parent->data < data) {
		parent->right = Insert(parent->right, data);
		parent = Rebalance(parent);
	}
	else {
		std::cout << "이미 키가 존재합니다" << std::endl;
		return parent;
	}
	return parent;
}

BTreeNode* AVLTree::RotateLL(BTreeNode* node)
{
	BTreeNode* pNode = GetParentNode(node);
	BTreeNode* cNode = node->left; // 자식노드

	/* Rotate LL */


	// 1. 부모노드가 없는 루트노드일때
	if (pNode == nullptr) {
		// 자식이 루트노드가 됨.
		root = cNode;
		node->left = cNode->right;
		cNode->right = node;
	}
	// 2. 부모노드가 있을때
	else {
		// 부모의 왼쪽에 자신이 있었을때
		if (pNode->left == node) {
			// 0. 자식의 오른쪽 노드를 자신의 왼쪽에 연결한다.
			// 1. 자식의 오른쪽에 자신을 연결한다.
			node->left = cNode->right;
			cNode->right = node;
			pNode->left = cNode;
		}
		// 부모의 오른쪽에 자신이 있었을때
		else {
			// 0. 자식의 오른쪽 노드를 자신의 왼쪽에 연결한다.
			// 1. 자식의 오른쪽에 자신을 연결한다.
			node->left = cNode->right;
			cNode->right = node;
			pNode->right = cNode;
		}
	}
	return cNode;
}

BTreeNode* AVLTree::RotateRR(BTreeNode* node)
{
	BTreeNode* pNode = GetParentNode(node);
	BTreeNode* cNode = node->right; // 자식노드

	/* Rotate RR */
	// 1. 부모노드가 없는 루트노드일때
	if (pNode == nullptr) {
		// 자식이 루트노드가 됨.
		root = cNode;
		node->right = cNode->left;
		cNode->left = node;
	}
	// 2. 부모노드가 있을때
	else {
		// 부모의 왼쪽에 자신이 있었을때
		if (pNode->left == node) {
			// 0. 자신의 right에 자식의 left 노드를 연결한다.
			// 1. 자식의 left에 자신을 연결한다.
			node->right = cNode->left;
			cNode->left = node;
			pNode->left = cNode;
		}
		// 부모의 오른쪽에 자신이 있었을때
		else {
			// 0. 자신의 right에 자식의 left 노드를 연결한다.
			// 1. 자식의 left에 자신을 연결한다.
			node->right = cNode->left;
			cNode->left = node;
			pNode->right = cNode;
		}
	}
	return cNode;
}

BTreeNode* AVLTree::RotateLR(BTreeNode * node)
{
	BTreeNode* cNode = node->left;
	// 1.자식을 기준으로 강제 RR을 시킨다.
	RotateRR(cNode);
	// 2.현재 노드를 기준으로 LL을 시킨다.
	return RotateLL(node);
}

BTreeNode* AVLTree::RotateRL(BTreeNode * node)
{
	BTreeNode* cNode = node->right;
	// 1.자식을 기준으로 강제 LL을 시킨다.
	RotateLL(cNode);
	// 2.현재 노드를 기준으로 RR을 시킨다.
	return RotateRR(node);
}

BTreeNode* AVLTree::Rebalance(BTreeNode* node)
{
	/*
		삽입이 일어남
		1. 전체 BF를 계산.
		2. 아래서부터 가장 가까운 BF가 2가 된 지점을 체크.
		3. 상황에 따라 RR RL LL LR
	*/
	std::cout << "TEST : " << node->data << std::endl;
	int bf = GetBalanceFactor(node);
	// 왼쪽 불균형
	if (bf > 1) {
		// LL
		if (GetBalanceFactor(node->left) > 0) {
			std::cout << "★ LL" << std::endl;
			return RotateLL(node);
		}
		// LR
		else {
			std::cout << "★ LR" << std::endl;
			return RotateLR(node);
		}
	}
	// 오른쪽 불균형
	else if (bf < -1) {
		// RL
		if (GetBalanceFactor(node->right) > 0) {
			std::cout << "★ RL" << std::endl;
			return RotateRL(node);
		}
		// RR
		else {
			std::cout << "★ RR" << std::endl;
			return RotateRR(node);
		}
	}
	return node;
}

// 직전 부모 노드 반환 (탐색)
BTreeNode * AVLTree::GetParentNode(BTreeNode * node)
{
	BTreeNode* pNode = nullptr; // 부모노드
	// root부터 시작
	BTreeNode* tNode = root;
	while (tNode->data != node->data) {
		// 이전 노드 기록(부모)
		pNode = tNode;
		if (tNode->data > node->data)
			tNode = tNode->left;
		else
			tNode = tNode->right;
	}
	// 1. nullptr이면 부모가 없는 노드
	// 2. 그외는 모두 부모 노드를 반환
	return pNode;
}