#pragma once
#include "Savings_Account.h"

class Trust_Account : public Savings_Account
{
protected:
	double m_bonus;
	int m_count {0};
public:
	Trust_Account(std::string name = "Unnamed Account", double balance = 0.0, int pin = 0, int int_rate = 0, int m_bonus = 0);
	virtual bool deposit(double amount = 0.0) override;
	virtual bool withdraw(double amount = 0.0) override;
	virtual void print(std::ostream &os) const override;
	virtual ~Trust_Account() = default;
};