#include <stdio.h>
#include <string.h>
#include "budget.h"

static Budget budgets[MAX_BUDGETS];
static int budgetCount = 0;

void budgetMenu(void)
{
    int choice;

    // menu printing...

    printf("\n====================================\n");
    printf("        BUDGET MANAGEMENT\n");
    printf("====================================\n");
    printf("1. Add Budget\n");
    printf("2. Display Budgets\n");
    printf("3. Search Department\n");
    printf("4. Return to Main Menu\n");
    printf("====================================\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
  {
    case 1:
        addBudget();
        break;

    case 2:
        displayBudgets();
        break;

    case 3:
        searchDepartment();
        break;

    case 4:
        return;

    default:
        printf("Invalid choice. Please select 1-4.\n");
        break;
  }
}

void addBudget(void)
{
    if (budgetCount >= MAX_BUDGETS)
    {
       printf("\n[ERROR] Budget storage is full.\n");
       return;
    }
    Budget *newBudget = &budgets[budgetCount];
    
    printf("\nEnter Department Name: ");
    getchar();
    fgets(newBudget->department, sizeof(newBudget->department), stdin);
    newBudget->department[strcspn(newBudget->department, "\n")] = '\0';

    printf("Enter Allocated Budget: N$ ");
    scanf("%lf", &newBudget->allocatedBudget);

    printf("Enter Expenditure: N$ ");
    scanf("%lf", &newBudget->expenditure);

    double remaining = newBudget->allocatedBudget - newBudget->expenditure;

    printf("Remaining Budget: N$ %.2f\n", remaining);

    budgetCount++;

    printf("Budget added successfully!\n");
}

void displayBudgets(void)
{

    printf("\n====================================\n");
    printf("           DISPLAY BUDGETS\n");
    printf("====================================\n");

   for (int i = 0; i < budgetCount; i++)
{
    printf("Department: %s\n", budgets[i].department);
    printf("Allocated Budget: N$ %.2f\n", budgets[i].allocatedBudget);
    printf("Expenditure: N$ %.2f\n", budgets[i].expenditure);
    printf("Remaining Budget: N$ %.2f\n",
       budgets[i].allocatedBudget - budgets[i].expenditure);
}

}

void searchDepartment(void)
{
    char searchName[50];
    int found = 0;

    printf("\nEnter Department Name to Search: ");
    getchar();
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    for (int i = 0; i < budgetCount; i++)
{
    if (strcmp(budgets[i].department, searchName) == 0)
    {
        printf("\nDepartment: %s\n", budgets[i].department);
        printf("Allocated Budget: N$ %.2f\n", budgets[i].allocatedBudget);
        printf("Expenditure: N$ %.2f\n", budgets[i].expenditure);
        printf("Remaining Budget: N$ %.2f\n",
               budgets[i].allocatedBudget - budgets[i].expenditure);

        found = 1;
    }
}
if (!found)
{
    printf("\nDepartment not found.\n");
}

}