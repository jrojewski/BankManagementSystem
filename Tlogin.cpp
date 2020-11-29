#include "Tlogin.hpp"
#include <iostream>
#include "TcreateUser.hpp"

using namespace std;

bool RC_ERR = false;

bool Tlogin::login(){

    TcreateUser user;
    string login, pass;
    int loginAttemtsCounter = 0;

    //login check in DB
    do
    {
        cout << "Your Login: ";
        cin >> login;
        loginAttemtsCounter++;
        if(loginAttemtsCounter==3){
            cout << "Ops, something went wrong...\n";
            RC_ERR = true;
        }
    // } while (!user.checkIfUserExist(login));
    } while (loginAttemtsCounter<3 || user.checkIfUserExist(login));

    if(RC_ERR){
        return false;
    }

    //Password check
    int attempts = 0;
    do
    {
        cout << "Password:  ";
        cin >> pass;
        attempts++;

        if(attempts == 3)
        {
            return false;
        }
        cout << "Wrong password... You have "<< 3 - attempts << " more\n";
    } while (pass != "lz");

    return true;
}