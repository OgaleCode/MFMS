#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "validation.h"

#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

void runEmployeeMenu() {
    int choice = 0;
    do {
        printf("\n--- Employee Management ---\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Search Employee\n");
        printf("4. Back to Main Menu\n");
        
        choice = getValidInt(1, 4, "Enter choice: ");
        
        switch (choice) {
            case 1: addEmployee(); break;
            case 2: displayEmployees(); break;
            case 3: searchEmployee(); break;
        }
    } while (choice != 4);
}

int main() {
    int choice = 0;

    do {
        printf("\n========================================\n");
        printf(" MUNICIPAL FINANCIAL MANAGEMENT SYSTEM \n");
        printf("========================================\n");
        printf("1. Employee Management\n");
        printf("2. Budget Management\n");
        printf("3. Supplier Management\n");
        printf("4. Asset Management\n");
        printf("5. Reports\n");
        printf("6. Exit\n");
        printf("========================================\n");
        
        choice = getValidInt(1, 6, "Enter choice: ");

        switch (choice) {
            case 1:
                runEmployeeMenu();
                break;
            case 2:
                budgetMenu();
                break;
            case 3:
                supplierMenu();
                break;
            case 4:
                assetManagementMenu();
                break;
            case 5:
               reportsMenu();
                break;
            case 6:
                printf("\nExiting system. Local tracking session closed cleanly.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
