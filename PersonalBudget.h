#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>

#include "Markup.h"
#include "UserManager.h"
#include "BudgetManager.h"
//#include "DateManager.h"

using namespace std;

class PersonalBudget
{
    UserManager userManager;
    BudgetManager *budgetManager;
    //DateManager dateManager;
    const string NAME_FILE_WITH_INCOMES;
    const string NAME_FILE_WITH_EXPENSES;

public:
    PersonalBudget(string nameFileWithUsers, string nameFileWithIncomes, string nameFileWithExpenses)
        : userManager(nameFileWithUsers), NAME_FILE_WITH_INCOMES(nameFileWithIncomes), NAME_FILE_WITH_EXPENSES(nameFileWithExpenses)
    {
        budgetManager = NULL;
    };
    ~PersonalBudget()
    {
        delete budgetManager;
        budgetManager = NULL;
    };
    void userSignUp();
    void userSignIn();
    void logOutUser();
    void changePasswordSignedInUser();
    void showAllUsers();
    bool isUserSignedIn();

    char selectOptionFromTheMainMenu();
    char selectOptionFromTheUserMenu();

    void addIncome();
    void addExpense();
    void showBalanceFromCurrentMonth();
    void showBalanceFromPreviousMonth();
};

#endif
