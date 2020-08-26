#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileWithUsers
{
    const string NAME_FILE_WITH_USERS;
    //bool isFileEmpty();

public:
    FileWithUsers(string nameFileWithUsers) : NAME_FILE_WITH_USERS(nameFileWithUsers) {};
    vector <User> loadUsersFromFile();
    void addUserToFile(User user);
    void saveAllUsersToFile(vector <User> users);
};

#endif
