#include "Credit.h"

Credit::Credit()
{

}
Credit::Credit(string tSentence)
{
}
Credit::Credit(double num1, double num2, int num3)
{
	sumToPay = num1;
	moneyOnCard = num2;
	timeToPay = num3;
	alreadyPayed = 0;
	needToPay = num1;
	paymentCount = num3;
}
Credit::Credit(double num1, double num2, double num3, int num4)
{
	sumToPay = num1;
	moneyOnCard = num2;
	percentFromCredit = num3;
	timeToPay = num4;
	alreadyPayed = 0;
	paymentCount = num3;
}
double Credit::EqualPartsPayment()
{
	double result;
	result = sumToPay / timeToPay;
	return result;
}
double Credit::PaymentPrecent()
{
	double result;
	result = sumToPay * percentFromCredit / 100;
	return result;
}
void Credit::Print(string sentence)
{
	sentence += "Credit\n";
}
EqualParts::EqualParts() :Credit()
{
}
EqualParts::EqualParts(string tSentence) : Credit(tSentence)
{
}
EqualParts::EqualParts(double num1, double num2, int num3) : Credit(num1, num2, num3)
{
}
void EqualParts::Print(string sentence)
{
	sentence += "EqualParts";
}
PercentPayment::PercentPayment() :Credit()
{}
PercentPayment::PercentPayment(string tSentence) :Credit(tSentence)
{}
PercentPayment::PercentPayment(double num1, double num2, double num3, int num4) : Credit(num1, num2, num3, num4)
{}
double PercentPayment::PercentSum()
{
	double percent, result;
	percent = PaymentPrecent();
	result = sumToPay + (percent * timeToPay);
	needToPay = result;
	sumToPay = result;
	return result;
}
void PercentPayment::Print(string sentence)
{
	sentence += "PercentPayment\n";
}
PrivilegePayment::PrivilegePayment():Credit()
{}
PrivilegePayment::PrivilegePayment(string tSentence):Credit(tSentence)
{}
PrivilegePayment::PrivilegePayment(double num1, double num2, double num3, int num4):Credit(num1, num2, num3, num4)
{}
double PrivilegePayment::PrivilegeSum()
{
	double result, percent;
	percent = PaymentPrecent();
	result = sumToPay - (percent * timeToPay);
	needToPay = result;
	sumToPay = result;
	return result;
}
void PrivilegePayment::Print(string sentence)
{
	sentence += "\nPrivilegePayment";
}