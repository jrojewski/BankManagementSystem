#include "Tmenu.hpp"
#include <iostream>

using namespace std;

void showMenu();

void Tmenu::showMenu()
{
    cout << "Customer Account Bank Management System\n\n";

    cout << "1. Create new account.\n"
    "2. Update information about your existing account.\n"
    "3. For transaction.\n"
    "4. Check the details of your account.\n"
    "5. Removing existing account.\n"
    "6. View customer's list.\n"
    "7. Exit." << endl;
}

