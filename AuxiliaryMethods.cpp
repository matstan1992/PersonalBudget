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
