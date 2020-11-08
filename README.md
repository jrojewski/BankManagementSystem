ReadMe

SQLITE3
Compile with this command:

#WINDOWS
g++ Tmenu.cpp main.cpp TcreateUser.cpp TcheckDetails.cpp Tlogin.cpp dbConnection.cpp sqlite3/sqlite3.o -I \sqlite3  -o "main"

#LINUX
gcc -g -c sqlite3.c -o sqlite3.o
g++ Tmenu.cpp main.cpp TcreateUser.cpp TcheckDetails.cpp Tlogin.cpp dbConnection.cpp sqlite3/sqlite3.o -I \sqlite3 -pthread -ldl -o "main"