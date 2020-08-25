#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget ("users.xml");
    personalBudget.showAllUsers();

    personalBudget.userSignUp();
    personalBudget.userSignUp();
    personalBudget.showAllUsers();

    return 0;
}
