#include <iostream>
#include <vector>

int main()
{
	std::cout << "Hello Data Structure"<<std::endl;

	std::vector<int> a(5);
	//a.reserve(100);
	//a.resize(10);
	std::cout << a.size() << std::endl;

	std::vector<int> b(10);
	a = b;

	return 0;
}