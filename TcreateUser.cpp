#include "TcreateUser.hpp"
#include <iostream>
#include <curses.h>
#include <string>

using namespace std;

bool ifUserExist = false;

struct client {
  string user;
  string password;
} ;

bool TcreateUser::checkIfUserExist(string username){

    //check in db
    string usr;
    cout << "LZ " << username << endl;

    /* chceck allUsers from DB
    *  DB conectivity need to be done here
    *  to check if use name is already added in DB
    */
    if(username=="lz"){
        cout << "User already existy in Database" << endl;
        ifUserExist = true;
        return true;
    }
    cout << "No such user in bank...\n";

    return false;

}

void TcreateUser::createUser(){

    client client;

    cout << "Insert new Username: ";
    cin >> client.user;

    // if user exists, do not ask for password for new user
    if(TcreateUser::checkIfUserExist(client.user)){
        return;
    }

    string pw;
    do
    {
        cout << "Enter the password: ";
        cin >> client.password;
        cout << "Re-enter the password once more: ";
        cin >> pw;

        if(client.password != pw){
            cout << "wrong passwords\nTry again\n";
        }else if(client.password == client.user){
            cout << "Password can't be the same as an user name\n";
        }
    } while ( (client.password != pw) || (client.user == client.password) );

    cout << "\nNew account has been created.\n";
    cout << "Summary:\n\tUsername:\t " + client.user + "\n\tPassword:\t " + client.password << endl;
}


