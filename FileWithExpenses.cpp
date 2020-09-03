#include "FileWithExpenses.h"

void FileWithExpenses:: addExpenseToFile(Expense expense)
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName().c_str());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("EXPENSES");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("UserId", AuxiliaryMethods::conversionIntToString(expense.getUserId()));
    xml.AddElem("ExpenseId", AuxiliaryMethods::conversionIntToString(expense.getExpenseId()));
    xml.AddElem("Date", DateManager::dateConversionIntToString(expense.getDate()));
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::conversionFloatToString(expense.getAmount()));

    xml.Save(getFileName().c_str());
}

vector <Expense> FileWithExpenses::loadExpensesFromFile(int signedInUserId)
{
    Expense expense;
    vector <Expense> expenses;

    CMarkup xml;

    xml.Load(getFileName().c_str());

    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        if(AuxiliaryMethods::conversionStringToInt(xml.GetData()) == signedInUserId)
        {
            xml.FindElem("UserId");
            expense.setUserId(AuxiliaryMethods::conversionStringToInt(xml.GetData()));
            xml.FindElem("ExpenseId");
            expense.setExpenseId(AuxiliaryMethods::conversionStringToInt(xml.GetData()));
            xml.FindElem("Date");
            expense.setDate(DateManager::dateConversionStringToInt(xml.GetData()));
            xml.FindElem("Item");
            expense.setItem(xml.GetData());
            xml.FindElem("Amount");
            expense.setAmount(AuxiliaryMethods::conversionStringToFloat(xml.GetData()));

            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }

    return expenses;
}

int FileWithExpenses::retrieveLastExpenseId()
{
    int lastExpenseId = 0;
    CMarkup xml;

    bool fileExists = xml.Load(getFileName().c_str());

    if(!fileExists)
    {
        return 0;
    }

    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Expense"))
    {
        xml.IntoElem();
        xml.FindElem("ExpenseId");
        lastExpenseId = AuxiliaryMethods::conversionStringToInt(xml.GetData());
        xml.OutOfElem();
    }

    return lastExpenseId;
}
