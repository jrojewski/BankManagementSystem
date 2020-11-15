#include <iostream>
#include <string.h>
#include "dbConnection.hpp"
#include "sqlite3/sqlite3.h"
#include "sqlite3.h"
#include <curses.h>
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
	if( rc ){
        // Show an error message
        cout << "DB Error: " << sqlite3_errmsg(db) << endl;
        dbConnection::closeDB();
    }
}

dbConnection::dbConnection(){

    // Save the result of opening the file
    rc = sqlite3_open("database/dbBank.db", &db);
    checkDBErrors();
    cout << "Database connected\n";

}

void dbConnection::createTable() {

    // Save SQL to create a table
    //sql = "CREATE TABLE PEOPLE (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL);";
    // Run the SQL
    rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
}

void dbConnection::insertData(char* ID, char* name) {

	char *query = NULL;

	// Build a string using asprintf()
	asprintf(&query, "INSERT INTO PEOPLE ('ID', 'NAME') VALUES  ('%s', '%s');", ID, name);
	// Prepare the query
    sqlite3_prepare(db, query, strlen(query), &stmt, NULL);
    // Test it
	rc = sqlite3_step(stmt);
	// Finialize the usage
	sqlite3_finalize(stmt);
	// Free up the query space
	free(query);
}

void dbConnection::showTable() {
	//sql changed - LZ
	// Save SQL insert data
  	sql = "SELECT * FROM users";

	// Run the SQL
	rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
}

// to rework - not working yet - dont use
bool dbConnection::checkIfUserExist(string login){

	string query = "SELECT * FROM users WHERE login="+login;

	int n = query.length();
	char query_array[n + 1];
    strcpy(query_array, query.c_str());

	if(rc = sqlite3_exec(db, query_array, callback, 0, &zErrMsg)){
		return true;
	}

	return false;
}

void dbConnection::deleteRow(char* ID) {

	char *query = NULL;

	// Build a string using asprintf()
	asprintf(&query, "DELETE FROM 'PEOPLE' WHERE ID = '%s';", ID);

	// Prepare the query
    sqlite3_prepare(db, query, strlen(query), &stmt, NULL);

    // Test it
	rc = sqlite3_step(stmt);

	// Finialize the usage
	sqlite3_finalize(stmt);

	// Free up the query space
	free(query);
}

void dbConnection::closeDB() {

	// Close the SQL connection
    sqlite3_close(db);

}