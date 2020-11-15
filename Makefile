#Makefile

COMPILE_MAIN?="main"
COMPILE_MENU?="Tmenu"
SOURCES = Tmenu.cpp main.cpp TcreateUser.cpp TcheckDetails.cpp Tlogin.cpp dbConnection.cpp
SQLITE_COMPILE_LINUX = gcc -g -c sqlite3/sqlite3.c -o sqlite3/sqlite3.o
SQLITE_RUN_LINUX = sqlite3/sqlite3.o -I \sqlite3 -pthread -ldl

make linux:
	${SQLITE_COMPILE_LINUX}
	g++ ${SOURCES} ${SQLITE_RUN_LINUX} -o ${COMPILE_MAIN} -Wwrite-strings
	./${COMPILE_MAIN}

make win:



clean:
	rm -f ${COMPILE_MAIN}
	rm -f sqlite3/sqlite3.o
dump:
	g++ ${SOURCES}.cpp -S

