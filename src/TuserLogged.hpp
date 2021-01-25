#ifndef TUSERLOGGED_H
#define TUSERLOGGED_H

#include "TrunMenu.hpp"
#include "TshowMenu.hpp"


class TuserLogged
{

public:

    void checkCurrentBalance(std::string);
    void transactionType();

    void cashDeposit(std::string, int=0);
    void cashWithdraw();
    void cashTransfer();

};

#endif