#ifndef TUSERLOGGED_H
#define TUSERLOGGED_H

#include "TrunMenu.hpp"
#include "TshowMenu.hpp"


class TuserLogged
{

public:

    void checkCurrentBalance(std::string);
    int transactionType();

    void cashDeposit(std::string);
    void cashWithdraw();
    void cashTransfer();

};

#endif