#include "TrunMenu.hpp"
#include "TuserLogged.hpp"
#include "TcreateUser.hpp"
#include "Tlogin.hpp"
#include "TshowMenu.hpp"
#include <iostream>

using namespace std;

void TrunMenu::runMainMenu(){

    TrunMenu runMenu;
    TshowMenu showMenu;
    showMenu.showMainMenu();

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        //Log in
        Tlogin login;
        if(login.login())
        {
            string user = login.getLogin();
            runMenu.runUserLoggedMenu(user);
        }else{
            runMainMenu();
        }
        break;
    case 2:
        //Sign up
        TcreateUser addUser;
        addUser.createUser();
        runMainMenu();
        break;
    case 3:
        cout << "Program closed." << endl;
        break;
    default:
        cout << "Missing option - try again!\n";
        break;
    }
}


void TrunMenu::runUserLoggedMenu(string user){

    TrunMenu runMenu;
    TshowMenu showMenu;
    showMenu.showLoggedMenu();

    TuserLogged action;

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        action.checkCurrentBalance(user);
        runUserLoggedMenu(user);
        break;
    case 2:
        cout << "2\n";
        action.transactionType();

        break;
    case 3:
        cout << "3\n";
        break;
    case 4:
        cout << "4\n";
        break;
    case 5:
        cout << "5\n";
        system("clear");
        runMenu.runMainMenu();
        break;
    default:
        cout << "Missing option - try again!\n";
        break;
    }
}
