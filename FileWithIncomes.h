#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"
#include "DateManager.h"

using namespace std;

class FileWithIncomes : public XmlFile
{
public:
    FileWithIncomes(string nameFileWithIncomes) : XmlFile(nameFileWithIncomes) {};
    vector <Income> loadIncomesFromFile(int signedInUserId);
    void addIncomeToFile(Income income);
    int retrieveLastIncomeId();
};

#endif
