#include "Tmenu.hpp"
#include <iostream>

using namespace std;

void mainMenu();

void Tmenu::mainMenu()
{
    cout << "Customer Account Bank Management System\n\n";

    cout << "1. Log in.\n"
    "2. Sign up.\n"
    "3. Exit." << endl;
}

void Tmenu::loggedMenu()
{
    cout << "\n\n";

    cout << "1. Show current balance.\n"
    "2. Make transaction.\n"
    "3. Transaction hitory.\n"
    "4. Edit my account.\n"
    "5. Log out." << endl;
}

void Tmenu::transactionHistoru()
{
    cout << "1. Show your account history\n"
    "2. Back\n" << endl;
}

void Tmenu::selfTransactions()
{
    cout << "1. Deposit\n"
    "2. Withdraw\n"
    "3. Transfer to another account\n"
    "4. Back\n" << endl;
}

void Tmenu::accountEdit()
{
    cout << "1. Password change\n"
    "3. Back\n" << endl;
}
