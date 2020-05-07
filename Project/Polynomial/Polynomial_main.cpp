#include "Polynomial.h"

/*
	모든항을 저장하지 않는 희소 다항식(Sparse Polynomial)은
	차수와 계수만 저장하는데, 어차피 순서대로 출력해야한다면,
	차라리 Map을 사용해서 저장하고 출력하는 방식이 더 좋아보인다.
	정렬이 되기 때문. 또한 읽는 속도가 O(1)이므로.

	하지만 학습을 위해 일단, Vector로 구현해보겠다.
	또한 전제 조건은 높은 차수부터 입력하도록 한다.

	대략 4시간 정도 걸린듯. 벡터와 참조에 대해서 배움.
	2019. August, 14
	Copyright 2019. SungHoon Kim. All rights reserved.
*/

int main()
{
	Polynomial poly_a, poly_b;
	int input = 0;
	int exp = 0;
	float coeff = 0;

	std::cout << "A의 항의 갯수 입력 : ";
	std::cin >> input;
	poly_a.SetSize(input);
	for (int i = 0; i < input; i++)
	{
		std::cout << "A의 지수(차수) 입력 : ";
		std::cin >> exp;
		std::cout << "A의 계수 입력 : ";
		std::cin >> coeff;
		poly_a.NewTerm(exp, coeff);
	}
	std::cout << std::endl;

	std::cout << "B의 항의 갯수 입력 : ";
	std::cin >> input;
	poly_b.SetSize(input);
	for (int i = 0; i < input; i++)
	{
		std::cout << "B의 지수(차수) 입력 : ";
		std::cin >> exp;
		std::cout << "B의 계수 입력 : ";
		std::cin >> coeff;
		poly_b.NewTerm(exp, coeff);
	}
	std::cout << std::endl << std::endl;
	
	/////////////////////////////////////////////////////
	
	poly_a.Add(poly_b).Print();
	poly_a.Sub(poly_b).Print();
	poly_a.Mult(poly_b).Print();
	poly_a.Div(poly_b).Print();

	return 0;
}
