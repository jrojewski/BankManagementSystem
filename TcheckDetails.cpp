#include "TcheckDetails.hpp"
#include <iostream>
//#include <curses.h>
#include <string>
#include "Tlogin.hpp"
#include "TcreateUser.hpp"

using namespace std;

void TcheckDetails::updateAccountData()
{

    Tlogin checkLogin;

    if(!checkLogin.login()){
        return;
    }

    cout << "Jestes zalogowany\n";


    cout << "1. Zmień adres\n"
    "2. Zaktualizuj...\n" << endl;
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\n\n\nAktualizacja adresu\n\n\n";
        break;
    case 2:
        cout << "\n\n\n wut wut \n\n\n";
        break;
    default:
        break;
    }
}