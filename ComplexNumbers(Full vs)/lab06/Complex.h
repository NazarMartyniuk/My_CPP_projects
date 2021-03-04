#pragma once
#include <iostream>

class Complex
{
	static int HowManyObjects;
public:
	double real, imag;
	int power;
	Complex();
	Complex(double realN, double imagN);
	Complex(double realN);
	Complex(double realN, double imagN, int pow);
	double Module(double real, double imag);
	double TrigonometricFormCosinus(double real, double imag);
	double TrigonometricFormSinus(double real, double imag);
	Complex operator+(Complex elem1)
	{
		return Complex(real + elem1.real, imag + elem1.imag);
	}
	Complex operator-(Complex elem1)
	{
		return Complex(real - elem1.real, imag - elem1.imag);
	}
	Complex operator*(Complex elem1)
	{
		Complex rez;
		rez.real = (real * elem1.real) - (imag * elem1.imag);
		rez.imag = (real * elem1.imag) + (imag * elem1.real);
		return rez;
	}
	Complex operator^(Complex elem) //перевантаження оператора модуля
	{
		Complex rez = sqrt(pow(elem.real, 2) + pow(elem.imag, 2));
		return rez;
	}
	friend System::String^ operator<<(System::String^ out, Complex point)
	{
		out = point.real + "+i" + point.imag;
		return out;
	}
	friend std::istream& operator>>(std::istream& in, Complex point)
	{
		in >> point.real;
		in >> point.imag;
		return in;
	}
	friend bool operator<(Complex elem1, Complex elem2)
	{
		if ((sqrt(pow(elem1.real, 2) + pow(elem1.imag, 2))) < (sqrt(pow(elem2.real, 2) + pow(elem2.imag, 2))))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	friend bool operator>(Complex elem1, Complex elem2)
	{
		if ((sqrt(pow(elem1.real, 2) + pow(elem1.imag, 2))) > (sqrt(pow(elem2.real, 2) + pow(elem2.imag, 2))))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	friend bool operator==(Complex elem1, Complex elem2)
	{
		if ((sqrt(pow(elem1.real, 2) + pow(elem1.imag, 2))) == (sqrt(pow(elem2.real, 2) + pow(elem2.imag, 2))))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	double PowerR(double real, double imag, int power);
	double PowerI(double real, double imag, int power);
	static int Get_HowManyObjCreated();
};