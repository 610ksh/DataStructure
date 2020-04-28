#include <iostream>
#include <vector>

int main()
{
	std::cout << "Hello Data Structure"<<std::endl;
	
	std::vector< std::vector<int> > head{ std::vector<int>(1), };

	{
		std::vector<int> a;
		head.push_back(a);
		std::vector<int>* f = new std::vector<int>();
		head.push_back(*f);

		head.push_back(*(new std::vector<int>()));

		head[1].push_back(5);
	}
	head[0].push_back(1);
	head[1].push_back(2);

	return 0;
}