#include "BinaryTree.h"


BinaryTree::BinaryTree()
{
	root = nullptr;
}

BTreeNode* BinaryTree::MakeTreeNode(const int& data)
{
	BTreeNode* newNode = new BTreeNode;
	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;

	return newNode;
}

void BinaryTree::SetRootNode(BTreeNode* const node)
{
	if (root != nullptr) {
		std::cout << "�̹� root ��尡 �����Ǿ��ֽ��ϴ�" << std::endl;
		return;
	}
	std::cout << "root ��带 �����մϴ�" << std::endl;
	root = node;
}

BTreeNode* BinaryTree::GetRootNode()
{
	return root;
}

void BinaryTree::MakeLeftSubTree(BTreeNode *parent, BTreeNode *left)
{
	if (parent->left != nullptr) {
		std::cout << "�̹� ����Ǿ� �ִ� left ��尡 �ֽ��ϴ�." << std::endl;
		return;
	}
	parent->left = left;
}

void BinaryTree::MakeRightSubTree(BTreeNode *parent, BTreeNode *right)
{
	if (parent->right != nullptr) {
		std::cout << "�̹� ����Ǿ� �ִ� right ��尡 �ֽ��ϴ�" << std::endl;
		return;
	}
	parent->right = right;
}

bool BinaryTree::IsEmpty()
{
	// it's empty if not exist root
	if (root = nullptr)
		return true;
	return false;
}

// ��ü ��� ����
int BinaryTree::GetCount(BTreeNode* node)
{
	if (node == nullptr) return 0;
	return 1 + GetCount(node->left) + GetCount(node->right);
}

// �ܸ� ��� ����
int BinaryTree::GetLeafCount(BTreeNode * node)
{
	if (node == nullptr) return 0;
	if (node->left == nullptr&&node->right == nullptr) {
		return 1;
	}
	return GetLeafCount(node->left) + GetLeafCount(node->right);
}

// Ʈ�� ��ü�� ����
int BinaryTree::GetHeight(BTreeNode * node)
{
	// Ʈ���� ������
	if (node == nullptr) return 0;

	// �ڽ� ��尡 ������
	if (node->left == nullptr && node->right == nullptr) {
		return 0;
	}
	// �ڽ� ��尡 �ϳ��� �ִٸ�
	if (node->right == nullptr) {
		return GetHeight(node->left) + 1;
	}
	if (node->left == nullptr) {
		return GetHeight(node->right) + 1;
	}

	// �ڽ� ��尡 �Ѵ� ������
	return std::max(GetHeight(node->left) + 1, GetHeight(node->right) + 1);
}

// ���� ��ȸ
void BinaryTree::Preorder()
{
	std::cout << "Preorder ����" << std::endl;
	std::cout << "Preorder : ";
	Preorder(root);
	std::cout << "\nPreorder ��" << std::endl;
}

void BinaryTree::Preorder(BTreeNode * node)
{
	// ���� ��尡 �����Ѵٸ�
	if (node != nullptr) {
		printf("[%d] ", node->data);
		Preorder(node->left);
		Preorder(node->right);
	}
}

// ���� ��ȸ
void BinaryTree::Inorder()
{
	std::cout << "Inorder ����" << std::endl;
	std::cout << "Inorder : ";
	Inorder(root);
	std::cout << "\nInorder ��" << std::endl;
}

void BinaryTree::Inorder(BTreeNode * node)
{
	if (node != nullptr) {
		Inorder(node->left);
		printf("[%d] ", node->data);
		Inorder(node->right);
	}
}

// ���� ��ȸ
void BinaryTree::Postorder()
{
	std::cout << "Postorder ����" << std::endl;
	std::cout << "Postorder : ";
	Postorder(root);
	std::cout << "\nPostorder ��" << std::endl;
}

void BinaryTree::Postorder(BTreeNode * node)
{
	// ���� ��尡 �����Ѵٸ�
	if (node != nullptr) {
		Postorder(node->left);
		Postorder(node->right);
		printf("[%d] ", node->data);
	}
}

// Level ��ȸ
void BinaryTree::Levelorder()
{
	std::cout << "Levelorder ����" << std::endl;
	std::cout << "Levelorder : ";
	Levelorder(this->root);
	std::cout << "\nLevelorder ��" << std::endl;
}

void BinaryTree::Levelorder(BTreeNode * node)
{
	// ���� ��尡 �����Ѵٸ�
	if (node != nullptr) {
		// queue ����
		std::queue<BTreeNode*> queue;
		// ���� rootNode �ֱ�
		queue.push(node);

		// queue�� ��������
		while (!queue.empty()) {
			// ť �� �տ� �ִ°� �б�
			printf("[%d] ", queue.front()->data);
			// ť �� �տ� �ִ°��� �ڽĵ� ť�� �ֱ�
			if (queue.front()->left != nullptr)
				queue.push(queue.front()->left);
			if (queue.front()->right != nullptr)
				queue.push(queue.front()->right);
			queue.pop();
		}
	}
}
