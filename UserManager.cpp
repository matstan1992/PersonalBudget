#include "UserManager.h"

void UserManager::userSignUp()
{
    User user = getDataNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::getDataNewUser()
{
    User user;

    user.setId(retrieveNewUserId());

    cout << "Podaj imie: ";
    user.setName(AuxiliaryMethods::loadLine());
    user.setName(AuxiliaryMethods::changeTheFirstLetterToUpperCaseAndTheRestToLowerCase(user.getName()));

    cout << "Podaj nazwisko: ";
    user.setSurname(AuxiliaryMethods::loadLine());
    user.setSurname(AuxiliaryMethods::changeTheFirstLetterToUpperCaseAndTheRestToLowerCase(user.getSurname()));

    do
    {
        cout << "Podaj login: ";
        user.setLogin(AuxiliaryMethods::loadLine());
    }
    while (isLoginExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    user.setPassword(AuxiliaryMethods::loadLine());

    return user;
}

int UserManager::retrieveNewUserId()
{
    if (users.empty() == true)
        return 1;
    else
        return users.back().getId() + 1;
}

bool UserManager::isLoginExist(string login)
{
    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::showAllUsers()
{
    for (int i = 0; i < users.size(); i++)
    {
        cout << users[i].getId() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
    }
}

void UserManager::loadUsersFromFile()
{
    users = fileWithUsers.loadUsersFromFile();
}
