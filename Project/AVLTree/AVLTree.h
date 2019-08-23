#pragma once
#include "BinarySearchTree3.h"

class AVLTree : public BinarySearchTree
{
public:
	// Balance Factor ���ϴ� �Լ�.
	int GetBalanceFactor(BTreeNode* node);

	// LL ȸ��, RR ȸ��
	void RotateLL(BTreeNode* node);
	void RotateRR(BTreeNode* node);
	void RotateLR(BTreeNode* node);
	void RotateRL(BTreeNode* node);

	void Rebalance();

	// ���� ����� �θ� ��带 ã�� �Լ�
	BTreeNode* GetParentNode(BTreeNode* node);
};

