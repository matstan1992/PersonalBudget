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
        addIncomeWithDifferentDate();
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
    int todayDate = dateManager.getCurrentDate();

    income = enterDataForNewIncome(todayDate);

    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);

    cout << "Nowy przychod zostal dodany" << endl << endl;
    system("pause");
}

void BudgetManager::addIncomeWithDifferentDate()
{
    Income income;
    int differentDate = 0;
    string enterDate = "";

    cout << "Podaj date (rrrr-mm-dd): ";
    enterDate = AuxiliaryMethods::loadLine();

    if(!dateManager.isDateCorrect(enterDate))
    {
        cout << "Niewlasciwa data" << endl;
        system("pause");
        return;
    }
    else
        differentDate = dateManager.dateConversionStringToInt(enterDate);

    income = enterDataForNewIncome(differentDate);
    incomes.push_back(income);
    fileWithIncomes.addIncomeToFile(income);

    cout << "Nowy przychod zostal dodany" << endl << endl;
    system("pause");
}

Income BudgetManager::enterDataForNewIncome(int date)
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

void BudgetManager::addExpense()
{
    char choice;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;
    cout << "1. Dzisiejszy wydatek" << endl;
    cout << "2. Wydatek z inna data" << endl;
    cout << "3. Powrot" << endl;

    cout << endl << "Twoj wybor: ";

    choice = AuxiliaryMethods::loadCharacter();

    switch (choice)
    {
    case '1':
        addExpenseWithTodayDate();
        break;
    case '2':
        addExpenseWithDifferentDate();
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

void BudgetManager::addExpenseWithTodayDate()
{
    Expense expense;
    int todayDate = dateManager.getCurrentDate();

    expense = enterDataForNewExpense(todayDate);

    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);

    cout << "Nowy wydatek zostal dodany" << endl << endl;
    system("pause");
}

void BudgetManager::addExpenseWithDifferentDate()
{
    Expense expense;
    int differentDate = 0;
    string enterDate = "";

    cout << "Podaj date (rrrr-mm-dd): ";
    enterDate = AuxiliaryMethods::loadLine();

    if(!dateManager.isDateCorrect(enterDate))
    {
        cout << "Niewlasciwa data" << endl;
        system("pause");
        return;
    }
    else
    differentDate = dateManager.dateConversionStringToInt(enterDate);

    expense = enterDataForNewExpense(differentDate);
    expenses.push_back(expense);
    fileWithExpenses.addExpenseToFile(expense);

    cout << "Nowy wydatek zostal dodany" << endl << endl;
    system("pause");
}

Expense BudgetManager::enterDataForNewExpense(int date)
{
    Expense expense;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO WYDATKU <<<" << endl << endl;

    expense.setUserId(SIGNED_IN_USER_ID);
    expense.setExpenseId(retrieveNewExpenseId());
    expense.setDate(date);

    cout << "Nazwa wydatku: ";
    expense.setItem(AuxiliaryMethods::loadLine());

    cout << "Kwota wydatku: ";
    expense.setAmount(AuxiliaryMethods::loadFloatNumber());

    return expense;
}

int BudgetManager::retrieveNewExpenseId()
{
    return fileWithExpenses.retrieveLastExpenseId() + 1;
}

void BudgetManager::showExpenses()
{
    for (int i = 0; i < expenses.size(); i++)
    {
        cout << expenses[i].getUserId() << endl;
        cout << expenses[i].getExpenseId() << endl;
        cout << expenses[i].getDate() << endl;
        cout << expenses[i].getItem() << endl;
        cout << expenses[i].getAmount() << endl << endl;
    }
    system("pause");
}
