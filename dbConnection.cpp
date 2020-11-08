#include <iostream>
#include <string>
#include "dbConnection.hpp"
#include "sqlite3/sqlite3.h"
#include "sqlite3.h"
#include <curses.h>

using namespace std;


int callback_Select(void *NotUsed, int argc, char **argv, char **azColName){
    for( int i = 0; i < argc; ++i ) {
        cout << azColName[i] << ": " << argv[i] << endl;
    }

    return 0;
}

sqlite3* TdbConnection::dbAccess() {
    static sqlite3* db;
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

int TdbConnection::checkUser(string login){

    // Pointer to SQLite connection
    sqlite3* db;
    char *zErrMsg = 0;
    int rc;
    string sql;

    // Save the connection result
    rc = sqlite3_open("database/dbBank.db", &db);

    // Test if there was an error
    if (rc) {

        cout << "DB Error: " << sqlite3_errmsg(db) << endl;
        sqlite3_close(db);

        return (1);
    } else {

        cout << "Opened Database Successfully!" << endl;
    }

    cout << "Wpisz zapytanie SQL: ";
    sql = "SELECT * FROM users WHERE login ='" +login+"'";
    // getline (check, sql);
    cout << sql << endl;

    rc = sqlite3_exec(db, sql.c_str(), callback_Select, 0, &zErrMsg);

    cout << "Dane wyswietlone!";

    // _getch();
    return (0);
}