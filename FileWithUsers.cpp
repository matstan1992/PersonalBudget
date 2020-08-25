#include "FileWithUsers.h"

void FileWithUsers::addUserToFile(User user)
{
    CMarkup xml;

    bool fileExists = xml.Load(nameFileWithUsers);

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getId());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());


    xml.Save(nameFileWithUsers);
}

vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector <User> users;

    CMarkup xml;

    xml.Load(nameFileWithUsers);

    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("User"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        user.setId(AuxiliaryMethods::conversionStringToInt(xml.GetData()));
        xml.FindElem("Name");
        user.setName(xml.GetData());
        xml.FindElem("Surname");
        user.setSurname(xml.GetData());
        xml.FindElem("Login");
        user.setLogin(xml.GetData());
        xml.FindElem("Password");
        user.setPassword(xml.GetData());
        xml.OutOfElem();

        users.push_back(user);
    }
    return users;
}
