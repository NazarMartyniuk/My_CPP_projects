#pragma once
#include <string>
using namespace std;
class Credit
{
protected:
	double sumToPay, moneyOnCard, percentFromCredit;
	int timeToPay;
	string sentence;
public:
	double alreadyPayed, needToPay;
	int paymentCount;
	Credit();
	Credit(string);
	Credit(double num1, double num2, int num3);
	Credit(double num1, double num2, double num3, int num4);
	double EqualPartsPayment();
	double PaymentPrecent();
	void Print(string);
};
class EqualParts : public Credit
{
public:
	EqualParts();
	EqualParts(string);
	EqualParts(double, double, int);
	void Print(string);
};

class PercentPayment : public Credit
{
public:
	PercentPayment();
	PercentPayment(string);
	PercentPayment(double, double, double, int);
	double PercentSum();
	void Print(string);
};

class PrivilegePayment : public Credit
{
public:
	PrivilegePayment();
	PrivilegePayment(string);
	PrivilegePayment(double, double, double, int);
	double PrivilegeSum();
	void Print(string);
};