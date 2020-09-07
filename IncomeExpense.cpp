#include "IncomeExpense.h"

void IncomeExpense::setUserId(int newUserId)
{
    userId = newUserId;
}

void IncomeExpense::setDate(int newDate)
{
        date = newDate;
}

void IncomeExpense::setItem(string newItem)
{
    item = newItem;
}

void IncomeExpense::setAmount(float newAmount)
{
    amount = newAmount;
}

int IncomeExpense::getUserId()
{
    return userId;
}

int IncomeExpense::getDate()
{
    return date;
}

string IncomeExpense::getItem()
{
    return item;
}

float IncomeExpense::getAmount()
{
    return amount;
}
