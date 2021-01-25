#ifndef TLOGIN_HPP
#define TLOGIN_HPP

#include <string>


class Tlogin
{

public:

    void setLogin(std::string l);
    std::string getLogin();
    bool login();
    std::string returnLoggedUser(std::string);
};

#endif


