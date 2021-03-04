#pragma once

class BankAccount
{
protected:
	double moneyOnCard = 0;
public:
	BankAccount();
	BankAccount(double);
	virtual double AddToCard(double, int) = 0;
	virtual double SendToOtherCard(double) = 0;
	virtual double SendToOtherCardWithPercent(double, int) = 0;
};

class StandartAcc :public BankAccount
{
public:
	StandartAcc();
	StandartAcc(double);
	double AddToCard(double, int) override;
	double SendToOtherCard(double) override;
	double SendToOtherCardWithPercent(double, int) override;
};

class SocialAcc :public StandartAcc
{
public:
	double cashback = 0;
	SocialAcc();
	SocialAcc(double);
	double SendToOtherCard(double);
	double SendToOtherCardWithPercent(double, int);
	void CashbackExit();
};

class VIPAcc :public SocialAcc
{
public:
	VIPAcc();
	VIPAcc(double);
};