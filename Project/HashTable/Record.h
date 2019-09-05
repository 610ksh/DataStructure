#pragma once
#include <iostream>
#include <string>

class Record
{
private:
	std::string key;
	std::string value;

public:
	Record(const std::string& k = "", const std::string& v = "");

	void SetRecord(const std::string& k = "", const std::string& v = "");
	void Reset();
	bool IsEmpty();
	bool IsEqual(const std::string& k);
	void Print();
	std::string GetKey();
};