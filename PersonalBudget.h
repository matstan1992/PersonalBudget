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
    void userSignUp();
    void showAllUsers();

};

#endif
