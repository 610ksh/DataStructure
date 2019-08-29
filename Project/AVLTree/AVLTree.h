#pragma once
#include "BinarySearchTree3.h"

class AVLTree : public BinarySearchTree
{
public:
	// Balance Factor 구하는 함수.
	int GetBalanceFactor(BTreeNode* node);

	void Insert(const int& data) override;

	// LL 회전, RR 회전
	BTreeNode* RotateLL(BTreeNode* node);
	BTreeNode* RotateRR(BTreeNode* node);
	BTreeNode* RotateLR(BTreeNode* node);
	BTreeNode* RotateRL(BTreeNode* node);

	BTreeNode* Rebalance(BTreeNode* node);

	// 현재 노드의 부모 노드를 찾는 함수
	BTreeNode* GetParentNode(BTreeNode* node);

private:
	BTreeNode* Insert(BTreeNode* parent, const int& data);
};

