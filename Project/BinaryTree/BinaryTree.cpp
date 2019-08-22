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
		std::cout << "이미 root 노드가 설정되어있습니다" << std::endl;
		return;
	}
	std::cout << "root 노드를 설정합니다" << std::endl;
	root = node;
}

BTreeNode* BinaryTree::GetRootNode()
{
	return root;
}

void BinaryTree::MakeLeftSubTree(BTreeNode *parent, BTreeNode *left)
{
	if (parent->left != nullptr) {
		std::cout << "이미 연결되어 있는 left 노드가 있습니다." << std::endl;
		return;
	}
	parent->left = left;
}

void BinaryTree::MakeRightSubTree(BTreeNode *parent, BTreeNode *right)
{
	if (parent->right != nullptr) {
		std::cout << "이미 연결되어 있는 right 노드가 있습니다" << std::endl;
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

// 전체 노드 개수
int BinaryTree::GetCount(BTreeNode* node)
{
	if (node == nullptr) return 0;
	return 1 + GetCount(node->left) + GetCount(node->right);
}

// 단말 노드 개수
int BinaryTree::GetLeafCount(BTreeNode * node)
{
	if (node == nullptr) return 0;
	if (node->left == nullptr&&node->right == nullptr) {
		return 1;
	}
	return GetLeafCount(node->left) + GetLeafCount(node->right);
}

// 트리 전체의 높이
int BinaryTree::GetHeight(BTreeNode * node)
{
	// 트리가 없을때
	if (node == nullptr) return 0;

	// 자식 노드가 없을때
	if (node->left == nullptr && node->right == nullptr) {
		return 0;
	}
	// 자식 노드가 하나만 있다면
	if (node->right == nullptr) {
		return GetHeight(node->left) + 1;
	}
	if (node->left == nullptr) {
		return GetHeight(node->right) + 1;
	}

	// 자식 노드가 둘다 있을때
	return std::max(GetHeight(node->left) + 1, GetHeight(node->right) + 1);
}

// 전위 순회
void BinaryTree::Preorder()
{
	std::cout << "Preorder 시작" << std::endl;
	std::cout << "Preorder : ";
	Preorder(root);
	std::cout << "\nPreorder 끝" << std::endl;
}

void BinaryTree::Preorder(BTreeNode * node)
{
	// 현재 노드가 존재한다면
	if (node != nullptr) {
		printf("[%d] ", node->data);
		Preorder(node->left);
		Preorder(node->right);
	}
}

// 중위 순회
void BinaryTree::Inorder()
{
	std::cout << "Inorder 시작" << std::endl;
	std::cout << "Inorder : ";
	Inorder(root);
	std::cout << "\nInorder 끝" << std::endl;
}

void BinaryTree::Inorder(BTreeNode * node)
{
	if (node != nullptr) {
		Inorder(node->left);
		printf("[%d] ", node->data);
		Inorder(node->right);
	}
}

// 후위 순회
void BinaryTree::Postorder()
{
	std::cout << "Postorder 시작" << std::endl;
	std::cout << "Postorder : ";
	Postorder(root);
	std::cout << "\nPostorder 끝" << std::endl;
}

void BinaryTree::Postorder(BTreeNode * node)
{
	// 현재 노드가 존재한다면
	if (node != nullptr) {
		Postorder(node->left);
		Postorder(node->right);
		printf("[%d] ", node->data);
	}
}

// Level 순회
void BinaryTree::Levelorder()
{
	std::cout << "Levelorder 시작" << std::endl;
	std::cout << "Levelorder : ";
	Levelorder(this->root);
	std::cout << "\nLevelorder 끝" << std::endl;
}

void BinaryTree::Levelorder(BTreeNode * node)
{
	// 현재 노드가 존재한다면
	if (node != nullptr) {
		// queue 생성
		std::queue<BTreeNode*> queue;
		// 최초 rootNode 넣기
		queue.push(node);

		// queue가 빌때까지
		while (!queue.empty()) {
			// 큐 맨 앞에 있는거 읽기
			printf("[%d] ", queue.front()->data);
			// 큐 맨 앞에 있는것의 자식들 큐에 넣기
			if (queue.front()->left != nullptr)
				queue.push(queue.front()->left);
			if (queue.front()->right != nullptr)
				queue.push(queue.front()->right);
			queue.pop();
		}
	}
}
