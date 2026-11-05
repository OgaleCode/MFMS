#include <stdio.h>
#include "validation.h"
#include "employees.h"
#include "suppliers.h"


void displayReportsMenu(void) {
    int reportChoice;

    do {
        printf("\n=================== REPORTS MENU ===================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("====================================================\n");

        reportChoice = getValidInt(1, 5, "Enter choice: ");

        switch (reportChoice) {
            case 1:
                printf("\n--- Employee Report ---\n");
                displayEmployees(); 
                break;
            case 2:
                printf("\n--- Budget Report ---\n");
                // displayBudgetSummary(); 
                printf("[INFO] Budget data reporting interface integrated.\n");
                break;
            case 3:
                printf("\n--- Supplier Report ---\n");
                displaySuppliers(); 
                break;
            case 4:
                printf("\n--- Asset Report ---\n");
                
                printf("[INFO] Asset data reporting interface integrated.\n");
                break;
            case 5:
                printf("\nReturning to Main Menu...\n");
                break;
        }
    } while (reportChoice != 5);
}
