#include "TcreateUser.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include "dbConnection.hpp"
#include "sqlite3/sqlite3.h"
//#include <curses.h>

using namespace std;

bool ifUserExist = false;

struct client {
    string firstName;
    string lastName;
    string login;
    string numberLogin;
    string password;
};

void TcreateUser::createUser(){

    client client;

    cout << "Insert your first name: " << endl;
    cin >> client.firstName;

    cout << "Insert your last name: " << endl;
    cin >> client.lastName;

    // creating client's login - make a method later
    // loop added - check of login in DB
    int tmp;
    stringstream ss;
    bool loginCheck;
    do
    {
        srand (time(NULL));
        for( int i = 0; i < 6; i++) {
            tmp = rand() % 10;
            ss << tmp;
        }
        ss >> client.numberLogin;
        // Comment below for development purpose
        //client.login = client.firstName.substr(0,3) + client.lastName.substr(0,3) + client.numberLogin;
        client.login = client.firstName;
        loginCheck = checkIfUserExist(client.login);
    } while ( loginCheck );

    cout << "LZ---------------\n";
    string pw;
    do
    {
        cout << "Enter the password: ";
        cin >> client.password;
        cout << "Re-enter the password once more: ";
        cin >> pw;

        if(client.password != pw){
            cout << "wrong passwords\nTry again\n";
        } else if(client.password == client.login) {
            cout << "Password can't be the same as an user name\n";
        }
    } while ( (client.password != pw) || (client.login == client.password) );

    dbConnection db;
    db.addUser(client.firstName, client.lastName, client.login, client.password);
    db.closeDB();

    cout << "\nNew account has been created. Your login: " << client.login << endl;
}

bool TcreateUser::checkIfUserExist(string username){

    dbConnection dbCon;
    if(dbCon.findUser(username)){
        cout << "User founded" << endl;
        dbCon.closeDB();
        return true;
    }

    printf("User NOT found <%s:%d>\n", __FUNCTION__, __LINE__);
    dbCon.closeDB();
    return false;
}

bool TcreateUser::checkPassword(string username, string password){

    dbConnection dbCon;

    if(!dbCon.checkUsersPassword(username, password)){
        dbCon.closeDB();
        return false;
    }

    dbCon.closeDB();
    return true;

}


