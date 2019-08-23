#include "AVLTree.h"


// ���� ����� BF�� ���Ѵ�
int AVLTree::GetBalanceFactor(BTreeNode * node)
{
	// ���� ��尡 null�̶��
	if (node == nullptr) return 0;

	// ���� ����� BF�� ��ȯ�Ѵ�.
	return GetHeight(node->left) - GetHeight(node->right);
}

void AVLTree::RotateLL(BTreeNode* node)
{
	BTreeNode* pNode = GetParentNode(node);
	BTreeNode* cNode = node->left; // �ڽĳ��
	
	/* Rotate LL */
	// 0. �ڽ��� ������ ��带 �ڽ��� ���ʿ� �����Ѵ�.
	// 1. �ڽ��� �����ʿ� �ڽ��� �����Ѵ�.
	node->left = cNode->right;
	cNode->right = node;

	// 1. �θ��尡 ���� ��Ʈ����϶�
	if (pNode == nullptr) {
		// �ڽ��� ��Ʈ��尡 ��.
		root = cNode;
	}
	// 2. �θ��尡 ������
	else {
		// �θ��� ���ʿ� �ڽ��� �־�����
		if (pNode->left = node) {
			pNode->left = cNode;
		}
		// �θ��� �����ʿ� �ڽ��� �־�����
		else {
			pNode->right = cNode;
		}
	}
}

void AVLTree::RotateRR(BTreeNode* node)
{
	BTreeNode* pNode = GetParentNode(node);
	BTreeNode* cNode = node->right; // �ڽĳ��

	/* Rotate RR */
	// 0. �ڽ��� right�� �ڽ��� left ��带 �����Ѵ�.
	// 1. �ڽ��� left�� �ڽ��� �����Ѵ�.
	node->right = cNode->left;
	cNode->left = node;

	// 1. �θ��尡 ���� ��Ʈ����϶�
	if (pNode == nullptr) {
		// �ڽ��� ��Ʈ��尡 ��.
		root = cNode;
	}
	// 2. �θ��尡 ������
	else {
		// �θ��� ���ʿ� �ڽ��� �־�����
		if (pNode->left = node) {
			pNode->left = cNode;
		}
		// �θ��� �����ʿ� �ڽ��� �־�����
		else {
			pNode->right = cNode;
		}
	}
}

void AVLTree::RotateLR(BTreeNode * node)
{
	BTreeNode* cNode = node->left;
	// 1.�ڽ��� �������� ���� RR�� ��Ų��.
	RotateRR(cNode);
	// 2.���� ��带 �������� LL�� ��Ų��.
	RotateLL(node);
}

void AVLTree::RotateRL(BTreeNode * node)
{
	BTreeNode* cNode = node->right;
	// 1.�ڽ��� �������� ���� LL�� ��Ų��.
	RotateLL(cNode);
	// 2.���� ��带 �������� RR�� ��Ų��.
	RotateRR(node);
}

void AVLTree::Rebalance()
{
}

// ���� �θ� ��� ��ȯ (Ž��)
BTreeNode * AVLTree::GetParentNode(BTreeNode * node)
{
	BTreeNode* pNode = nullptr; // �θ���
	// root���� ����
	BTreeNode* tNode = root;
	while (tNode->data != node->data) {
		// ���� ��� ���(�θ�)
		pNode = tNode;
		if (tNode->data > node->data)
			tNode = tNode->left;
		else
			tNode = tNode->right;
	}
	// 1. nullptr�̸� �θ� ���� ���
	// 2. �׿ܴ� ��� �θ� ��带 ��ȯ
	return pNode;
}