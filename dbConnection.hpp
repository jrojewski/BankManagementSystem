#ifndef DBCONNECTION_HPP
#define DBCONNECTION_HPP

#include <string>
#include "sqlite3/sqlite3.h"

class TdbConnection
{

public:
    sqlite3* dbAccess();
    int checkUser(std::string);

};

#endif