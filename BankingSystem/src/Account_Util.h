#pragma once
#include "Account.h"
#include "Savings_Account.h"
#include "Current_Account.h"
#include "Trust_Account.h"

// Utility functions

void account_switch(std::vector<std::unique_ptr<Account>> &accounts, int choice = 0);
void handles_accounts(std::vector<std::unique_ptr<Account>> &accounts, int choice = 0);
void deposit(std::vector<std::unique_ptr<Account>> &accounts);
void withdraw(std::vector<std::unique_ptr<Account>> &accounts);
void display(std::vector<std::unique_ptr<Account>> &accounts);
void ClearScreen();