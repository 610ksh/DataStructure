#include "HashTable.h"
#include "HashChainMap.h"

/*
	HashTable
	September 3, 2019
*/

int main()
{
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

	HashChainMap hashChainMap;

	std::cout << "Hello Hash Table" << std::endl;
	return 0;
}