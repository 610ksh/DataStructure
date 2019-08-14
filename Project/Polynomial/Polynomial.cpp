#include "Polynomial.h"

void Polynomial::SetSize(const int & size)
{
	// Ȥ�� �� �߰��� ���� 2�� ���� �Ҵ�
	termArray.reserve(size * 2);
	// ������ ���� �� 0���� �ʱ�ȭ
	termArray.resize(size);
}

void Polynomial::NewTerm(const int & theExp, const float & theCoeff)
{
	termArray[length].exp = theExp;
	termArray[length++].coef = theCoeff;
}

Polynomial Polynomial::Add(Polynomial & b)
{
	// ���ο� �ӽ� ������ ����� ����Ѵ�.
	Polynomial poly_Add;
	poly_Add.termArray.resize(length + b.length);

	int aPos = 0, bPos = 0;

	while (aPos < this->length && bPos < b.length)
	{
		// ������ a > b, b�� �ִ´�
		if (this->termArray[aPos].exp > b.termArray[bPos].exp) {
			poly_Add.NewTerm(b.termArray[bPos].exp, b.termArray[bPos].coef);
			bPos++;
		}
		// ������ a = b, ���Ѱ��� �ִ´�
		else if (this->termArray[aPos].exp == b.termArray[bPos].exp) {
			float t = termArray[aPos].coef + b.termArray[bPos].coef;
			// 0�� �ƴ϶��
			if (t) {
				poly_Add.NewTerm(this->termArray[aPos].exp, t);
			}
			aPos++, bPos++;
		}
		// ������ a < b, a�� �ִ´�
		else {
			poly_Add.NewTerm(this->termArray[aPos].exp, this->termArray[aPos].coef);
			aPos++;
		}
	}

	/* �����ִ� ���� ��� ����Ѵ�. */

	// a��
	for (; aPos < length; ++aPos) {
		poly_Add.NewTerm(this->termArray[aPos].exp, this->termArray[aPos].coef);
	}

	// b��
	for (; bPos < b.length; ++bPos) {
		poly_Add.NewTerm(b.termArray[bPos].exp, b.termArray[bPos].coef);
	}

	return poly_Add;
}

Polynomial Polynomial::Sub(Polynomial & b)
{
	// ���ο� �ӽ� ������ ����� ����Ѵ�.
	Polynomial poly_Add;
	poly_Add.termArray.resize(length + b.length);

	int aPos = 0, bPos = 0;

	while (aPos < this->length && bPos < b.length)
	{
		// ������ a > b, b�� �ִ´�
		if (this->termArray[aPos].exp > b.termArray[bPos].exp) {
			poly_Add.NewTerm(b.termArray[bPos].exp, -(b.termArray[bPos].coef));
			bPos++;
		}
		// ������ a = b, ���Ѱ��� �ִ´�
		else if (this->termArray[aPos].exp == b.termArray[bPos].exp) {
			float t = termArray[aPos].coef - b.termArray[bPos].coef;
			// 0�� �ƴ϶��
			if (t) {
				poly_Add.NewTerm(this->termArray[aPos].exp, t);
			}
			aPos++, bPos++;
		}
		// ������ a < b, a�� �ִ´�
		else {
			poly_Add.NewTerm(this->termArray[aPos].exp, this->termArray[aPos].coef);
			aPos++;
		}
	}

	/* �����ִ� ���� ��� ����Ѵ�. */

	// a��
	for (; aPos < length; ++aPos) {
		poly_Add.NewTerm(this->termArray[aPos].exp, this->termArray[aPos].coef);
	}

	// b��
	for (; bPos < b.length; ++bPos) {
		poly_Add.NewTerm(b.termArray[bPos].exp, -(b.termArray[bPos].coef));
	}

	return poly_Add;
}

Polynomial Polynomial::Mult(Polynomial & b)
{
	Polynomial poly_Mult;
	poly_Mult.termArray.resize(length + b.length);
	// b�� a ���׽Ŀ� ����.
	for (int i = 0; i < b.length; ++i)
	{
		Polynomial temp;
		temp.termArray.resize(length);
		// a �ุŭ ����
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
	// b�� a ���׽Ŀ� ����.
	for (int i = 0; i < b.length; ++i)
	{
		Polynomial temp;
		temp.termArray.resize(length);
		// a �ุŭ ����
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
		std::cout << i << "��° coef(���) : " << termArray[i].coef << " exp(����) : " << termArray[i].exp << std::endl;
	std::cout << "�迭���� : " << termArray.size() << "  ���� ���� : " << length << std::endl;
	std::cout << std::endl;
}