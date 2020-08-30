#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    char choice;

    PersonalBudget personalBudget ("users.xml", "incomes.xml");

    while (true)
    {
        if (personalBudget.isUserSignedIn() == false)
        {
            choice = personalBudget.selectOptionFromTheMainMenu();

            switch (choice)
            {
            case '1':
                personalBudget.userSignUp();
                break;
            case '2':
                personalBudget.userSignIn();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
        else
        {
            choice = personalBudget.selectOptionFromTheUserMenu();

            switch (choice)
            {
            case '1':
                personalBudget.addIncome();
                break;
            /*case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.showBalanceFromCurrentMonth();
                break;
            case '4':
                personalBudget.showBalanceFromPreviousMonth();
                break;
            case '5':
                personalBudget.showBalanceFromSelectedPeriod();
                break;*/
            case '6':
                personalBudget.changePasswordSignedInUser();
                break;
            case '7':
                personalBudget.logOutUser();
                break;
            }
        }
    }
    /*  personalBudget.userSignUp();
      personalBudget.showAllUsers();
    */
    return 0;
}
