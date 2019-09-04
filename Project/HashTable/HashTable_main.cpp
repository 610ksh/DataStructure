#include "HashTable.h"
#include "HashChainMap.h"

/*
	HashTable
	September 3, 2019
*/

int main()
{
	HashTable hash;
	hash.AddLinearProb("do", "�ݺ�"); // 3
	hash.AddLinearProb("for", "�ݺ�"); // 2
	hash.AddLinearProb("if", "�б�"); // 12
	hash.AddLinearProb("case", "�б�"); // 9
	hash.AddLinearProb("else", "�б�"); // 9
	hash.AddLinearProb("return", "��ȯ"); // 9
	hash.AddLinearProb("function", "�Լ�"); // 12
	hash.Print();
	std::cout << std::endl;
	hash.SearchLinearProb("return");
	hash.SearchLinearProb("class");
	hash.SearchLinearProb("function");

	HashChainMap hashChainMap;

	std::cout << "Hello Hash Table" << std::endl;
	return 0;
}