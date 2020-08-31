#include "BudgetManager.h"

void BudgetManager::addIncome()
{
    char choice;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;
    cout << "1. Dzisiejszy przychod" << endl;
    cout << "2. Przychod z inna data" << endl;
    cout << "3. Powrot" << endl;

    cout << endl << "Twoj wybor: ";

    choice = AuxiliaryMethods::loadCharacter();

    switch (choice)
    {
    case '1':
        addIncomeWithTodayDate();
        break;
    case '2':
//        addIncomeWithDifferentDate();
        break;
    case '3':
        return;
        break;
    default:
        cout << "Nie ma takiej opcji";
        system("pause");
        break;
    }
}

void BudgetManager::addIncomeWithTodayDate()
{
    Income income;
    int todayDate = 20200825; //dateManager

    income = enterDataForNewPosition(todayDate);

    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);

    cout << "Nowy przychod zostal dodany" << endl << endl;
    system("pause");
}
/*
void BudgetManager::addIncomeWithDifferentDate()
{
    Income income;
    int differentDate = 0;
    string enterDate = "";

    cout << "Podaj date (rrrr-mm-dd): ";
    enetrDate = AuxiliaryMethods::loadLine();

    dateManager.dateIsCorrect(enterDate)
    differentDate = dateManager.convertDate
    income = enterDataForNewPosition(differentDate);

    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);

    cout << "Nowy przychod zostal dodany" << endl << endl;
    system("pause");
}

/*
void BudgetManager::addExpense()
{
    IncomeExpense expense;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    expense = enterDataForNewPosition();

    expenses.push_back(expense);
    //fileWithExpenses.addNewPositionToFile(expense);

    cout << "Nowy wydatek zostal dodany" << endl << endl;
    system("pause");
}
*/
Income BudgetManager::enterDataForNewPosition(int date)
{
    Income income;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO PRZYCHODU <<<" << endl << endl;

    income.setUserId(SIGNED_IN_USER_ID);
    income.setIncomeId(retrieveNewIncomeId());
    income.setDate(date);

    cout << "Nazwa przychodu: ";
    income.setItem(AuxiliaryMethods::loadLine());

    cout << "Kwota przychodu: ";
    income.setAmount(AuxiliaryMethods::loadFloatNumber());

    return income;
}

int BudgetManager::retrieveNewIncomeId()
{
    return fileWithIncomes.retrieveLastIncomeId() + 1;
}
void BudgetManager::showIncomes()
{
    for (int i = 0; i < incomes.size(); i++)
    {
        cout << incomes[i].getUserId() << endl;
        cout << incomes[i].getIncomeId() << endl;
        cout << incomes[i].getDate() << endl;
        cout << incomes[i].getItem() << endl;
        cout << incomes[i].getAmount() << endl;
    }
    system("pause");
}
