#include "BinaryTree.h"

/*
	기본 이진트리

	August 22, 2019
*/
int main()
{
	BinaryTree tree;

	// Create TreeNode
	BTreeNode* a = tree.MakeTreeNode(1);
	BTreeNode* b = tree.MakeTreeNode(2);
	BTreeNode* c = tree.MakeTreeNode(3);
	BTreeNode* d = tree.MakeTreeNode(4);
	BTreeNode* e = tree.MakeTreeNode(5);
	BTreeNode* f = tree.MakeTreeNode(6);
	BTreeNode* g = tree.MakeTreeNode(7);

	// Setting root
	tree.SetRootNode(a);

	// Linking tree
	tree.MakeLeftSubTree(a, b);
	tree.MakeRightSubTree(a, c);
	tree.MakeLeftSubTree(b, d);
	tree.MakeRightSubTree(b, e);
	tree.MakeLeftSubTree(c, f);
	tree.MakeRightSubTree(c, g);
	
	// error check
	tree.MakeLeftSubTree(a, g);
	std::cout << std::endl;
	
	// Traversal
	tree.Preorder();
	tree.Inorder();
	tree.Postorder();
	tree.Levelorder();
	std::cout << std::endl;
	
	std::cout << "All of node are : " << tree.GetCount(tree.GetRootNode()) << std::endl;
	std::cout << "All of Leafnode are : " << tree.GetLeafCount(tree.GetRootNode()) << std::endl;
	std::cout << "Height of tree is : " << tree.GetHeight(tree.GetRootNode()) << std::endl;

	return 0;
}