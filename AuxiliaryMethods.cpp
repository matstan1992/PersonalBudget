#include "AuxiliaryMethods.h"

string AuxiliaryMethods::changeTheFirstLetterToUpperCaseAndTheRestToLowerCase(string text)
{
    if (!text.empty())
    {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

string AuxiliaryMethods::conversionIntToString(int number)
{
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::conversionStringToInt(string number)
{
    int numberInt;
    istringstream iss(number);
    iss >> numberInt;

    return numberInt;
}

float AuxiliaryMethods::loadFloatNumber()
{
    float number = 0;
    string input = "";

    getline(cin, input);

    if(input.find(',') !=string::npos)
        input.replace(input.find(','), 1, ".");

    number = atof(input.c_str());

    return number;
}

string AuxiliaryMethods::loadLine()
{
    string input = "";
    getline(cin, input);
    return input;
}

char AuxiliaryMethods::loadCharacter()
{
    string input = "";
    char character  = {0};

    while (true)
    {
        getline(cin, input);

        if (input.length() == 1)
        {
            character = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return character;
}

string AuxiliaryMethods::conversionFloatToString(float number)
{
    stringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

float AuxiliaryMethods::conversionStringToFloat(string number)
{
    return atof(number.c_str());
}
