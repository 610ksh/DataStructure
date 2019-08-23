#pragma once
#include "BinaryTree3.h"

class BinarySearchTree : public BinaryTree
{
public:
	bool Search(const int& data);
	void Insert(const int& data);
	void Remove(const int& data);
};

