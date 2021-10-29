#pragma once

#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <iomanip>
#include <windows.h>

class Account
{
	friend std::ostream &operator << (std::ostream &os, const Account &account);
protected:
	std::string m_name;
	double m_balance;
	int m_pin;

public:
	Account(std::string name = "Unnamed Account", double balance = 0.0, int pin = 0);
	virtual int getPin() const;
	virtual std::string getName() const;
	virtual bool deposit(double amount = 0.0) = 0;
	virtual bool withdraw(double amount = 0.0) = 0;
	virtual void print(std::ostream &os) const = 0;
	virtual ~Account() = default;
};