#include "TcreateUser.hpp"
#include <iostream>
//#include <curses.h>
#include <string>
#include "dbConnection.hpp"
#include "sqlite3/sqlite3.h"

using namespace std;

bool ifUserExist = false;

struct client {
  string login;
  string password;
};

void TcreateUser::createUser(){

    client client;

    cout << "Insert new Username: ";
    cin >> client.login;

    /* if user exists, do not ask for password for new user
    if(TcreateUser::checkIfUserExist(client.user)){
        return;
    } */

    string pw;
    do
    {
        cout << "Enter the password: ";
        cin >> client.password;
        cout << "Re-enter the password once more: ";
        cin >> pw;

        if(client.password != pw){
            cout << "wrong passwords\nTry again\n";
        }else if(client.password == client.login){
            cout << "Password can't be the same as an user name\n";
        }
    } while ( (client.password != pw) || (client.login == client.password) );

    dbConnection db;
    db.addUser(client.login, client.password);
    db.closeDB();

    cout << "\nNew account has been created.\n";
}

bool TcreateUser::checkIfUserExist(string username){

    dbConnection dbCon;
    if(!dbCon.findUser(username)){
        cout << "Sorry, user not found" << endl;
        return false;
    }

    dbCon.closeDB();
    return true;
}

