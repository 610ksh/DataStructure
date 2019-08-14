#include "Polynomial.h"

void Polynomial::SetSize(const int & size)
{
	// 혹시 모를 추가를 위해 2배 공간 할당
	termArray.reserve(size * 2);
	// 사이즈 지정 및 0으로 초기화
	termArray.resize(size);
}

void Polynomial::NewTerm(const int & theExp, const float & theCoeff)
{
	termArray[length].exp = theExp;
	termArray[length++].coef = theCoeff;
}

Polynomial Polynomial::Add(Polynomial & b)
{
	// 새로운 임시 변수를 만들어 출력한다.
	Polynomial poly_Add;
	poly_Add.termArray.resize(length + b.length);

	int aPos = 0, bPos = 0;

	while (aPos < this->length && bPos < b.length)
	{
		// 차수가 a > b, b를 넣는다
		if (this->termArray[aPos].exp > b.termArray[bPos].exp) {
			poly_Add.NewTerm(b.termArray[bPos].exp, b.termArray[bPos].coef);
			bPos++;
		}
		// 차수가 a = b, 더한값을 넣는다
		else if (this->termArray[aPos].exp == b.termArray[bPos].exp) {
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			// 0이 아니라면
			if (t) {
				poly_Add.NewTerm(this->termArray[aPos].exp, t);
			}
			aPos++, bPos++;
		}
		// 차수가 a < b, a를 넣는다
		else {
			poly_Add.NewTerm(this->termArray[aPos].exp, this->termArray[aPos].coef);
			aPos++;
		}
	}

	/* 남아있는 항을 모두 출력한다. */

	// a항
	for (; aPos < length; ++aPos) {
		poly_Add.NewTerm(this->termArray[aPos].exp, this->termArray[aPos].coef);
	}

	// b항
	for (; bPos < b.length; ++bPos) {
		poly_Add.NewTerm(b.termArray[bPos].exp, b.termArray[bPos].coef);
	}

	return poly_Add;
}

Polynomial Polynomial::Sub(Polynomial & b)
{
	// 새로운 임시 변수를 만들어 출력한다.
	Polynomial poly_Add;
	poly_Add.termArray.resize(length + b.length);

	int aPos = 0, bPos = 0;

	while (aPos < this->length && bPos < b.length)
	{
		// 차수가 a > b, b를 넣는다
		if (this->termArray[aPos].exp > b.termArray[bPos].exp) {
			poly_Add.NewTerm(b.termArray[bPos].exp, -(b.termArray[bPos].coef));
			bPos++;
		}
		// 차수가 a = b, 더한값을 넣는다
		else if (this->termArray[aPos].exp == b.termArray[bPos].exp) {
			float t = termArray[aPos].coef - b.termArray[bPos].coef;
			// 0이 아니라면
			if (t) {
				poly_Add.NewTerm(this->termArray[aPos].exp, t);
			}
			aPos++, bPos++;
		}
		// 차수가 a < b, a를 넣는다
		else {
			poly_Add.NewTerm(this->termArray[aPos].exp, this->termArray[aPos].coef);
			aPos++;
		}
	}

	/* 남아있는 항을 모두 출력한다. */

	// a항
	for (; aPos < length; ++aPos) {
		poly_Add.NewTerm(this->termArray[aPos].exp, this->termArray[aPos].coef);
	}

	// b항
	for (; bPos < b.length; ++bPos) {
		poly_Add.NewTerm(b.termArray[bPos].exp, -(b.termArray[bPos].coef));
	}

	return poly_Add;
}

Polynomial Polynomial::Mult(Polynomial & b)
{
	Polynomial poly_Mult;
	poly_Mult.termArray.resize(length + b.length);
	// b를 a 다항식에 곱함.
	for (int i = 0; i < b.length; ++i)
	{
		Polynomial temp;
		temp.termArray.resize(length);
		// a 행만큼 실행
		for (int j = 0; j < length; ++j)
		{
			temp.NewTerm(termArray[j].exp + b.termArray[i].exp, termArray[j].coef * b.termArray[i].coef);
		}
		poly_Mult = poly_Mult.Add(temp);
	}

	return poly_Mult;
}

Polynomial Polynomial::Div(Polynomial & b)
{
	Polynomial poly_Div;
	poly_Div.termArray.resize(length + b.length);
	// b를 a 다항식에 곱함.
	for (int i = 0; i < b.length; ++i)
	{
		Polynomial temp;
		temp.termArray.resize(length);
		// a 행만큼 실행
		for (int j = 0; j < length; ++j)
		{
			temp.NewTerm(termArray[j].exp - b.termArray[i].exp, termArray[j].coef / b.termArray[i].coef);
		}
		poly_Div = poly_Div.Add(temp);
	}

	return poly_Div;
}

void Polynomial::Print() const
{
	int index = 0;
	for (unsigned int i = 0; i < length; i++)
		std::cout << i << "번째 coef(계수) : " << termArray[i].coef << " exp(지수) : " << termArray[i].exp << std::endl;
	std::cout << "배열길이 : " << termArray.size() << "  실제 길이 : " << length << std::endl;
	std::cout << std::endl;
}