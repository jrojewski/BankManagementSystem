#include "Tlogin.hpp"
#include <iostream>
#include "TcreateUser.hpp"

using namespace std;

bool Tlogin::login(){

    TcreateUser user;
    string login, pass;

    cout << "tLogin LZLZLZ" << endl;

    cout << "Podaj login: ";
    cin >> login;
    /*
    if(user.checkIfUserExist(login)==false){

        return false;
    } */


    // cout << "Password:  ";
    // cin >> pass;

    int attempts = 0;
    do
    {
        cout << "Password:  ";
        cin >> pass;
        attempts++;

        if(attempts == 3){
            return false;
        }
        cout << "Wrong pass... You have "<< 3 - attempts << " more\n";

    } while (pass != "lz");

    return true;
}
