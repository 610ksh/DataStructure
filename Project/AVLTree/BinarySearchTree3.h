#pragma once
#include "BinaryTree3.h"

class BinarySearchTree : public BinaryTree
{
public:
	bool Search(const int& data);
	virtual void Insert(const int& data);
	void Remove(const int& data);
};

