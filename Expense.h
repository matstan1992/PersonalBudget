#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

#include "Income.h"

using namespace std;

class Expense : public Income
{
    int expenseId;

public:
    void setExpenseId(int newId);

    int getExpenseId();

};

#endif
