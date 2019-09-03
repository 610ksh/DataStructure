#pragma once
#include <iostream>

/*
	http://blog.daum.net/_blog/BlogTypeView.do?blogid=0rsX2&articleno=11&_bloghome_menu=recenttext
*/
inline int Transform(const std::string& key)
{
	int number = 0;
	const char* cstr = key.c_str();
	while (*cstr)
		number += (*cstr++);
	return number;
}

inline int HashFunction(const std::string& key)
{
	const char* cstr = key.c_str();
	return Transform(key) % 13;
}