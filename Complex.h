#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <string>
using namespace std;
using std::string;

struct Complex {
	double re = 0;
	double im = 0;

	Complex sum(Complex n1);

	Complex minus(Complex n1);

	Complex multiply(Complex n1);

	Complex divide(Complex n1);

	void printComplex();

	double abs();

	static Complex string2Complex(string line);
};

#endif