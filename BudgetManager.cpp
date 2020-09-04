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

void BudgetManager::showBalanceFromCurrentMonth()
{
    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    system("cls");
    cout << " >>> TWOJE PRZYCHODY W TYM MIESIACU <<<" << endl << endl;

    for(vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if((dateManager.extractMonth(DateManager::dateConversionIntToString(itr -> getDate())) == dateManager.getCurrentMonth()) && (dateManager.extractYear(DateManager::dateConversionIntToString(itr -> getDate())) == dateManager.getCurrentYear()))
        {
        showIncomes(*itr);
        sumOfIncomes += itr -> getAmount();
        }
    }

    if(sumOfIncomes == 0)
    {
        cout << "Nie masz zadnych przychodow w tym miesiacu. " << endl << endl;
    }
    else
        cout << endl << "Suma Twoich przychodow w tym miesiacu wynosi: " << sumOfIncomes << endl << endl;


    cout << endl << " >>> TWOJE WYDATKI W TYM MIESIACU <<<" << endl << endl;

    for(vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if((dateManager.extractMonth(DateManager::dateConversionIntToString(itr -> getDate())) == dateManager.getCurrentMonth()) && (dateManager.extractYear(DateManager::dateConversionIntToString(itr -> getDate())) == dateManager.getCurrentYear()))
        {
        showExpenses(*itr);
        sumOfExpenses += itr -> getAmount();
        }
    }

    if(sumOfExpenses == 0)
    {
        cout << "Nie masz zadnych wydatkow w tym miesiacu. " << endl << endl;
    }
    else
        cout << endl << "Suma Twoich wydatkow w tym miesiacu wynosi: " << sumOfExpenses << endl << endl;

    if((sumOfIncomes != 0 || sumOfExpenses != 0) && (sumOfIncomes > sumOfExpenses))
        cout << endl << "Twoj zysk w biezacym miesiacu wynosi: " << sumOfIncomes - sumOfExpenses << endl << endl;
    else if((sumOfIncomes != 0 || sumOfExpenses != 0) && (sumOfIncomes < sumOfExpenses))
        cout << endl << "Twoja strata w biezacym miesiacu wynosi: " << sumOfIncomes - sumOfExpenses << endl << endl;

    system("pause");
}

void BudgetManager::showBalanceFromPreviousMonth()
{
    float sumOfIncomes = 0;
    float sumOfExpenses = 0;

    system("cls");
    cout << " >>> TWOJE PRZYCHODY W POPRZEDNIM MIESIACU <<<" << endl << endl;

    for(vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if((dateManager.extractMonth(DateManager::dateConversionIntToString(itr -> getDate())) == (dateManager.getCurrentMonth() - 1)) && (dateManager.extractYear(DateManager::dateConversionIntToString(itr -> getDate())) == dateManager.getCurrentYear()))
        {
        showIncomes(*itr);
        sumOfIncomes += itr -> getAmount();
        }
    }

    if(sumOfIncomes == 0)
    {
        cout << "Nie bylo zadnych przychodow w poprzednim miesiacu. " << endl << endl;
    }
    else
        cout << endl << "Suma Twoich przychodow w poprzednim miesiacu wynosila: " << sumOfIncomes << endl << endl;


    cout << endl << " >>> TWOJE WYDATKI W POPRZEDNIM MIESIACU <<<" << endl << endl;

    for(vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if((dateManager.extractMonth(DateManager::dateConversionIntToString(itr -> getDate())) == (dateManager.getCurrentMonth() - 1)) && (dateManager.extractYear(DateManager::dateConversionIntToString(itr -> getDate())) == dateManager.getCurrentYear()))
        {
        showExpenses(*itr);
        sumOfExpenses += itr -> getAmount();
        }
    }

    if(sumOfExpenses == 0)
    {
        cout << "Nie bylo zadnych wydatkow w poprzednim miesiacu. " << endl << endl;
    }
    else
        cout << endl << "Suma Twoich wydatkow w poprzednim miesiacu wynosila: " << sumOfExpenses << endl << endl;

    if((sumOfIncomes != 0 || sumOfExpenses != 0) && (sumOfIncomes > sumOfExpenses))
        cout << endl << "Twoj zysk w poprzednim miesiacu wynosil: " << sumOfIncomes - sumOfExpenses << endl << endl;
    else if((sumOfIncomes != 0 || sumOfExpenses != 0) && (sumOfIncomes < sumOfExpenses))
        cout << endl << "Twoja strata w poprzednim miesiacu wynosila: " << sumOfIncomes - sumOfExpenses << endl << endl;

    system("pause");
}

void BudgetManager::showIncomes(Income income)
{
    cout << "ID Przychodu: " << income.getIncomeId() << " Data: " << DateManager::dateConversionIntToString(income.getDate()) << " Kwota: " << income.getAmount() << " Nazwa: " << income.getItem() << endl;
}

void BudgetManager::showExpenses(Expense expense)
{
    cout << "ID Wydatku: " << expense.getIncomeId() << " Data: " << DateManager::dateConversionIntToString(expense.getDate()) << " Kwota: " << expense.getAmount() << " Nazwa: " << expense.getItem() << endl;
}
