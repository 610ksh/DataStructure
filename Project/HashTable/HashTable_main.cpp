#include "HashTable.h"
#include "HashChainMap.h"

/*
	HashTable
	September 3, 2019
*/

int main()
{
	std::cout << "Start Hash table with linear probing" << std::endl;
	
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

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "Start Hash map with chaining" << std::endl;

	HashChainMap hashChainMap;
	hashChainMap.AddRecord("do", "�ݺ�"); // 3
	hashChainMap.AddRecord("for", "�ݺ�"); // 2
	hashChainMap.AddRecord("if", "�б�"); // 12
	hashChainMap.AddRecord("case", "�б�"); // 9
	hashChainMap.AddRecord("else", "�б�"); // 9
	hashChainMap.AddRecord("return", "��ȯ"); // 9
	hashChainMap.AddRecord("function", "�Լ�"); // 12

	hashChainMap.Print();
	std::cout << std::endl;
	hashChainMap.SearchRecord("return");
	hashChainMap.SearchRecord("class");
	hashChainMap.SearchRecord("function");

	return 0;
}