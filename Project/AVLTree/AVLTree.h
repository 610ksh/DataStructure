#pragma once
#include "BinarySearchTree3.h"

class AVLTree : public BinarySearchTree
{
public:
	// Balance Factor ���ϴ� �Լ�.
	int GetBalanceFactor(BTreeNode* node);

	void Insert(const int& data) override;

	// LL ȸ��, RR ȸ��
	BTreeNode* RotateLL(BTreeNode* node);
	BTreeNode* RotateRR(BTreeNode* node);
	BTreeNode* RotateLR(BTreeNode* node);
	BTreeNode* RotateRL(BTreeNode* node);

	BTreeNode* Rebalance(BTreeNode* node);

	// ���� ����� �θ� ��带 ã�� �Լ�
	BTreeNode* GetParentNode(BTreeNode* node);

private:
	BTreeNode* Insert(BTreeNode* parent, const int& data);
};

