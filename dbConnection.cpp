#include <iostream>
#include <string>
#include <stdio.h>
#include "dbConnection.hpp"
#include "sqlite3/sqlite3.h"
//#include <curses.h>
#include <stdio.h>

using namespace std;

int dbConnection::callback(void *NotUsed, int argc, char **argv, char **azColName) {

	// int argc: holds the number of results
	// (array) azColName: holds each column returned
	// (array) argv: holds each value

	for(int i = 0; i < argc; i++) {

	    //column name, value, and newline
	    cout << azColName[i] << ": " << argv[i] << endl;
	}

	// Insert a newline
	cout << endl;

	// Return successful
	return 0;
}

void dbConnection::checkDBErrors() {
	if( resultCode ){
        // Show an error message
        cout << "DB Error: " << sqlite3_errmsg(db) << endl;
        dbConnection::closeDB();
    }
}

dbConnection::dbConnection(){

    // Save the result of opening the file
    resultCode = sqlite3_open("database/dbBank.db", &db);
    checkDBErrors();
    cout << "Database connected\n";

}

void dbConnection::addUser(string login,string password) {
	
	string sql = "INSERT INTO test ('login', 'pass') VALUES ('";
	sql.append(login);
	sql.append("', '");
	sql.append(password);
	sql.append("');");
	cout << sql << endl; //debugString

	sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, NULL);

	resultCode = sqlite3_step(stmt);

	sqlite3_finalize(stmt); 
}

void dbConnection::closeDB() {

	// Close the SQL connection
    sqlite3_close(db);

}