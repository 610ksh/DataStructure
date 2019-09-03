#include "HashTable.h"

HashTable::HashTable()
{
	Reset();
}

void HashTable::Reset()
{
	for (auto i : table)
		i.Reset();
}

void HashTable::Print()
{
	for (int i = 0; i < 10;++i) {
		printf("[%2d] ", i);
		table[i].Print();
	}
}

void HashTable::AddLinearProb(const std::string & key, const std::string & value)
{
	int i, hashValue;
	hashValue = i = HashFunction(key);
}

void HashTable::SearchLinearProb(const std::string & key)
{
}
