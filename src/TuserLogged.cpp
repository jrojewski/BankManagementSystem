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
    TrunMenu runMenu;

    tMenu.makeTransactions();
    int choice;
    string user = log.getLogin();

    cin >> choice;
    switch (choice)
    {
    case 1:
        cashDeposit(user);
        runMenu.runUserLoggedMenu(user);
        break;
    case 2:
        cashWithdraw(user);
        runMenu.runUserLoggedMenu(user);
        break;
    case 3:
        /* code */
        break;
    case 4:
        runMenu.runUserLoggedMenu(user);
        break;
    default:
        break;
    }
}

void TuserLogged::cashDeposit(string user, int cash){

    cout << "How much money would you like to deposit?\n";
    do{
        cin >> cash;
        if(cash <= 0){
            cout << "Deposit value must be higher than 0...\nPlease try again...:\n";
        }
    }while(cash <= 0);

    dbConnection db;
    db.depositCash(user, cash);
    double currentBalance = db.checkCurrentBalance(user);
    cout << "Your balance is: " << currentBalance << endl;

    db.closeDB();
}

void TuserLogged::cashWithdraw(string user, int cash) {

    cout << "How much money would you like to withdraw?\n";
    do{
        cin >> cash;
        if(cash <= 0){
            cout << "Withdraw value must be higher than 0...\nPlease try again...:\n";
        }
    }while(cash <= 0);

    dbConnection db;
    db.withdrawCash(user, cash);
    double currentBalance = db.checkCurrentBalance(user);
    cout << "Your balance is: " << currentBalance << endl;

    db.closeDB();
}

void TuserLogged::transactionHistory(string user){

    dbConnection db;
    cout << "Dear " << user << "...\n";
    cout << "Your account history: \n" << endl;
    int his = db.showTransactionEvent(user);
    db.closeDB();

}

