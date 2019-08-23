#pragma once
#include "BinarySearchTree3.h"

class AVLTree : public BinarySearchTree
{
public:
	// Balance Factor 구하는 함수.
	int GetBalanceFactor(BTreeNode* node);

	// LL 회전, RR 회전
	void RotateLL(BTreeNode* node);
	void RotateRR(BTreeNode* node);
	void RotateLR(BTreeNode* node);
	void RotateRL(BTreeNode* node);

	void Rebalance();

	// 현재 노드의 부모 노드를 찾는 함수
	BTreeNode* GetParentNode(BTreeNode* node);
};

