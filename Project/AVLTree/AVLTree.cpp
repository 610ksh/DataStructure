#include "AVLTree.h"


// ���� ����� BF�� ���Ѵ�
int AVLTree::GetBalanceFactor(BTreeNode * node)
{
	// ���� ��尡 null�̶��
	if (node == nullptr) return 0;

	int left = GetHeight(node->left);
	int right = GetHeight(node->right);

	std::cout << "BF : " << left - right << std::endl;
	return left - right;
}

void AVLTree::Insert(const int & data)
{
	std::cout << "���� ����" << std::endl;
	std::cout << data << std::endl;
	Insert(root, data);
	std::cout << "���� ��" << std::endl << std::endl;
}

BTreeNode* AVLTree::Insert(BTreeNode* parent, const int& data)
{
	if (root == nullptr) {
		SetRootNode(MakeTreeNode(data));
	}
	// �� Ʈ�����
	if (parent == nullptr) {
		parent = MakeTreeNode(data);
	}
	// ����
	else if (parent->data > data) {
		parent->left = Insert(parent->left, data);
		parent = Rebalance(parent);
	}
	// ������
	else if (parent->data < data) {
		parent->right = Insert(parent->right, data);
		parent = Rebalance(parent);
	}
	else {
		std::cout << "�̹� Ű�� �����մϴ�" << std::endl;
		return parent;
	}
	return parent;
}

BTreeNode* AVLTree::RotateLL(BTreeNode* node)
{
	BTreeNode* pNode = GetParentNode(node);
	BTreeNode* cNode = node->left; // �ڽĳ��

	/* Rotate LL */


	// 1. �θ��尡 ���� ��Ʈ����϶�
	if (pNode == nullptr) {
		// �ڽ��� ��Ʈ��尡 ��.
		root = cNode;
		node->left = cNode->right;
		cNode->right = node;
	}
	// 2. �θ��尡 ������
	else {
		// �θ��� ���ʿ� �ڽ��� �־�����
		if (pNode->left == node) {
			// 0. �ڽ��� ������ ��带 �ڽ��� ���ʿ� �����Ѵ�.
			// 1. �ڽ��� �����ʿ� �ڽ��� �����Ѵ�.
			node->left = cNode->right;
			cNode->right = node;
			pNode->left = cNode;
		}
		// �θ��� �����ʿ� �ڽ��� �־�����
		else {
			// 0. �ڽ��� ������ ��带 �ڽ��� ���ʿ� �����Ѵ�.
			// 1. �ڽ��� �����ʿ� �ڽ��� �����Ѵ�.
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
	BTreeNode* cNode = node->right; // �ڽĳ��

	/* Rotate RR */
	// 1. �θ��尡 ���� ��Ʈ����϶�
	if (pNode == nullptr) {
		// �ڽ��� ��Ʈ��尡 ��.
		root = cNode;
		node->right = cNode->left;
		cNode->left = node;
	}
	// 2. �θ��尡 ������
	else {
		// �θ��� ���ʿ� �ڽ��� �־�����
		if (pNode->left == node) {
			// 0. �ڽ��� right�� �ڽ��� left ��带 �����Ѵ�.
			// 1. �ڽ��� left�� �ڽ��� �����Ѵ�.
			node->right = cNode->left;
			cNode->left = node;
			pNode->left = cNode;
		}
		// �θ��� �����ʿ� �ڽ��� �־�����
		else {
			// 0. �ڽ��� right�� �ڽ��� left ��带 �����Ѵ�.
			// 1. �ڽ��� left�� �ڽ��� �����Ѵ�.
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
	// 1.�ڽ��� �������� ���� RR�� ��Ų��.
	RotateRR(cNode);
	// 2.���� ��带 �������� LL�� ��Ų��.
	return RotateLL(node);
}

BTreeNode* AVLTree::RotateRL(BTreeNode * node)
{
	BTreeNode* cNode = node->right;
	// 1.�ڽ��� �������� ���� LL�� ��Ų��.
	RotateLL(cNode);
	// 2.���� ��带 �������� RR�� ��Ų��.
	return RotateRR(node);
}

BTreeNode* AVLTree::Rebalance(BTreeNode* node)
{
	/*
		������ �Ͼ
		1. ��ü BF�� ���.
		2. �Ʒ������� ���� ����� BF�� 2�� �� ������ üũ.
		3. ��Ȳ�� ���� RR RL LL LR
	*/
	std::cout << "TEST : " << node->data << std::endl;
	int bf = GetBalanceFactor(node);
	// ���� �ұ���
	if (bf > 1) {
		// LL
		if (GetBalanceFactor(node->left) > 0) {
			std::cout << "�� LL" << std::endl;
			return RotateLL(node);
		}
		// LR
		else {
			std::cout << "�� LR" << std::endl;
			return RotateLR(node);
		}
	}
	// ������ �ұ���
	else if (bf < -1) {
		// RL
		if (GetBalanceFactor(node->right) > 0) {
			std::cout << "�� RL" << std::endl;
			return RotateRL(node);
		}
		// RR
		else {
			std::cout << "�� RR" << std::endl;
			return RotateRR(node);
		}
	}
	return node;
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