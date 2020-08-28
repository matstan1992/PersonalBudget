#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

using namespace std;

class FileWithUsers : public XmlFile
{
public:
    FileWithUsers(string nameFileWithUsers) : XmlFile(nameFileWithUsers) {};
    vector <User> loadUsersFromFile();
    void addUserToFile(User user);
    void saveAllUsersToFile(vector <User> users);
};

#endif
