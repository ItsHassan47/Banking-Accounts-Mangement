#include "Current_Account.h"

Current_Account::Current_Account(std::string name, double balance, int pin, int fee) 
	: Account {name, balance, pin}, m_fee {50} {}


bool Current_Account::deposit(double amount) {
	return Account::deposit(amount);
}

bool Current_Account::withdraw(double amount) {
	m_balance -= m_fee;
	return Account::withdraw(amount);
}

void Current_Account::print(std::ostream &os) const {
	os.precision(2);
	os << std::fixed;
	os << " [Current Account name: " << m_name << "] [Balance: " << m_balance << "] [ Withdraw fee cut: " << m_fee << " PKR]";
}