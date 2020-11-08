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
    menu.showMenu();

    int choice;
    cout << " Co wybierasz? " << endl;
    cin >> choice;

    switch (choice)
    {
    case 1:
        TcreateUser addUser;
        // Create new account.
        addUser.createUser();
        break;
    case 2:
        TcheckDetails checkDetails;
        checkDetails.updateAccountData();
        break;
    case 3:
        cout << "3" << endl;
        break;
    case 4:
        cout << "4" << endl;
        break;
    case 5:
        cout << "5" << endl;
        break;
    case 6:
        cout << "6" << endl;
        break;
    case 7:
        cout << "7" << endl;
        break;

    default:
        cout << "Missing option - try again!\n";
        break;
    }
}