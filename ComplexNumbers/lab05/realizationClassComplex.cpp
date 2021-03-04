#include "Complex.h"
#include <math.h>

Complex::Complex()
{}
Complex::Complex(double vNumb1, double vNumb2, double iNumb1, double iNumb2)
{
	validNumb1 = vNumb1;
	validNumb2 = vNumb2;
	imaginaryNumb1 = iNumb1;
	imaginaryNumb2 = iNumb2;
}
Complex::Complex(double vNumb, double iNumb, int power)
{
	validNumb = vNumb;
	imaginaryNumb = iNumb;
	this->power = power;
}
double Complex::ValidSum(void)
{
	return (validNumb1 + validNumb2);
}
double Complex::ImaginarySum(void)
{
	return (imaginaryNumb1 + imaginaryNumb2);
}
double Complex::ValidSubtraction(void)
{
	return (validNumb1 - validNumb2);
}
double Complex::ImaginarySubtraction(void)
{
	return (imaginaryNumb1 - imaginaryNumb2);
}
double Complex::ValidMultiplication(void)
{
	return ((validNumb1 * validNumb2) - (imaginaryNumb1 * imaginaryNumb2));
}
double Complex::ImaginaryMultiplication(void)
{
	return ((validNumb1 * imaginaryNumb2) + (imaginaryNumb1 * validNumb2));
}
double Complex::ValidPower(void)
{
	result = 1;
	tempResult = 1;
	if (power > 1)
	{
		for (size_t i = 1; i < power; i++)
		{
			result = ((validNumb * validNumb) - (imaginaryNumb * imaginaryNumb)) * tempResult;
			tempResult = result;
		}
		return result;
	}
	else
	{
		return validNumb;
	}
}
double Complex::ImaginaryPower(void)
{
	result = 1;
	tempResult = 1;
	if (power > 1)
	{
		for (size_t i = 1; i < power; i++)
		{
			result = ((validNumb * imaginaryNumb) + (imaginaryNumb * validNumb)) * tempResult;
			tempResult = result;
		}
		return result;
	}
	else
	{
		return imaginaryNumb;
	}
}
double Complex::Module(void)
{
	return sqrt(pow(validNumb, 2) + pow(imaginaryNumb, 2));
}
double Complex::TrigonometricFormCosinus(void)
{
	r = Module();
	result = validNumb / r;
	return result;
}
double Complex::TrigonometricFormSinus(void)
{
	r = Module();
	result = imaginaryNumb / r;
	return result;
}
