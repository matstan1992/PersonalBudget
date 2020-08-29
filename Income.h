#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income
{
    int userId;
    int incomeId;
    int date;
    string item;
    float amount;

public:
    void setUserId(int newUserId);
    void setIncomeId(int newId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getUserId();
    int getIncomeId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif
