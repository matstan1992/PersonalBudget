#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetManager
{
    const int SIGNED_IN_USER_ID;
    vector <Income> incomes;
    Income enterDataForNewPosition(int date);
    int retrieveNewIncomeId();

public:
    BudgetManager(int signedInUserId) : SIGNED_IN_USER_ID(signedInUserId) {};
    void addIncome();
    void addIncomeWithTodayDate();
    void addIncomeWithDifferentDate();

};

#endif
