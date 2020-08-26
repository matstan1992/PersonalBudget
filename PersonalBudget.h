#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>
#include <windows.h>

#include "Markup.h"
#include "UserManager.h"/*
#include "BudgetManager.h"
#include "DateManager.h"
*/
using namespace std;

class PersonalBudget
{
    UserManager userManager;
    //BudgetManager budgetManager;
    //DateManager dateManager;

public:
    PersonalBudget(string nameFileWithUsers) : userManager(nameFileWithUsers)
    {};
    void userSignUp();
    void userSignIn();
    void showAllUsers();
    bool isUserSignedIn();

    char selectOptionFromTheMainMenu();
    char selectOptionFromTheUserMenu();

};

#endif
