#pragma once
#include <iostream>
#include <queue>

/*
	Binary Tree's ADT
	
	// Create Node (노드 생성)
	1. BTreeNode* MakeTreeNode(const int& data);
	
	// Root setter, getter
	2. void SetRootNode(BTreeNode* const node);
	3. BTreeNode* GetRootNode();
	
	// Linking Node (노드 연결)
	4. void MakeLeftSubTree(BTreeNode* parent, BTreeNode* left);
	5. void MakeRightSubTree(BTreeNode* parent, BTreeNode* right);
	
	// Traversal (순회)
	6. void Preorder(BTreeNode* parent);
	7. void Inorder(BTreeNode* parent);
	8. void Postorder(BTreeNode* parent);
	// ※ Levelorder는 queue를 사용한다 std::queue
	9. void Levelorder(BTreeNode* node);

	// etc.
	10. bool IsEmpty();
	11. int GetCount(BTreeNode* node);
	12. int GetLeafCount(BTreeNode* node);
	13. int GetHeight(BTreeNode* node);

	※ 메모리 해제를 구현하지 않았다.
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
	// 외부에서 사용 못하게 막음.
	void Preorder(BTreeNode* node);
	void Inorder(BTreeNode* node);
	void Postorder(BTreeNode* node);
	void Levelorder(BTreeNode* node);
};