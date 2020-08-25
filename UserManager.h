#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int signedInUserId;
    vector <User> users;
    FileWithUsers fileWithUsers;

    User getDataNewUser();
    int retrieveNewUserId();
    bool isLoginExist(string login);

public:
    UserManager(string fileWithUsers) : fileWithUsers(fileWithUsers)
    {};
    void loadUsersFromFile();
    void userSignUp();
    void showAllUsers();
};
#endif
