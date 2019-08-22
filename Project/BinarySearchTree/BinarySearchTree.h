#pragma once
#include "BinaryTree.h"

class BinarySearchTree : public BinaryTree
{
public:
	bool Search(const int& data);
	void Insert(const int& data);
	void Remove(const int& data);
};

