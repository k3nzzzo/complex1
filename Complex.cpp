#include "Complex.h"


Complex Complex::sum(Complex n1)
{
	return Complex{ this->re + n1.re, this->im + n1.im };
}

Complex Complex::minus(Complex n1)
{
	return Complex{ this->re - n1.re, this->im - n1.im };
}

Complex Complex::multiply(Complex n1)
{
	double a = this->re;
	double b = this->im;
	double c = n1.re;
	double d = n1.im;

	return Complex{ a * c - b * d , b * c + a * d };
}

Complex Complex::divide(Complex n1)
{
	Complex conjugated{ n1.re,-n1.im };
	this->multiply(conjugated);
	double denom = pow(n1.re, 2) + pow(n1.im, 2);

	return Complex{ this->re / denom,this->im / denom };
}

void Complex::printComplex()
{
	cout << this->re;

	if (this->im != 0) {
		if (this->im > 0) {
			cout << "+";
		}
		cout << this->im << "i";
	}

}

double Complex::abs()
{
	double result = sqrt(pow(this->re, 2) + pow(this->im, 2));
	return result;
}

Complex Complex::string2Complex(string line)
{
	string reString = "", imString = "";

	if (line.find('+') != string::npos)
	{
		int borderPos = line.find('+');
		for (int i = 0;i < borderPos;i++)
		{
			reString += line[i];
		}
		for (int i = borderPos + 1;i < line.length() - 1;i++)
		{
			imString += line[i];
		}
	}
	else
	{
		int borderPos = line.find('-', 1);
		for (int i = 0;i < borderPos;i++)
		{
			reString += line[i];
		}
		for (int i = borderPos;i < line.length() - 1;i++)
		{
			imString += line[i];
		}
	}


	return Complex{ stod(reString), stod(imString) };
}
