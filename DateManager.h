#ifndef DATEMANAGER_H
#define DATEMANAGER_H

#include <iostream>
#include <windows.h>
#include <winbase.h>

#include "AuxiliaryMethods.h"

using namespace std;

class DateManager
{
public:
    bool isLeapYear(int year);
    bool isDateCorrect(string date);
    int getCurrentDate();
    int getCurrentMonth();
    int getCurrentYear();
    static int dateConversionStringToInt(string date);
    static string dateConversionIntToString(int date);
};

#endif
