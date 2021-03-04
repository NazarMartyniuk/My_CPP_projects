#include <math.h>
class Complex
{
private:
	double tempResult, r, result, imaginaryNumb1, imaginaryNumb2, validNumb1, validNumb2, power, validNumb, imaginaryNumb;
public:
	Complex(void);
	Complex(double vNumb1, double vNumb2, double iNumb1, double iNumb2);
	Complex(double vNumb, double iNumb, int power);
	double ValidSum(void);
	double ImaginarySum(void);
	double ValidSubtraction(void);
	double ImaginarySubtraction(void);
	double ValidMultiplication(void);
	double ImaginaryMultiplication(void);
	double ValidPower(void);
	double ImaginaryPower(void);
	double Module(void);
	double TrigonometricFormCosinus(void);
	double TrigonometricFormSinus(void);
};