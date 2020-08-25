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
    const string nameFileWithUsers;
    //bool isFileEmpty();

public:
    FileWithUsers(string NAME_FILE_WITH_USERS) : nameFileWithUsers(NAME_FILE_WITH_USERS) {};
    vector <User> loadUsersFromFile();
    void addUserToFile(User user);

};

#endif
