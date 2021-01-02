#Makefile

COMPILE_MAIN?="bin/main"
COMPILE_MENU?="Tmenu"
SQL_O ="bin/sqlite3.o"
COMPILE_SQL = "include/sqlite3/sqlite3.c"
SOURCES = src/TshowMenu.cpp src/main.cpp src/TcreateUser.cpp src/TcheckDetails.cpp src/Tlogin.cpp src/dbConnection.cpp src/TuserLogged.cpp src/TrunMenu.cpp
SQLITE_COMPILE_LINUX = gcc -g -c ${COMPILE_SQL} -o bin/sqlite3.o
SQLITE_COMPILE_WIN = gcc ${COMPILE_SQL} -c -o bin/sqlite3.o
SQLITE_RUN_LINUX = bin/sqlite3.o -I \sqlite3 -pthread -ldl
SQLITE_RUN_WIN = ${SQL_O} -I \sqlite3

make linux:
	${SQLITE_COMPILE_LINUX}
	g++ ${SOURCES} ${SQLITE_RUN_LINUX} -o ${COMPILE_MAIN} -Wwrite-strings
	./${COMPILE_MAIN}

make win:
	${SQLITE_COMPILE_WIN}
	g++ ${SOURCES} ${SQLITE_RUN_WIN} -o ${COMPILE_MAIN}
	./${COMPILE_MAIN}

clean:
	rm -f ${COMPILE_MAIN}
	rm -f ${SQL_O}
dump:
	g++ ${SOURCES}.cpp -S

