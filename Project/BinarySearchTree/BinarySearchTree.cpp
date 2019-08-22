#include "BinarySearchTree.h"


void BinarySearchTree::Insert(const int & data)
{
	BTreeNode* NewNode = new BTreeNode;
	NewNode->data = data;
	NewNode->left = nullptr;
	NewNode->right = nullptr;

	// Ʈ���� ������� ��Ʈ ���� ����
	if (IsEmpty())
		SetRootNode(NewNode);

	BTreeNode* parent = root;

	// ��� Ž�� O(logN)
	while (parent != nullptr) {
		// ���� �̹� �����Ŷ�� �ߴ�
		if (parent->data == data) return;
		// �������� ����
		else if (parent->data > data) {
			// ���� ��尡 �����Ѵٸ� �̵�
			if (parent->left != nullptr) {
				parent = parent->left;
			}
			// ���� ��尡 ����ٸ� �ű⿡ ����
			else {
				parent->left = NewNode;
				return;
			}
		}
		// ū���� ������
		else {
			// ���� ��尡 �����Ѵٸ� �̵�
			if (parent->right != nullptr)
				parent = parent->right;
			// ���� ��尡 ����ٸ� �ű⿡ ����
			else {
				parent->right = NewNode;
				return;
			}
		}
	}
}

void BinarySearchTree::Remove(const int & data)
{
	// Ʈ���� ����ٸ�
	if (IsEmpty()) return;

	// ������ ��尡 ������ ����
	if (!Search(data)) return;

	// ���� ������ ���� �θ� ��带 ã�´�.
	BTreeNode* parentN = nullptr;
	BTreeNode* removeN = root;
	// ���������� ã�´�
	while (!(removeN->data == data)) {
		// ���� ��庸�� ���ʿ� �ִٸ�
		if (removeN->data > data) {
			// �θ� ���
			parentN = removeN;
			// ���� �̵�
			removeN = removeN->left;
		}
		// ���� ��庸�� �����ʿ� �ִٸ�
		else {
			parentN = removeN;
			removeN = removeN->right;
		}
	}// ������ �� ã��

	// 1. ������ ��尡 �ܸ�����϶�
	if (removeN->left == nullptr && removeN->right == nullptr) {

		// ��Ʈ ��带 ��ü�Ҷ�
		if (parentN == nullptr) {
			delete removeN;
			root = nullptr;
			return;
		}
		// �θ��� ���ʿ� �޸��Ÿ�
		if (parentN->left == removeN) {
			parentN->left = nullptr;
			delete removeN;
		}
		else {
			parentN->right = nullptr;
			delete removeN;
		}
	}

	// 2. ������ ��尡 �ڽ� 1���� ������
	else if (removeN->left == nullptr || removeN->right == nullptr) {
		// �ڽ� ��带 ã�ƾ���.

		// ��Ʈ ��带 ��ü�Ҷ�
		if (parentN == nullptr) {
			// root �缳��
			if (root->left != nullptr)
				root = removeN->left;
			else
				root = removeN->right;
			delete removeN;
			return;
		}

		// �ڽ��� ���ʿ� ������
		if (removeN->left != nullptr) {
			// ���� ��尡 �θ��� ���� �ڽĿ� ������
			if (parentN->left == removeN) {
				// ���� ����� �ڽİ� ���� ����� �θ� ����
				parentN->left = removeN->left;
				delete removeN;
			}
			// ���� ��尡 �θ��� ������ �ڽĿ� ������
			else {
				// ���� ����� �ڽİ� ���� ����� �θ� ����
				parentN->right = removeN->left;
				delete removeN;
			}
		}
		// �ڽ��� �����ʿ� ������
		else {
			// ���� ��尡 �θ��� ���� �ڽĿ� ������
			if (parentN->left == removeN) {
				// ���� ����� �ڽİ� ���� ����� �θ� ����
				parentN->left = removeN->right;
				delete removeN;
			}
			// ���� ��尡 �θ��� ������ �ڽĿ� ������
			else {
				// ���� ����� �ڽİ� ���� ����� �θ� ����
				parentN->right = removeN->right;
				delete removeN;
			}
		}
	}

	// 3. ������ ��尡 �ڽ� 2���� ������.
	else {
		// ������ ���� ���������� ��ü
		BTreeNode* replaceN = removeN->right;
		BTreeNode* replaceParentN = nullptr;

		// ������ ���� ū���� �� ���� �θ� ã��.
		while (replaceN->left != nullptr) {
			replaceParentN = replaceN;
			replaceN = replaceN->left;
		}


		// ��ü���� ��������� ������ ��带 ���� (�׻� ����)
		replaceN->left = removeN->left;

		// ���� �θ��尡 ���� ������
		if (replaceParentN == nullptr) {

			// ��Ʈ ��带 ��ü�Ҷ�
			if (parentN == nullptr) {
				delete removeN;
				// root �缳��
				root = replaceN;
				return;
			}

			// ���� ��尡 ���� �θ� ����� ���ʿ� ������
			if (parentN->left == removeN) {
				// �θ���� ��ü��带 ����
				parentN->left = replaceN;
				// ���� ��� ����
				delete removeN;
			}
			// ���� ��尡 ���� �θ� ����� �����ʿ� ������
			else {
				// �θ���� ��ü��带 ����
				parentN->right = replaceN;
				// ���� ��� ����
				delete removeN;
			}
		}
		// ���� �θ� ��尡 ���� �����Ҷ�
		else {
			// ��ü����� �θ��� ���� ���� (�׻� ������)
			replaceParentN->left = nullptr;
			// ��ü����� �����ʵ� ����
			replaceN->right = removeN->right;

			if (parentN == nullptr) {
				delete removeN;
				// root �缳��
				root = replaceN;
				return;
			}

			// ���� ��尡 ���� �θ� ����� ���ʿ� ������
			if (parentN->left == removeN) {
				// �θ���� ��ü��带 ����
				parentN->left = replaceN;
				// ���� ��� ����
				delete removeN;
			}
			// ���� ��尡 ���� �θ� ����� �����ʿ� ������
			else {
				// �θ���� ��ü��带 ����
				parentN->right = replaceN;
				// ���� ��� ����
				delete removeN;
			}
		}
	}
}

bool BinarySearchTree::Search(const int & data)
{
	// ���� �� Ʈ�����
	if (IsEmpty()) return false;

	BTreeNode* parent = root;

	// �ڽ��� null�� �Ǳ� ������
	while (parent != nullptr) {
		if (parent->data == data) return true;
		// ������ ����
		else if (parent->data > data) {
			parent = parent->left;
		}
		// ū�� ������
		else {
			parent = parent->right;
		}
	}
	return false;
}