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
    UserManager(string nameFileWithUsers) : fileWithUsers(nameFileWithUsers)
    {
        signedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    void userSignUp();
    void userSignIn();
    void logOutUser();
    void changePasswordSignedInUser();
    void showAllUsers();
    bool isUserSignedIn();
    int retrieveSignedInUserId();
};

#endif
