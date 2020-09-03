#include "Income.h"

void Income::setUserId(int newUserId)
{
    userId = newUserId;
}

void Income::setIncomeId(int newId)
{
    incomeId = newId;
}

void Income::setDate(int newDate)
{
        date = newDate;
}

void Income::setItem(string newItem)
{
    item = newItem;
}

void Income::setAmount(float newAmount)
{
    amount = newAmount;
}

int Income::getUserId()
{
    return userId;
}

int Income::getIncomeId()
{
    return incomeId;
}

int Income::getDate()
{
    return date;
}

string Income::getItem()
{
    return item;
}

float Income::getAmount()
{
    return amount;
}
