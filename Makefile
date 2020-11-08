#Makefile

COMPILE_MAIN?="main"
COMPILE_MENU?="Tmenu"
SOURCES = Tmenu.cpp main.cpp TcreateUser.cpp TcheckDetails.cpp Tlogin.cpp dbConnection.cpp

main:
	g++ ${SOURCES} -o ${COMPILE_MAIN}
	./${COMPILE_MAIN}
clean:
	rm -f ${COMPILE_MAIN}

dump:
	g++ ${SOURCES}.cpp -S

