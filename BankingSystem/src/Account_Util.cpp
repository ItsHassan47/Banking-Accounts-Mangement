#include "Account_Util.h"

void account_switch(std::vector<std::unique_ptr<Account>> &accounts, int choice)
{
	switch (choice) {
	case 1:
		handles_accounts(accounts, choice);
		return;
	case 2:
		handles_accounts(accounts, choice);
		return;
	case 3:
		handles_accounts(accounts, choice);
		return;
	case 4:
		deposit(accounts);
		return;
	case 5:
		withdraw(accounts);
		return;
	case 6:
		display(accounts);
		return;
	}
}

void handles_accounts(std::vector<std::unique_ptr<Account>> &accounts, int choice)
{
	double init_amount {0};
	std::string name {};
	int pin {0};

	std::cout << "Enter the name: ";
	std::getline(std::cin, name);
	std::cout << "Enter the amount: ";
	std::cin >> init_amount;
	std::cout << "Enter the AccNo: ";
	std::cin >> pin;

	if (choice == 1) {
		accounts.push_back(std::make_unique<Savings_Account>(name, init_amount, pin));
		std::cout << "\n=== Savings Account Opened: " << name << ", with a Account No: " << pin << " =================" << std::endl;
	} else if (choice == 2) {
		accounts.push_back(std::make_unique<Current_Account>(name, init_amount, pin));
		std::cout << "\n=== Current Account Opened: " << name << ", with a Account No: " << pin << " ================" << std::endl;
	} else if (choice == 3) {
		accounts.push_back(std::make_unique<Trust_Account>(name, init_amount, pin));
		std::cout << "\n=== Trust Account Opened: " << name << ", with a Account No: " << pin << " ==================" << std::endl;
	}
}

void deposit(std::vector<std::unique_ptr<Account>> &accounts)
{
	double dep_amount {0};
	int pin {0};

	std::cout << "Enter the amount to deposit: ";
	std::cin >> dep_amount;
	std::cout << "Enter the AccNo: ";
	std::cin >> pin;
	std::cout << "\n=== Depositing to Accounts =========================================" << std::endl;

	for (auto &acc : accounts) {

		if (acc->getPin() == pin) {
			if (acc->deposit(dep_amount))
				std::cout << "Amount: " << dep_amount << ", Successfully deposited." << std::endl;
			else
				std::cout << "Amount: " << dep_amount << ", Cannot be deposited." << std::endl;
		}
	}
}

void withdraw(std::vector<std::unique_ptr<Account>> &accounts)
{
	double with_amount {0};
	int pin {0};

	std::cout << "Enter the amount to withdraw: ";
	std::cin >> with_amount;
	std::cout << "Enter the AccNo: ";
	std::cin >> pin;
	std::cout << "\n=== Withdrawing from Accounts ======================================" << std::endl;

	for (auto &acc : accounts) {
		if (acc->getPin() == pin) {
			if (acc->withdraw(with_amount))
				std::cout << "Amount: " << with_amount << ", Successfully withdrawn." << std::endl;
			else
				std::cout << "Amount: " << with_amount << ", Cannot be withdrawn." << std::endl;
		}
	}
}

void display(std::vector<std::unique_ptr<Account>> &accounts)
{
	int pin {0};
	std::cout << "Enter the AccNo: ";
	std::cin >> pin;

	for (const auto &acc : accounts) {
		if (acc->getPin() == pin && acc->getName() != "Unnamed Account")
			std::cout << *acc << std::endl;
	}
}

// Function is resposible clearing the console
void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = {0, 0};

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR)' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}