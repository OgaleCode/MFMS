#include <stdio.h>
#include "reports.h"
#include "validation.h"

void reportsMenu(void) {
    int reportChoice = 0;
    
    do {
        printf("\n========================================\n");
        printf("             REPORTS MENU               \n");
        printf("========================================\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Back to Main Menu\n");
        printf("========================================\n");
        
        reportChoice = getValidInt(1, 5, "Enter choice: ");
        
        switch (reportChoice) {
            case 1:
                printf("\n--- Employee Report ---\n");
                printf("Total Employees: 0\n");
                printf("Average Salary: N$0.00\n");
                printf("Highest Salary: N$0.00\n");
                printf("Lowest Salary: N$0.00\n");
                break;
            case 2:
                printf("\n--- Budget Report ---\n");
                printf("Total Allocated Budget: N$0.00\n");
                printf("Total Expenditure: N$0.00\n");
                printf("Remaining Budget: N$0.00\n");
                break;
            case 3:
                printf("\n--- Supplier Report ---\n");
                printf("Displaying all registered suppliers...\n");
                break;
            case 4:
                printf("\n--- Asset Report ---\n");
                printf("Displaying registered municipal assets...\n");
                break;
        }
    } while (reportChoice != 5);
}
