#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include <vector>

#include "User.h"
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
    //UserManager userManager;
    //BudgetManager budgetManager;
    //DateManager dateManager;

public:
    void userSignUp();

};

#endif
