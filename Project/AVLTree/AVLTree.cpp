#include "AVLTree.h"


// 현재 노드의 BF를 구한다
int AVLTree::GetBalanceFactor(BTreeNode * node)
{
	// 현재 노드가 null이라면
	if (node == nullptr) return 0;

	// 현재 노드의 BF를 반환한다.
	return GetHeight(node->left) - GetHeight(node->right);
}

void AVLTree::RotateLL(BTreeNode* node)
{
	BTreeNode* pNode = GetParentNode(node);
	BTreeNode* cNode = node->left; // 자식노드
	
	/* Rotate LL */
	// 0. 자식의 오른쪽 노드를 자신의 왼쪽에 연결한다.
	// 1. 자식의 오른쪽에 자신을 연결한다.
	node->left = cNode->right;
	cNode->right = node;

	// 1. 부모노드가 없는 루트노드일때
	if (pNode == nullptr) {
		// 자식이 루트노드가 됨.
		root = cNode;
	}
	// 2. 부모노드가 있을때
	else {
		// 부모의 왼쪽에 자신이 있었을때
		if (pNode->left = node) {
			pNode->left = cNode;
		}
		// 부모의 오른쪽에 자신이 있었을때
		else {
			pNode->right = cNode;
		}
	}
}

void AVLTree::RotateRR(BTreeNode* node)
{
	BTreeNode* pNode = GetParentNode(node);
	BTreeNode* cNode = node->right; // 자식노드

	/* Rotate RR */
	// 0. 자신의 right에 자식의 left 노드를 연결한다.
	// 1. 자식의 left에 자신을 연결한다.
	node->right = cNode->left;
	cNode->left = node;

	// 1. 부모노드가 없는 루트노드일때
	if (pNode == nullptr) {
		// 자식이 루트노드가 됨.
		root = cNode;
	}
	// 2. 부모노드가 있을때
	else {
		// 부모의 왼쪽에 자신이 있었을때
		if (pNode->left = node) {
			pNode->left = cNode;
		}
		// 부모의 오른쪽에 자신이 있었을때
		else {
			pNode->right = cNode;
		}
	}
}

void AVLTree::RotateLR(BTreeNode * node)
{
	BTreeNode* cNode = node->left;
	// 1.자식을 기준으로 강제 RR을 시킨다.
	RotateRR(cNode);
	// 2.현재 노드를 기준으로 LL을 시킨다.
	RotateLL(node);
}

void AVLTree::RotateRL(BTreeNode * node)
{
	BTreeNode* cNode = node->right;
	// 1.자식을 기준으로 강제 LL을 시킨다.
	RotateLL(cNode);
	// 2.현재 노드를 기준으로 RR을 시킨다.
	RotateRR(node);
}

void AVLTree::Rebalance()
{
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