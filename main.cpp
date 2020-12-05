/*
* Bank Managment System 
* Project for developing own skills and...
* To have fun
*/

#include <iostream>
#include "Tmenu.hpp"
#include "TcreateUser.hpp"
#include "TcheckDetails.hpp"
#include "dbConnection.hpp"
#include "Tlogin.hpp"

using namespace std;
/***********************************/
void runMenu();
/***********************************/

int main() {

    runMenu();

    return 0;
}

void runMenu(){

    Tmenu menu;
    menu.mainMenu();

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        //Log in
        Tlogin login;
        if(login.login())
        {
            menu.loggedMenu();
        }
        break;
    case 2:
        //Sign up
        TcreateUser addUser;
        addUser.createUser();
        // TcheckDetails checkDetails;
        // checkDetails.updateAccountData();
        break;
    case 3:
        cout << "Program closed." << endl;
        break;
    default:
        cout << "Missing option - try again!\n";
        break;
    }
}