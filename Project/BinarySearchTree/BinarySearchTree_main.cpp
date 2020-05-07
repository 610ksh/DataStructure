#include "BinarySearchTree.h"

/*
	BST = Binary Search Tree.

	삽입, 삭제, 검색 모두다 O(n). 편향될 수 있기 때문.
	개선한 트리 = AVL (Balanced BST)


	August 23, 2019

	Copyright 2019. SungHoon Kim. All rights reserved.
*/

int main()
{
	BinarySearchTree tree;
	tree.Insert(4);
	tree.Insert(2);
	tree.Insert(6);
	tree.Insert(1);
	tree.Insert(3);
	tree.Insert(5);
	tree.Insert(7);
	tree.Insert(8);

	tree.Insert(1);

	std::cout << "Search 결과 : " << tree.Search(1) << std::endl;
	std::cout << "Search 결과 : " << tree.Search(9) << std::endl;
	std::cout << "Search 결과 : " << tree.Search(5) << std::endl;
	
	tree.Remove(4);

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