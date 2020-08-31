#ifndef BUDGETMANAGER_H
#define BUDGETMANAGER_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "Income.h"
#include "Expense.h"
#include "FileWithIncomes.h"
#include "FileWithExpenses.h"
#include "AuxiliaryMethods.h"

using namespace std;

class BudgetManager
{
    const int SIGNED_IN_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;
    FileWithIncomes fileWithIncomes;
    FileWithExpenses fileWithExpenses;

    Income enterDataForNewIncome(int date);
    Expense enterDataForNewExpense(int date);

    int retrieveNewIncomeId();
    int retrieveNewExpenseId();

public:
    BudgetManager(string nameFileWithIncomes, string nameFileWithExpenses, int signedInUserId) : fileWithIncomes(nameFileWithIncomes), fileWithExpenses(nameFileWithExpenses), SIGNED_IN_USER_ID(signedInUserId)
    {
        incomes = fileWithIncomes.loadIncomesFromFile(SIGNED_IN_USER_ID);
        expenses = fileWithExpenses.loadExpensesFromFile(SIGNED_IN_USER_ID);
    };
    void addIncome();
    void addIncomeWithTodayDate();
    void addIncomeWithDifferentDate();

    void addExpense();
    void addExpenseWithTodayDate();
    void addExpenseWithDifferentDate();
void showExpenses();
};

#endif