#include <stdio.h>
#include <stdlib.h>
#include "constants.h"
#include "validation.h"

// 1. INTEGRATION:
#include "employees.h"
#include "budget.h"
#include "suppliers.h"
#include "assets.h"
#include "reports.h"

int main() {
    // -------------------------------------------------------------
    // -------------------------------------------------------------
    
    // Employee Arrays 
    char empIds[MAX_RECORDS][STR_LEN];
    char empNames[MAX_RECORDS][STR_LEN];
    float empSalaries[MAX_RECORDS];
    int employeeCount = 0;

    // Budget Arrays 
    char deptNames[MAX_RECORDS][STR_LEN];
    float allocatedBudgets[MAX_RECORDS];
    float actualExpenditures[MAX_RECORDS];
    int deptCount = 0;

    // Supplier Arrays 
    char supplierIds[MAX_RECORDS][STR_LEN];
    char supplierNames[MAX_RECORDS][STR_LEN];
    int supplierCount = 0;

    // Asset Arrays 
    char assetIds[MAX_RECORDS][STR_LEN];
    char assetNames[MAX_RECORDS][STR_LEN];
    float assetValues[MAX_RECORDS];
    int assetCount = 0;

    int choice = 0;

    // -------------------------------------------------------------
    // SYSTEM NAVIGATION LOOP
    // -------------------------------------------------------------
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
        
        // 
        choice = getValidInt(1, 6, "Enter choice: ");

        switch (choice) {
            case 1:
                // 
                employeeMenu(empIds, empNames, empSalaries, &employeeCount);
                break;
            case 2:
                // 
                budgetMenu(deptNames, allocatedBudgets, actualExpenditures, &deptCount);
                break;
            case 3:
                // 
                supplierMenu(supplierIds, supplierNames, &supplierCount);
                break;
            case 4:
                // 
                assetMenu(assetIds, assetNames, assetValues, &assetCount);
                break;
            case 5:
                // 
                // Passes all historical data down for analysis
                reportsMenu(empSalaries, employeeCount, allocatedBudgets, actualExpenditures, deptCount);
                break;
            case 6:
                printf("\nExiting system. Local tracking session closed cleanly.\n");
                break;
        }
    } while (choice != 6);

    return 0;
}
