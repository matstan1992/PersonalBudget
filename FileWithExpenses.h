#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>

#include "Expense.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"
#include "XmlFile.h"

using namespace std;

class FileWithExpenses : public XmlFile
{
    public:
    FileWithExpenses(string nameFileWithExpenses) : XmlFile(nameFileWithExpenses) {};
    vector <Expense> loadExpensesFromFile(int signedInUserId);
    void addExpenseToFile(Expense expense);
    int retrieveLastExpenseId();
};

#endif
