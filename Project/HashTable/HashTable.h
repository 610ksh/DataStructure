#pragma once
#include "Record.h"
#include "HashFunctions.h"

#define TABLE_SIZE 13

class HashTable
{
private:
	Record table[TABLE_SIZE]; // table size is 13;

public:
	HashTable();

	void Reset();
	void Print();
	
	// 선형 조사법을 이용한 삽입
	void AddLinearProb(const std::string& key, const std::string& value);
	// 탐색
	Record* SearchLinearProb(const std::string& key);
};