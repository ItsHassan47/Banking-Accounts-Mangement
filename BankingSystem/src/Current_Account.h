#pragma once
#include "Account.h"

class Current_Account : public Account
{
protected:
	int m_fee;

public:
	Current_Account(std::string name = "Unnamed Account", double balance = 0.0, int pin = 0, int fee = 0);
	virtual bool deposit(double amount = 0.0) override;
	virtual bool withdraw(double amount = 0.0) override;
	virtual void print(std::ostream &os) const override;
	virtual ~Current_Account() = default;
};