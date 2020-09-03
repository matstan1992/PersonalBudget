#include "DateManager.h"

bool DateManager::isLeapYear(int year)
{
    return ((year%4==0 && year%100!=0) || year%400==0);
}

int DateManager::getCurrentDate()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    int date = 0;
    string dateString = "";
    string tmp = "";

    dateString = AuxiliaryMethods::conversionIntToString(getCurrentYear());
    tmp = AuxiliaryMethods::conversionIntToString(getCurrentMonth());

    if(tmp.length() == 1)
        tmp.insert(0, "0");
    dateString += tmp;

    tmp = AuxiliaryMethods::conversionIntToString(st.wDay);
    if(tmp.length() == 1)
        tmp.insert(0, "0");
    dateString += tmp;

    date = AuxiliaryMethods::conversionStringToInt(dateString);

    return date;
}

int DateManager::getCurrentMonth()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    return st.wMonth;
}

int DateManager::getCurrentYear()
{
    SYSTEMTIME st;
    GetSystemTime(&st);

    return st.wYear;
}

bool DateManager::isDateCorrect(string date)
{
    if(date.length() != 10 || date[4] != '-' || date[7] != '-')
    {
        return false;
    }
    string year = date.substr(0,4);
    string month = date.substr(5,2);
    string day = date.substr(8,2);

    int intYear = AuxiliaryMethods::conversionStringToInt(year);
    int intMonth = AuxiliaryMethods::conversionStringToInt(month);

    if(intYear < 2000 || intYear > getCurrentYear())
        return false;
    else
    {
        if(intMonth > getCurrentMonth())
            return false;
    }
    if(isLeapYear(intYear) && month == "02")
    {
        if(day >= "01" && day <= "29")
            return true;
        else
            return false;
    }
    else
    {
        if(month == "01" || month == "03" || month == "05" || month == "07" || month == "08" || month == "10" || month == "12")
        {
            if(day >= "01" && day <= "31")
                return true;
            else
                return false;
        }
        else if(month == "02")
        {
            if(day >= "01" && day <= "28")
                return true;
            else
                return false;
        }
        else if(month == "04" || month == "06" || month == "09" || month == "11")
        {
            if(day >= "01" && day <= "30")
                return true;
            else
                return false;
        }
        else
            return false;
    }
}

int DateManager::dateConversionStringToInt(string date)
{
    date.erase(4,1);
    date.erase(6,1);
    int intDate = AuxiliaryMethods::conversionStringToInt(date);
    return intDate;
}

string DateManager::dateConversionIntToString(int date)
{
    string stringDate = AuxiliaryMethods::conversionIntToString(date);
    stringDate.insert(4,"-");
    stringDate.insert(7,"-");
    return stringDate;
}
