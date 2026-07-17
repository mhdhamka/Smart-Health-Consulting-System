#ifndef BOOL_H
#define BOOL_H

#include <string>

bool checkExistUsername(const std::string& username);

bool checkEmail(const std::string& email);

bool checkMobile(std::string input, int size);

bool validateLogin(std::string username, std::string password);

#endif



