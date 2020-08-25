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

    string name;
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);
    user.setName(AuxiliaryMethods::changeTheFirstLetterToUpperCaseAndTheRestToLowerCase(user.getName()));

    string surname;
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);
    user.setSurname(AuxiliaryMethods::changeTheFirstLetterToUpperCaseAndTheRestToLowerCase(user.getSurname()));

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    }
    while (isLoginExist(user.getLogin()) == true);

    string password;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);

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

