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
    string nameFileWithUsers;
    //bool isFileEmpty();

public:
    FileWithUsers();
    vector <User> loadUsersFromFile();
    void addUserToFile(User user);

};

#endif
