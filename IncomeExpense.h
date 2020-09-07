#ifndef INCOMEEXPENSE_H
#define INCOMEEXPENSE_H

#include <iostream>

using namespace std;

class IncomeExpense
{
    int userId;
    int date;
    string item;
    float amount;

public:
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(float newAmount);

    int getUserId();
    int getDate();
    string getItem();
    float getAmount();
};

#endif
