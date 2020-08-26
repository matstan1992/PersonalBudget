#include "UserManager.h"

void UserManager::userSignUp()
{
    User user = getDataNewUser();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

void UserManager::userSignIn()
{
    User user;
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    signedInUserId = itr -> getId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

void UserManager::logOutUser()
{
    signedInUserId = 0;
}

void UserManager::changePasswordSignedInUser()
{
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLine();

    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++)
    {
        if (itr -> getId() == signedInUserId)
        {
            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.saveAllUsersToFile(users);
}

User UserManager::getDataNewUser()
{
    User user;

    system("cls");

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

bool UserManager::isUserSignedIn()
{
    if(signedInUserId > 0)
        return true;
    else
        return false;
}
