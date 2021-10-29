#include "Savings_Account.h"

Savings_Account::Savings_Account(std::string name, double balance, int pin, int int_rate, int year)
	: Account {name, balance, pin}, m_int_rate {4}, m_year {year} {}

bool Savings_Account::deposit(double amount)
{
	amount += amount * (m_int_rate / 100) * m_year;
	return Account::deposit(amount);
}

bool Savings_Account::withdraw(double amount)
{
	return Account::withdraw(amount);
}

void Savings_Account::print(std::ostream &os) const
{
	os.precision(2);
	os << std::fixed;
	os << " [Savings Account name: " << m_name << "] [Balance: " << m_balance << "] [Interest rate: " << m_int_rate << "%]";
}