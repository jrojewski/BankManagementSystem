#include "TuserLogged.hpp"
#include "dbConnection.hpp"
#include <iostream>

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