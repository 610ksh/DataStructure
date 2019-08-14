#pragma once

#include <iostream>
#include <vector>

class Polynomial;

// 캡슐화를 위해 클래스로 선언(private)
class Term {
	// Polynomial 클래스에서 termArray를 통해 Term 클래스의 private에 접근하기 위해 필요.
	friend Polynomial;
private:
	int exp; // 지수(차수) : exponent
	float coef; // 계수 : coefficient
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