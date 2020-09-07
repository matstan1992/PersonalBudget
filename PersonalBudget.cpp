#include "PersonalBudget.h"

char PersonalBudget::selectOptionFromTheMainMenu()
{
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

char PersonalBudget:: selectOptionFromTheUserMenu()
{
    char choice;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << " " << userManager.getNameOfSignedInUser() << " " << userManager.getSurnameOfSignedInUser() << endl;
    cout << "--------------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "--------------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "--------------------------------" << endl;
    cout << "Twoj wybor: ";

    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

void PersonalBudget::userSignUp()
{
    userManager.userSignUp();
}

void PersonalBudget::userSignIn()
{
    userManager.userSignIn();
    if(userManager.isUserSignedIn())
    {
        budgetManager = new BudgetManager(NAME_FILE_WITH_INCOMES, NAME_FILE_WITH_EXPENSES, userManager.retrieveSignedInUserId());
    }
}

void PersonalBudget::logOutUser()
{
    userManager.logOutUser();
    delete budgetManager;
    budgetManager = NULL;
}

void PersonalBudget::changePasswordSignedInUser()
{
    userManager.changePasswordSignedInUser();
}

void PersonalBudget::showAllUsers()
{
    userManager.showAllUsers();
}

bool PersonalBudget::isUserSignedIn()
{
    userManager.isUserSignedIn();
}

void PersonalBudget::addIncome()
{
    budgetManager -> addIncome();
}

void PersonalBudget::addExpense()
{
    budgetManager -> addExpense();
}

void PersonalBudget::showBalanceFromCurrentMonth()
{
    budgetManager -> showBalanceFromCurrentMonth();
}

void PersonalBudget::showBalanceFromPreviousMonth()
{
    budgetManager -> showBalanceFromPreviousMonth();
}

void PersonalBudget::showBalanceFromSelectedPeriod()
{
    budgetManager -> showBalanceFromSelectedPeriod();
}
