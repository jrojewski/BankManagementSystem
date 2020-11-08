#include "dbConnection.hpp"
#include <iostream>
#include "sqlite3/sqlite3.h"
#include <string>

using namespace std;

sqlite3* TdbConnection::dbAccess() {
    static sqlite3* db;
    char *ErrorMsg = 0;
    int resultCode;

    resultCode = sqlite3_open("database/dbBank.db", &db);

    if (resultCode) {
        cout << "DB Error " << resultCode << ": " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);
        return NULL;
    } else {
        cout << "DB Access Granted" << endl;
        return db;
    }
}