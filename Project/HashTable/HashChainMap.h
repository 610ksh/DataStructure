#pragma once
#include "HashFunctions.h"
#include <iostream>
#include <list>

#define TABLE_SIZE 13

class HashChainMap
{
private:
	std::list<std::string> table[TABLE_SIZE];
	
public:
	HashChainMap();

	void Print();
	void AddRecord(const std::string& key, const std::string& value);
	void SearchRecord(const std::string& key);
};

