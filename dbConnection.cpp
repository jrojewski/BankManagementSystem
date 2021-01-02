#include <iostream>
#include <string>
#include <stdio.h>
#include "dbConnection.hpp"
#include "sqlite3/sqlite3.h"
//#include <curses.h>

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

void dbConnection::addUser(string firstName,string lastName, string login, string password) {

	string sql = "INSERT INTO users ('FirstName', 'LastName', 'Login', 'Password') VALUES ('";
	sql.append(firstName);
	sql.append("', '");
	sql.append(lastName);
	sql.append("', '");
	sql.append(login);
	sql.append("', '");
	sql.append(password);
	sql.append("');");
	cout << sql << endl; //debugString

	sqlite3_prepare_v2(db, sql.c_str(), sql.length(), &stmt, NULL);

	resultCode = sqlite3_step(stmt);

	sqlite3_finalize(stmt);
}

bool dbConnection::findUser(string login) {

	string query =  "SELECT * FROM users WHERE Login='" + login + "' ";
	resultCode = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);

	if(resultCode == SQLITE_OK)
    {
       if (sqlite3_step(stmt) == SQLITE_ROW)
       {
          cout << "Record found" << endl;
       }
       else
       {
          cout << "Record not found" << endl;
          sqlite3_finalize(stmt);
		  return false;
       }
    }
    sqlite3_finalize(stmt);
	return true;
}

bool dbConnection::checkUsersPassword(string login, string pass){

	cout << "Login: " << login << endl;
    cout << "Pass: " << pass << endl;

    string query =  "SELECT * FROM users WHERE Login='" + login + "' AND Password = '"+ pass + "'";
	resultCode = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);

    cout << "Result: " <<  resultCode << endl;
	if(resultCode == SQLITE_OK)
    {
       if (sqlite3_step(stmt) == SQLITE_ROW)
       {
            cout << "Password record found" << endl;
            printf("Password record found  <%s:%d>", __FUNCTION__ , __LINE__);
       }
       else
       {
            printf("Password not match: login:%s password = %s <%s:%d>\n", login,  pass, __FUNCTION__, __LINE__);
		    return false;
       }
    }
    sqlite3_finalize(stmt);
	return true;

}

double dbConnection::checkCurrentBalance(string login){

	string balance =  "SELECT Balance FROM users WHERE Login='" + login + "' ";
	resultCode = sqlite3_prepare_v2(db, balance.c_str(), balance.length(), &stmt, NULL);

	if(resultCode != SQLITE_OK)
    {
        printf("Something went wrong...<File:%s, Fun:%s, Line:%d>", __FILE__, __FUNCTION__, __LINE__);
        return -1;
    }

    if (sqlite3_step(stmt) == SQLITE_ROW)
    {
        int bal = sqlite3_column_int(stmt, 0);
        sqlite3_finalize(stmt);
        return (double)bal;
    }

    return -1;
}


double dbConnection::depositCash(double cash){


}

void dbConnection::closeDB() {

	// Close the SQL connection
    sqlite3_close(db);

}