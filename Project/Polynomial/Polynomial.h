#pragma once

#include <iostream>
#include <vector>

class Polynomial;

// ĸ��ȭ�� ���� Ŭ������ ����(private)
class Term {
	// Polynomial Ŭ�������� termArray�� ���� Term Ŭ������ private�� �����ϱ� ���� �ʿ�.
	friend Polynomial;
private:
	int exp; // ����(����) : exponent
	float coef; // ��� : coefficient
};


class Polynomial {
private:
	std::vector<Term> termArray;
	int length = 0;

public:
	void SetSize(const int& size);
	void NewTerm(const int & theExp, const float & theCoeff);
	Polynomial Add(Polynomial& b);
	Polynomial Mult(Polynomial& b);
	Polynomial Sub(Polynomial& b);
	Polynomial Div(Polynomial& b);
	void Print() const;
};