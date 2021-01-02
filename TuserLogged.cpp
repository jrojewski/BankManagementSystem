#include "TuserLogged.hpp"
#include "dbConnection.hpp"
#include <iostream>
#include "Tlogin.hpp"

using namespace std;

double currentBalance;

void TuserLogged::checkCurrentBalance(string user){

    system("clear");
    dbConnection db;
    cout << "Dear " << user << "...\n";
    currentBalance = db.checkCurrentBalance(user);
    cout << "Your balance is: " << currentBalance << endl;

    db.closeDB();
}

int TuserLogged::transactionType(){

    system("clear");

    Tlogin log;
    TshowMenu tMenu;

    string user = log.getLogin();
    tMenu.makeTransactions();
    int choice;

    switch (choice)
    {
    case 1:
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


    return -1;
}

void TuserLogged::cashDeposit(string user){
    double cash;

    cout << "How much money would you like to deposit?\n";
    cin >> cash;

    dbConnection db;
    db.depositCash(cash);
    currentBalance = db.checkCurrentBalance(user);
    cout << "Your balance is: " << currentBalance << endl;

    db.closeDB();


}

