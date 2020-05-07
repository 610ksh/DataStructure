#include "Polynomial.h"

/*
	������� �������� �ʴ� ��� ���׽�(Sparse Polynomial)��
	������ ����� �����ϴµ�, ������ ������� ����ؾ��Ѵٸ�,
	���� Map�� ����ؼ� �����ϰ� ����ϴ� ����� �� ���ƺ��δ�.
	������ �Ǳ� ����. ���� �д� �ӵ��� O(1)�̹Ƿ�.

	������ �н��� ���� �ϴ�, Vector�� �����غ��ڴ�.
	���� ���� ������ ���� �������� �Է��ϵ��� �Ѵ�.

	�뷫 4�ð� ���� �ɸ���. ���Ϳ� ������ ���ؼ� ���.
	2019. August, 14
	Copyright 2019. SungHoon Kim. All rights reserved.
*/

int main()
{
	Polynomial poly_a, poly_b;
	int input = 0;
	int exp = 0;
	float coeff = 0;

	std::cout << "A�� ���� ���� �Է� : ";
	std::cin >> input;
	poly_a.SetSize(input);
	for (int i = 0; i < input; i++)
	{
		std::cout << "A�� ����(����) �Է� : ";
		std::cin >> exp;
		std::cout << "A�� ��� �Է� : ";
		std::cin >> coeff;
		poly_a.NewTerm(exp, coeff);
	}
	std::cout << std::endl;

	std::cout << "B�� ���� ���� �Է� : ";
	std::cin >> input;
	poly_b.SetSize(input);
	for (int i = 0; i < input; i++)
	{
		std::cout << "B�� ����(����) �Է� : ";
		std::cin >> exp;
		std::cout << "B�� ��� �Է� : ";
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
