#include "Tlogin.hpp"
#include <iostream>
#include "TcreateUser.hpp"

using namespace std;

bool isUser;
bool isPasswordCorrect;
string logUser;

void Tlogin::setLogin(string l)
{
        logUser = l;
}

string Tlogin::getLogin()
{
        return logUser;
}

bool Tlogin::login(){

    TcreateUser user;
    string login, pass;
    int loginAttemtsCounter = 0;
    int passAttemtsCounter = 0;

    isUser = false;
    isPasswordCorrect = false;

    //login check in DB
    do
    {
        cout << "Your Login: ";
        cin >> login;

        if(user.checkIfUserExist(login)){
            cout << "Correct Login\n";
            isUser = true;
        }

        loginAttemtsCounter++;
        if(loginAttemtsCounter==3){
            cout << "\nOps, something went wrong...\n\n";
            return false;
        }
    } while (isUser != true);

    //Password check
    do
    {
        cout << "Password:  ";
        cin >> pass;

        if(user.checkPassword(login, pass))
        {
            isPasswordCorrect = true;
        }

        if(passAttemtsCounter == 3)
        {
            return false;
        }

        if(isPasswordCorrect==false)
        {
            cout << "Wrong password... You have "<< 3 - passAttemtsCounter << " more\n";
            passAttemtsCounter++;
        }

    } while (isPasswordCorrect != true);

    system("clear");
    cout << "Hello " << login << endl;
    cout << "You are logged in\n";

    setLogin(login);
    return true;
}