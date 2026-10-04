#include <stdio.h>
#include "suppliers.h"
#include <string.h>

static Supplier suppliers[MAX_SUPPLIERS];
static int supplierCount = 0;

void supplierMenu(void)
{
    int choice;

    do
    {
        printf("\n========================================\n");
        printf("        SUPPLIER MANAGEMENT\n");
        printf("========================================\n");
        printf("1. Add Supplier\n");
        printf("2. Display Suppliers\n");
        printf("3. Search Supplier\n");
        printf("4. Return to the main menu\n");
        printf("========================================\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("\n[ERROR] Please enter a number.\n");

            while (getchar() != '\n')
                ;

            choice = 0;
            continue;
        }

        while (getchar() != '\n')
            ;

        switch (choice)
        {

        case 1:
            addSupplier();
            break;

        case 2:
            displaySuppliers();
            break;

        case 3:
            searchSupplier();
            break;

        case 4:
            printf("\nReturning to the main menu...\n");
            break;

        default:
            printf("\n[ERROR] Invalid choice. Please select 1-4.\n");
        }

    } while (choice != 4);
}

int supplierIDExists(int id)
{
    for (int i = 0; i < supplierCount; i++)
    {
        if (suppliers[i].id == id)
        {
            return 1;
        }
    }

    return 0;
}

void addSupplier(void)
{
    if (supplierCount >= MAX_SUPPLIERS)
    {
        printf("\n[ERROR] Supplier storage is full.\n");
        return;
    }

    Supplier newSupplier;

    printf("\n========== ADD SUPPLIER ==========\n");

    while (1)
    {
        printf("Enter Supplier ID: ");

        if (scanf("%d", &newSupplier.id) != 1)
        {
            printf("[ERROR] Supplier ID must be a number.\n");

            while (getchar() != '\n')
                ;
        }
        else if (newSupplier.id <= 0)
        {
            printf("[ERROR] Supplier ID must be greater than 0.\n");

            while (getchar() != '\n')
                ;
        }
        else if (supplierIDExists(newSupplier.id))
        {
            printf("[ERROR] Supplier ID already exists.\n");
            printf("Please enter a different Supplier ID.\n");

            while (getchar() != '\n')
                ;
        }
        else
        {
            while (getchar() != '\n')
                ;
            break;
        }
    }

    do
    {
        printf("Enter Supplier Name: ");
        fgets(newSupplier.name, sizeof(newSupplier.name), stdin);

        newSupplier.name[strcspn(newSupplier.name, "\n")] = '\0';

        if (strlen(newSupplier.name) == 0)
        {
            printf("[ERROR] Supplier name cannot be empty.\n");
        }

    } while (strlen(newSupplier.name) == 0);

    do
    {
        printf("Enter Supplier Email: ");
        fgets(newSupplier.email, sizeof(newSupplier.email), stdin);

        newSupplier.email[strcspn(newSupplier.email, "\n")] = '\0';

        if (strlen(newSupplier.email) == 0)
        {
            printf("[ERROR] Email cannot be empty.\n");
        }

    } while (strlen(newSupplier.email) == 0);

    do
    {
        printf("Enter Telephone Number: ");
        fgets(newSupplier.telephone, sizeof(newSupplier.telephone), stdin);

        newSupplier.telephone[strcspn(newSupplier.telephone, "\n")] = '\0';

        if (strlen(newSupplier.telephone) == 0)
        {
            printf("[ERROR] Telephone number cannot be empty.\n");
        }

    } while (strlen(newSupplier.telephone) == 0);

    do
    {
        printf("Enter Town/Location: ");
        fgets(newSupplier.town, sizeof(newSupplier.town), stdin);

        newSupplier.town[strcspn(newSupplier.town, "\n")] = '\0';

        if (strlen(newSupplier.town) == 0)
        {
            printf("[ERROR] Town/Location cannot be empty.\n");
        }

    } while (strlen(newSupplier.town) == 0);

    suppliers[supplierCount] = newSupplier;
    supplierCount++;

    printf("\n[SUCCESS] Supplier added successfully!\n");
}

void displaySuppliers(void)
{
    if (supplierCount == 0)
    {
        printf("\n[INFO] No suppliers have been registered yet.\n");
        return;
    }

    printf("\n==================== REGISTERED SUPPLIERS ====================\n");

    for (int i = 0; i < supplierCount; i++)
    {
        printf("\nSupplier %d\n", i + 1);
        printf("--------------------------------------------------\n");
        printf("Supplier ID      : %d\n", suppliers[i].id);
        printf("Supplier Name    : %s\n", suppliers[i].name);
        printf("Email            : %s\n", suppliers[i].email);
        printf("Telephone        : %s\n", suppliers[i].telephone);
        printf("Town/Location    : %s\n", suppliers[i].town);
    }

    printf("\n==============================================================\n");
    printf("Total Suppliers: %d\n", supplierCount);
}

void searchSupplier(void)
{
    int searchID;
    int found = 0;

    if (supplierCount == 0)
    {
        printf("\n[INFO] No suppliers have been registered yet.\n");
        return;
    }

    printf("\n========== SEARCH SUPPLIER ==========\n");
    printf("Enter Supplier ID to search: ");

    if (scanf("%d", &searchID) != 1)
    {
        printf("[ERROR] Supplier ID must be a number.\n");

        while (getchar() != '\n')
            ;

        return;
    }

    while (getchar() != '\n')
        ;

    for (int i = 0; i < supplierCount; i++)
    {

        if (suppliers[i].id == searchID)
        {
            printf("\n[SUCCESS] Supplier found!\n");
            printf("----------------------------------------\n");
            printf("Supplier ID      : %d\n", suppliers[i].id);
            printf("Supplier Name    : %s\n", suppliers[i].name);
            printf("Email            : %s\n", suppliers[i].email);
            printf("Telephone        : %s\n", suppliers[i].telephone);
            printf("Town/Location    : %s\n", suppliers[i].town);
            printf("----------------------------------------\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\n[INFO] No supplier found with ID %d.\n", searchID);
    }
}
