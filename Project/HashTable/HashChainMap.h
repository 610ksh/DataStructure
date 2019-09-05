#pragma once
#include "HashFunctions.h"
#include "Record.h"

/*
	Hash map for Chaining method
	September 5, 2019
*/

#define TABLE_SIZE 13

class Node : public Record
{
private:
	Node* link;
public:
	Node(const std::string& key, const std::string& value) : Record(key, value), link(nullptr) {}
	Node* GetLink() { return link; }
	void SetLink(const std::string& key, const std::string& value)
	{
		// create new node
		Node* newNode = new Node(key,value);
		// link to prior node
		link = newNode;
	}
}; 

class HashChainMap
{
private:
	Node* table[TABLE_SIZE];
	
public:
	// initial table
	HashChainMap();

	void Print();
	void AddRecord(const std::string& key, const std::string& value);
	Node* SearchRecord(const std::string& key);
};