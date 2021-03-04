#include "classes.h"

BankAccount::BankAccount()
{ }

BankAccount::BankAccount(double moneyToAdd)
{
	moneyOnCard = moneyToAdd;
}

StandartAcc::StandartAcc() : BankAccount()
{ }

StandartAcc::StandartAcc(double moneyToAdd) : BankAccount(moneyToAdd)
{ }

double StandartAcc::AddToCard(double money, int percent)
{
	int perc = 100 - percent;
	money = money * perc / 100;
	moneyOnCard += money;
	return moneyOnCard;
}

double StandartAcc::SendToOtherCard(double money)
{
	moneyOnCard -= money;
	return moneyOnCard;
}

double StandartAcc::SendToOtherCardWithPercent(double money, int percent)
{
	int perc = 100 + percent;
	money = money * perc / 100;
	moneyOnCard -= money;
	return moneyOnCard;
}

SocialAcc::SocialAcc() : StandartAcc()
{ }

SocialAcc::SocialAcc(double moneyToAdd) : StandartAcc(moneyToAdd)
{ }

double SocialAcc::SendToOtherCard(double money)
{
	moneyOnCard -= money;
	cashback += money * 3 / 100;
	return moneyOnCard;
}

double SocialAcc::SendToOtherCardWithPercent(double money, int percent)
{
	int perc = 100 + percent;
	money = money * perc / 100;
	moneyOnCard -= money;
	cashback += (money * 5 / 100);
	return moneyOnCard;
}

void SocialAcc::CashbackExit()
{
	cashback = 0;
}

VIPAcc::VIPAcc() : SocialAcc()
{ }

VIPAcc::VIPAcc(double moneyToAdd) : SocialAcc(moneyToAdd)
{ }