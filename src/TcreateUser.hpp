#ifndef TCREATEUSER_HPP
#define TCREATEUSER_HPP

#include <string>

class TcreateUser
{
public:

    bool checkIfUserExist(std::string);
    bool checkPassword(std::string, std::string);
    void createUser();
    void showUserNameSurname(std::string);

};

#endif


