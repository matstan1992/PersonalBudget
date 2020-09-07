#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdlib>

using namespace std;

class AuxiliaryMethods
{
public:
    static string changeTheFirstLetterToUpperCaseAndTheRestToLowerCase(string text);
    static string conversionIntToString(int number);
    static int conversionStringToInt(string number);
    static float loadFloatNumber();
    static string loadLine();
    static char loadCharacter();
    static string conversionFloatToString(float number);
    static float conversionStringToFloat(string number);
};

#endif
