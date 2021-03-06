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
        cout << "Niewlasciwa data. Wpisz date z przedzialu od 2000-01-01 do ostatniego dnia biezacego miesiaca. " << endl << endl;
        return addIncomeWithDifferentDate();
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

    cout << "Kwota przychodu (w zl): ";
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
        cout << "Niewlasciwa data. Wpisz date z przedzialu od 2000-01-01 do ostatniego dnia biezacego miesiaca. " << endl << endl;
        return addExpenseWithDifferentDate();
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

    cout << "Kwota wydatku (w zl): ";
    expense.setAmount(AuxiliaryMethods::loadFloatNumber());

    return expense;
}

int BudgetManager::retrieveNewExpenseId()
{
    return fileWithExpenses.retrieveLastExpenseId() + 1;
}

void BudgetManager::showBalanceFromCurrentMonth()
{
    float sumOfIncomes = 0, sumOfExpenses = 0;

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
        cout << endl << "Suma Twoich przychodow w tym miesiacu wynosi: " << sumOfIncomes << " zl" << endl << endl;


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
        cout << endl << "Suma Twoich wydatkow w tym miesiacu wynosi: " << sumOfExpenses << " zl" << endl << endl;

    if((sumOfIncomes != 0 || sumOfExpenses != 0) && (sumOfIncomes > sumOfExpenses))
        cout << endl << endl << "Twoj zysk w biezacym miesiacu wynosi: " << sumOfIncomes - sumOfExpenses << " zl" << endl << endl;
    else if((sumOfIncomes != 0 || sumOfExpenses != 0) && (sumOfIncomes < sumOfExpenses))
        cout << endl << endl << "Twoja strata w biezacym miesiacu wynosi: " << sumOfIncomes - sumOfExpenses << " zl" << endl << endl;

    system("pause");
}

void BudgetManager::showBalanceFromPreviousMonth()
{
    float sumOfIncomes = 0, sumOfExpenses = 0;

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
        cout << endl << "Suma Twoich przychodow w poprzednim miesiacu wynosila: " << sumOfIncomes << " zl" << endl << endl;


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
        cout << endl << "Suma Twoich wydatkow w poprzednim miesiacu wynosila: " << sumOfExpenses << " zl" << endl << endl;

    if((sumOfIncomes != 0 || sumOfExpenses != 0) && (sumOfIncomes > sumOfExpenses))
        cout << endl << endl << "Twoj zysk w poprzednim miesiacu wynosil: " << sumOfIncomes - sumOfExpenses << " zl" << endl << endl;
    else if((sumOfIncomes != 0 || sumOfExpenses != 0) && (sumOfIncomes < sumOfExpenses))
        cout << endl << endl << "Twoja strata w poprzednim miesiacu wynosila: " << sumOfIncomes - sumOfExpenses << " zl" << endl << endl;

    system("pause");
}

void BudgetManager::showBalanceFromSelectedPeriod()
{
    string beginDate = "", endDate = "";
    float sumOfIncomes = 0, sumOfExpenses = 0;

    system("cls");
    cout << " >>> TWOJ BILANS W WYBRANYM OKRESIE <<<" << endl << endl;

    cout << "Podaj date poczatku okresu (rrrr-mm-dd): ";
    beginDate = AuxiliaryMethods::loadLine();

    if(!dateManager.isDateCorrect(beginDate))
    {
        cout << "Niewlasciwa data. Twoj bilans moze byc pokazany maksymalnie od 2000-01-01. " << endl;
        system("pause");
        return showBalanceFromSelectedPeriod();
    }
    else
    {
        cout << "Podaj date konca okresu (rrrr-mm-dd): ";
        endDate = AuxiliaryMethods::loadLine();
        if(!dateManager.isDateCorrect(endDate))
        {
            cout << "Niewlasciwa data. Twoj bilans moze byc pokazany maksymalnie do ostatniego dnia biezacego miesiaca. " << endl;
            system("pause");
            return showBalanceFromSelectedPeriod();
        }
    }
    system("cls");
    cout << " >>> TWOJE PRZYCHODY W OKRESIE OD " << beginDate << " DO " << endDate << " <<<" << endl << endl;

    for(vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++)
    {
        if((itr -> getDate() >= DateManager::dateConversionStringToInt(beginDate)) && (itr -> getDate() <= DateManager::dateConversionStringToInt(endDate)))
        {
            showIncomes(*itr);
            sumOfIncomes += itr -> getAmount();
        }
    }

    if(sumOfIncomes == 0)
    {
        cout << "Brak przychodow w wybranym okresie. " << endl << endl;
    }
    else
        cout << endl << "Suma Twoich przychodow w wybranym okresie: " << sumOfIncomes << " zl" << endl << endl;


    cout << endl << endl << " >>> TWOJE WYDATKI W OKRESIE OD " << beginDate << " DO " << endDate << " <<<" << endl << endl;

    for(vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++)
    {
        if((itr -> getDate() >= DateManager::dateConversionStringToInt(beginDate)) && (itr -> getDate() <= DateManager::dateConversionStringToInt(endDate)))
        {
            showExpenses(*itr);
            sumOfExpenses += itr -> getAmount();
        }
    }

    if(sumOfExpenses == 0)
    {
        cout << "Brak wydatkow w wybranym okresie. " << endl << endl;
    }
    else
        cout << endl << "Suma Twoich wydatkow w wybranym okresie: " << sumOfExpenses << " zl" << endl << endl;

    if((sumOfIncomes != 0 || sumOfExpenses != 0) && (sumOfIncomes > sumOfExpenses))
        cout << endl << endl << "Twoj zysk w wybranym okresie wynosi: " << sumOfIncomes - sumOfExpenses << " zl" << endl << endl;
    else if((sumOfIncomes != 0 || sumOfExpenses != 0) && (sumOfIncomes < sumOfExpenses))
        cout << endl << endl << "Twoja strata w wybranym okresie wynosi: " << sumOfIncomes - sumOfExpenses << " zl" << endl << endl;

    system("pause");
}

void BudgetManager::showIncomes(Income income)
{
    cout << "ID Przychodu: " << income.getIncomeId() << " Data: " << DateManager::dateConversionIntToString(income.getDate()) << " Kwota: " << income.getAmount() << " zl" << " Nazwa: " << income.getItem() << endl;
}

void BudgetManager::showExpenses(Expense expense)
{
    cout << "ID Wydatku: " << expense.getExpenseId() << " Data: " << DateManager::dateConversionIntToString(expense.getDate()) << " Kwota: " << expense.getAmount() << " zl" << " Nazwa: " << expense.getItem() << endl;
}

void BudgetManager::sortIncomesByDate()
{
    struct date
    {
        inline bool operator () (Income& date1, Income& date2)
        {
            return (date1.getDate() < date2.getDate());
        }
    };
    sort(incomes.begin(), incomes.end(), date());
}

void BudgetManager::sortExpensesByDate()
{
    struct date
    {
        inline bool operator () (Expense& date1, Expense& date2)
        {
            return (date1.getDate() < date2.getDate());
        }
    };
    sort(expenses.begin(), expenses.end(), date());
}
