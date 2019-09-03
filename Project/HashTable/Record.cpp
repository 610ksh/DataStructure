#include "Record.h"



Record::Record(const std::string& k="", const std::string& v="")
{
	SetRecord(k, v);
}

void Record::SetRecord(const std::string& k, const std::string& v)
{
	key = k;
	value = v;
}

void Record::Reset()
{
	key = "";
	value = "";
}

bool Record::IsEmpty()
{
	return key[0] == '\0';
}

bool Record::IsEqual(const std::string& k)
{
	return k == key;
}

void Record::Print()
{
	printf("%20s = %s\n", key, value);
}
