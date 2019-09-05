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
	hash.AddLinearProb("do", "반복"); // 3
	hash.AddLinearProb("for", "반복"); // 2
	hash.AddLinearProb("if", "분기"); // 12
	hash.AddLinearProb("case", "분기"); // 9
	hash.AddLinearProb("else", "분기"); // 9
	hash.AddLinearProb("return", "반환"); // 9
	hash.AddLinearProb("function", "함수"); // 12
	hash.Print();
	std::cout << std::endl;
	hash.SearchLinearProb("return");
	hash.SearchLinearProb("class");
	hash.SearchLinearProb("function");

	std::cout << std::endl << std::endl << std::endl;
	std::cout << "Start Hash map with chaining" << std::endl;

	HashChainMap hashChainMap;
	hashChainMap.AddRecord("do", "반복"); // 3
	hashChainMap.AddRecord("for", "반복"); // 2
	hashChainMap.AddRecord("if", "분기"); // 12
	hashChainMap.AddRecord("case", "분기"); // 9
	hashChainMap.AddRecord("else", "분기"); // 9
	hashChainMap.AddRecord("return", "반환"); // 9
	hashChainMap.AddRecord("function", "함수"); // 12

	hashChainMap.Print();
	std::cout << std::endl;
	hashChainMap.SearchRecord("return");
	hashChainMap.SearchRecord("class");
	hashChainMap.SearchRecord("function");

	return 0;
}