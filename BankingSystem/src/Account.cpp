#include "Account.h"

Account::Account(std::string name, double balance, int pin)
	: m_name {name}, m_balance {balance}, m_pin {pin} {}


int Account::getPin() const { return m_pin; }

std::string Account::getName() const { return m_name; }

bool Account::deposit(double amount)
{
	if (amount > 0) {
		m_balance += amount;
		return true;
	}
	return false;
}

bool Account::withdraw(double amount)
{
	if (amount <= m_balance) {
		m_balance -= amount;
		return true;
	}
	return false;
}

std::ostream &operator << (std::ostream &os, const Account &obj)
{
	obj.print(os);
	return os;
}