#include "Trust_Account.h"

Trust_Account::Trust_Account(std::string name, double balance, int pin, int int_rate, int bonus)
	: Savings_Account {name, balance, pin, int_rate}, m_bonus {5000} {}


bool Trust_Account::deposit(double amount)
{
	if (amount > 50000) {
		amount += m_bonus;
		return Savings_Account::deposit(amount);
	}
	return Savings_Account::deposit(amount);
}

bool Trust_Account::withdraw(double amount)
{
	const int max_count {3};
	while (m_count < max_count) {
		m_count++;
		return Account::withdraw(amount);
	}
	return false;
}

void Trust_Account::print(std::ostream &os) const
{
	os.precision(2);
	os << std::fixed;
	os << " [Trust Account name: " << m_name << "] [Balance: " << m_balance << "] [Interest rate: " << m_int_rate << "%" << "][Bonus: " << m_bonus << "]";
}