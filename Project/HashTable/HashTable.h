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
	
	// 선형 조사법을 이용한 삽입
	void AddLinearProb(const std::string& key, const std::string& value);
	// 탐색
	void SearchLinearProb(const std::string& key);
};

