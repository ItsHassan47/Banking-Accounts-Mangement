#pragma once
#include "Account.h"

class Savings_Account : public Account
{
protected:
	int m_int_rate;
	int m_year;

public:
	Savings_Account(std::string name = "Unnamed Account", double balance = 0.0, int pin = 0, int int_rate = 4, int year = 1);
	virtual bool deposit(double amount = 0.0) override;
	virtual bool withdraw(double amount = 0.0) override;
	virtual void print(std::ostream &os) const override;
	virtual ~Savings_Account() = default;
};