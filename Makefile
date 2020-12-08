#Makefile

COMPILE_MAIN?="main"
COMPILE_MENU?="Tmenu"
SOURCES = TshowMenu.cpp main.cpp TcreateUser.cpp TcheckDetails.cpp Tlogin.cpp dbConnection.cpp TuserLogged.cpp TrunMenu.cpp
SQLITE_COMPILE_LINUX = gcc -g -c sqlite3/sqlite3.c -o sqlite3/sqlite3.o
SQLITE_COMPILE_WIN = gcc sqlite3/sqlite3.c -c -o sqlite3/sqlite3.o
SQLITE_RUN_LINUX = sqlite3/sqlite3.o -I \sqlite3 -pthread -ldl
SQLITE_RUN_WIN = sqlite3/sqlite3.o -I \sqlite3

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
	rm -f sqlite3/sqlite3.o
dump:
	g++ ${SOURCES}.cpp -S

