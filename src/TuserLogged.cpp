#include "TuserLogged.hpp"
#include "dbConnection.hpp"
#include <iostream>
#include "Tlogin.hpp"

using namespace std;


void TuserLogged::checkCurrentBalance(string user){

    system("clear");
    dbConnection db;
    cout << "Dear " << user << "...\n";
    double currentBalance = db.checkCurrentBalance(user);
    cout << "Your balance is: " << currentBalance << endl;

    db.closeDB();
}

void TuserLogged::transactionType(){

    system("clear");
    Tlogin log;
    TshowMenu tMenu;

    tMenu.makeTransactions();
    int choice;
    string user;

    cin >> choice;
    switch (choice)
    {
    case 1:
        user = log.getLogin();
        TuserLogged::cashDeposit(user);

        break;
    case 2:
        /* code */

        break;
    case 3:
        /* code */
        break;
    case 4:
        /*4code */
        break;
    default:
        break;
    }
}

void TuserLogged::cashDeposit(string user, double cash){

    cout << "How much money would you like to deposit?\n";
    cin >> cash;

    dbConnection db;
    db.depositCash(user, cash);
    double currentBalance = db.checkCurrentBalance(user);
    cout << "Your balance is: " << currentBalance << endl;

    db.closeDB();


}

