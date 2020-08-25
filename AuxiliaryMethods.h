#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <algorithm>
#include <sstream>

using namespace std;

class AuxiliaryMethods
{
public:
    static string changeTheFirstLetterToUpperCaseAndTheRestToLowerCase (string text);
    static string conversionIntToString(int number);
    static int conversionStringToInt(string number);
    static string downloadNumber(string text, int characterPosition);
    static string loadLine();
    static char loadCharacter();
    static string conversionFloatToString(float number);
    static int loadInteger();
};

#endif
