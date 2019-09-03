#pragma once
#include "Record.h"
#include "HashFunctions.h"

class HashTable
{
private:
	Record table[13]; // table size is 13;

public:
	HashTable();

	void Reset();
	void Print();
	
	// ���� ������� �̿��� ����
	void AddLinearProb(const std::string& key, const std::string& value);
	// Ž��
	void SearchLinearProb(const std::string& key);
};

