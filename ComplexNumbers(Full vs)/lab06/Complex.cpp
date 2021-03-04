#include "Complex.h"

int Complex::HowManyObjects = 0;
Complex::Complex()
{
	HowManyObjects++;
}

Complex::Complex(double realN, double imagN)
{
	HowManyObjects++;
	real = realN;
	imag = imagN;
}

Complex::Complex(double realN)
{
	HowManyObjects++;
	real = realN;
}

Complex::Complex(double realN, double imagN, int pow)
{
	HowManyObjects++;
	real = realN;
	imag = imagN;
	power = pow;
}

double Complex::Module(double real, double imag)
{
	return sqrt(pow(real, 2) + pow(imag, 2));
}

double Complex::TrigonometricFormSinus(double real, double imag)
{
	double sinus;
	sinus = imag / (Module(real, imag));
	return sinus;
}

double Complex::TrigonometricFormCosinus(double real, double imag)
{
	double cosinus;
	cosinus = real / (Module(real, imag));
	return cosinus;
}

double Complex::PowerR(double real, double imag, int power)
{
	double result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= ((real * real) - (imag * imag));
	}
	return result;
}

double Complex::PowerI(double real, double imag, int power)
{
	double result = 1;
	for (int i = 0; i < power; i++)
	{
		result *= ((real * imag) + (imag * real));
	}
	return result;
}

int Complex::Get_HowManyObjCreated()
{
	return HowManyObjects;
}