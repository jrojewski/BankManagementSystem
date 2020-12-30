#ifndef TUSERLOGGED_H
#define TUSERLOGGED_H

#include "TrunMenu.hpp"
#include "TshowMenu.hpp"


class TuserLogged
{

    TshowMenu showMenu;
    TrunMenu runMenu;

public:
    TuserLogged(){
        showMenu.showLoggedMenu();
        runMenu.runUserLoggedMenu();
    }

};

#endif