#include "FileWithIncomes.h"

void FileWithIncomes:: addIncomeToFile(Income income)
{
    CMarkup xml;

    bool fileExists = xml.Load(getFileName().c_str());

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("INCOMES");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("UserId", AuxiliaryMethods::conversionIntToString(income.getUserId()));
    xml.AddElem("IncomeId", AuxiliaryMethods::conversionIntToString(income.getIncomeId()));
    xml.AddElem("Date", DateManager::dateConversionIntToString(income.getDate()));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::conversionFloatToString(income.getAmount()));

    xml.Save(getFileName().c_str());
}

vector <Income> FileWithIncomes::loadIncomesFromFile(int signedInUserId)
{
    Income income;
    vector <Income> incomes;

    CMarkup xml;

    xml.Load(getFileName().c_str());

    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("UserId");
        if(AuxiliaryMethods::conversionStringToInt(xml.GetData()) == signedInUserId)
        {
            xml.FindElem("UserId");
            income.setUserId(AuxiliaryMethods::conversionStringToInt(xml.GetData()));
            xml.FindElem("IncomeId");
            income.setIncomeId(AuxiliaryMethods::conversionStringToInt(xml.GetData()));
            xml.FindElem("Date");
            income.setDate(DateManager::dateConversionStringToInt(xml.GetData()));
            xml.FindElem("Item");
            income.setItem(xml.GetData());
            xml.FindElem("Amount");
            income.setAmount(AuxiliaryMethods::conversionStringToFloat(xml.GetData()));

            incomes.push_back(income);
        }
        xml.OutOfElem();
    }

    return incomes;
}

int FileWithIncomes::retrieveLastIncomeId()
{
    int lastIncomeId = 0;
    CMarkup xml;

    bool fileExists = xml.Load(getFileName().c_str());

    if(!fileExists)
    {
        return 0;
    }

    xml.FindElem();
    xml.IntoElem();

    while (xml.FindElem("Income"))
    {
        xml.IntoElem();
        xml.FindElem("IncomeId");
        lastIncomeId = AuxiliaryMethods::conversionStringToInt(xml.GetData());
        xml.OutOfElem();
    }

    return lastIncomeId;
}
