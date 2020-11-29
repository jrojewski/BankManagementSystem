#ifndef DBCONNECTION_HPP
#define DBCONNECTION_HPP

#include <string>
#include "sqlite3/sqlite3.h"

class dbConnection
{
    // Pointer to SQLite connection
    sqlite3 *db;

    // Save any error messages
    char *zErrMsg;

    // Save the result of opening the file
    int resultCode;

    // Saved SQL
    const char* sql;

    // Compiled SQLite Statement
    sqlite3_stmt *stmt;

    // Create a callback function
	static int callback(void* , int , char **, char **);

	void checkDBErrors();


public:
	dbConnection();
	void addUser(std::string, std::string);
    bool findUser(std::string);
	void closeDB();
    //bool checkIfUserExist(std::string);

};

#endif