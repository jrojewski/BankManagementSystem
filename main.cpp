/*
* Bank Managment System 
* Project for developing own skills and...
* To have fun
*/

#include <iostream>
#include "Tmenu.hpp"

using namespace std;

void runMenu();


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
        cout << "1" << endl;
        break;
    case 2:
        cout << "2" << endl;
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