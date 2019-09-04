#include "HashChainMap.h"



HashChainMap::HashChainMap()
{

}

void HashChainMap::Print()
{
	for (auto i : table) {
		for (auto i2 : i) {
			std::cout << i2.data()<< " ";
		}
		std::cout << std::endl;
	}
}

void HashChainMap::AddRecord(const std::string& key, const std::string& value)
{
	// hash°ª »ý¼º
	int hashValue = HashFunction(key);

}

void HashChainMap::SearchRecord(const std::string& key)
{
}
