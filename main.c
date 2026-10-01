#include <stdio.h>
#include <stdlib.h>

void displayMenu(void);
float getValidPositiveFloat(const char *promptMessage);

int main(void) {
    int choice = 0;
    float sampleFinancialInput = 0.0;

    do {
        displayMenu();
        
        if (scanf("%d", &choice) != 1) {
            printf("\n[ERROR] Invalid character detected. Please enter numbers only!\n");
            while (getchar() != '\n'); 
            choice = 0; 
            continue; 
        }

        switch(choice) {
            case 1:
                printf("\n--- Employee Management Module ---\n");
                sampleFinancialInput = getValidPositiveFloat("Enter Employee Basic Salary: N$ ");
                printf("[Validation Success] Saved Valid Salary Amount: N$ %.2f\n", sampleFinancialInput);
                break;
            case 2:
                printf("\n--- Budget Management Module ---\n");
                sampleFinancialInput = getValidPositiveFloat("Enter Departmental Budget Allocation: N$ ");
                printf("[Validation Success] Saved Valid Budget Amount: N$ %.2f\n", sampleFinancialInput);
                break;
            case 3:
                printf("\n--- Supplier Management Module ---\n");
                break;
            case 4:
                printf("\n--- Asset Management Module ---\n");
                break;
            case 5:
                printf("\n--- System Reports ---\n");
                break;
            case 6:
                printf("\nShutting down system modules...\n");
                break;
            default:
                printf("\n[ERROR] Choice out of bounds. Select a valid number (1-6).\n");
                break;
        }
    } while (choice != 6);

    printf("\nSystem stopped successfully.\n");
    return 0;
}

void displayMenu(void) {
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
    printf("Enter your choice: ");
}

float getValidPositiveFloat(const char *promptMessage) {
    float value = 0.0;
    int isValid = 0;

    do {
        printf("%s", promptMessage);
        
        if (scanf("%f", &value) != 1) {
            printf("[ERROR] Invalid data type. Please enter numerical values only.\n");
            while (getchar() != '\n'); 
            continue;
        }

        if (value < 0.0) {
            printf("[ERROR] Financial values cannot be negative. Please try again.\n");
            continue;
        }

        isValid = 1; 
    } while (!isValid);

    return value;
}
