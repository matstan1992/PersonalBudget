#ifndef INCOME_H
#define INCOME_H

#include <iostream>

#include "IncomeExpense.h"

using namespace std;

class Income : public IncomeExpense
{
    int incomeId;

public:
    void setIncomeId(int newId);

    int getIncomeId();
};

#endif
