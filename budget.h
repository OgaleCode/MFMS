#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 100

typedef struct {
    char department[50];
    double allocatedBudget;
    double expenditure;
} Budget;

void budgetMenu(void);
void addBudget(void);
void displayBudgets(void);
void searchDepartment(void);

#endif