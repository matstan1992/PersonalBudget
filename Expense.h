#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

#include "IncomeExpense.h"

using namespace std;

class Expense : public IncomeExpense
{
    int expenseId;

public:
    void setExpenseId(int newId);

    int getExpenseId();
};

#endif
