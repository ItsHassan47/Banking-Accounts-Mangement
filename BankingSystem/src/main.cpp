#include "Account.h"
#include "Account_Util.h"

int main()
{
	std::cout << '\n' << std::setw(70) << "Welcome to the Banking Account Manager\n" << std::endl;

	std::vector<std::unique_ptr<Account>> accounts;

	int choice {0};

	while (true) {
		std::cout << "\nPress 1 to Open a Savings Account" << std::endl
			<< "Press 2 to Open a Current account" << std::endl
			<< "Press 3 to Open a Trust account" << std::endl
			<< "Press 4 to Deposit" << std::endl
			<< "Press 5 to Withdraw" << std::endl
			<< "Press 6 to Display" << std::endl
			<< "Press 7 to Clear the Screen" << std::endl
			<< "Press 8 to Exit" << std::endl
			<< "\nEnter your choice: ";
		std::cin >> choice;
		std::cin.ignore();

		if (choice == 7)			
			system("CLS");			
		if (choice == 8)
			break;

		account_switch(accounts, choice);
	}

	return 0;
}