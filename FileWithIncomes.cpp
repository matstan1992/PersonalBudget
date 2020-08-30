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
    xml.AddElem("Date", AuxiliaryMethods::conversionIntToString(income.getDate()));
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::conversionFloatToString(income.getAmount()));


    xml.Save(getFileName().c_str());
}
