#include "PersonalBudget.h"

PersonalBudget::PersonalBudget()
{
    userManager.loadUsersFromFile();
}

void PersonalBudget::userSignUp()
{
    userManager.userSignUp();
}

void PersonalBudget::showAllUsers()
{
    userManager.showAllUsers();
}
