#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <algorithm>

#include "User.h"
#include "Markup.h"

/*
#include "UserManager.h"
#include "BudgetManager.h"
#include "DateManager.h"
*/
using namespace std;

class PersonalBudget
{
    int signedInUserId;

    vector <User> users;
    User getDataNewUser();
    int retrieveNewUserId();
    bool isLoginExist(string login);
    void addUserToFile(User user);
    string changeTheFirstLetterToUpperCaseAndTheRestToLowerCase (string text);
    //UserManager userManager;
    //BudgetManager budgetManager;
    //DateManager dateManager;

public:
    void userSignUp();
    void showAllUsers();

};

#endif
