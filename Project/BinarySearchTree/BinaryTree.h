#pragma once
#include <iostream>
#include <queue>

/*
	Binary Tree's ADT
	
	// Create Node (��� ����)
	1. BTreeNode* MakeTreeNode(const int& data);
	
	// Root setter, getter
	2. void SetRootNode(BTreeNode* const node);
	3. BTreeNode* GetRootNode();
	
	// Linking Node (��� ����)
	4. void MakeLeftSubTree(BTreeNode* parent, BTreeNode* left);
	5. void MakeRightSubTree(BTreeNode* parent, BTreeNode* right);
	
	// Traversal (��ȸ)
	6. void Preorder(BTreeNode* parent);
	7. void Inorder(BTreeNode* parent);
	8. void Postorder(BTreeNode* parent);
	// �� Levelorder�� queue�� ����Ѵ� std::queue
	9. void Levelorder(BTreeNode* node);

	// etc.
	10. bool IsEmpty();
	11. int GetCount(BTreeNode* node);
	12. int GetLeafCount(BTreeNode* node);
	13. int GetHeight(BTreeNode* node);

	�� �޸� ������ �������� �ʾҴ�.
*/

struct BTreeNode {
	int data;
	BTreeNode* left;
	BTreeNode* right;
};

class BinaryTree
{
protected:
	BTreeNode* root;

private:
	// link left subtree
	void MakeLeftSubTree(BTreeNode* parent, BTreeNode* left);
	void MakeRightSubTree(BTreeNode* parent, BTreeNode* right);

public:
	BinaryTree();

	// create Node
	BTreeNode* MakeTreeNode(const int& data);

	// setter getter RootNode
	void SetRootNode(BTreeNode* const node);
	BTreeNode* GetRootNode();

	// traversal
	void Preorder();
	void Inorder();
	void Postorder();
	void Levelorder();

	// etc.
	bool IsEmpty();
	int GetCount(BTreeNode* node);
	int GetLeafCount(BTreeNode* node);
	int GetHeight(BTreeNode* node);

protected:
	// �ܺο��� ��� ���ϰ� ����.
	void Preorder(BTreeNode* node);
	void Inorder(BTreeNode* node);
	void Postorder(BTreeNode* node);
	void Levelorder(BTreeNode* node);
};