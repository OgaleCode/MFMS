#include <stdio.h>
#include "employees.h"

#define MAX_EMPLOYEES 50

/* Employee data */
int employeeIDs[MAX_EMPLOYEES];
char employeeNames[MAX_EMPLOYEES][100];
char employeeDepartments[MAX_EMPLOYEES][100];

float employeeBasic[MAX_EMPLOYEES];
float employeeHousing[MAX_EMPLOYEES];
float employeeTransport[MAX_EMPLOYEES];

int employeeCount = 0;

/* Add a new employee */
void addEmployee(void)
{
    if (employeeCount >= MAX_EMPLOYEES)
    {
        printf("\nEmployee storage is full.\n");
        return;
    }

    printf("\n===== ADD EMPLOYEE =====\n");

    printf("Enter Employee ID: ");
    scanf("%d", &employeeIDs[employeeCount]);

    printf("Enter Employee Name: ");
    scanf(" %99[^\n]", employeeNames[employeeCount]);

    printf("Enter Department: ");
    scanf(" %99[^\n]", employeeDepartments[employeeCount]);

    do
    {
        printf("Enter Basic Salary: ");
        scanf("%f", &employeeBasic[employeeCount]);

        if (employeeBasic[employeeCount] < 0)
        {
            printf("Salary cannot be negative. Please try again.\n");
        }

    } while (employeeBasic[employeeCount] < 0);

    do
    {
        printf("Enter Housing Allowance: ");
        scanf("%f", &employeeHousing[employeeCount]);

        if (employeeHousing[employeeCount] < 0)
        {
            printf("Housing allowance cannot be negative. Please try again.\n");
        }

    } while (employeeHousing[employeeCount] < 0);

    do
    {
        printf("Enter Transport Allowance: ");
        scanf("%f", &employeeTransport[employeeCount]);

        if (employeeTransport[employeeCount] < 0)
        {
            printf("Transport allowance cannot be negative. Please try again.\n");
        }

    } while (employeeTransport[employeeCount] < 0);

    employeeCount++;

    printf("\nEmployee added successfully.\n");
}


/* Calculate gross employee salary */
float calculateSalary(float basic, float housing, float transport)
{
    return basic + housing + transport;
}


/* Display all employees */
void displayEmployees(void)
{
    int i;

    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n===== EMPLOYEE LIST =====\n");

    for (i = 0; i < employeeCount; i++)
    {
        printf("\nEmployee %d\n", i + 1);
        printf("Employee ID: %d\n", employeeIDs[i]);
        printf("Name: %s\n", employeeNames[i]);
        printf("Department: %s\n", employeeDepartments[i]);
        printf("Basic Salary: N$%.2f\n", employeeBasic[i]);
        printf("Housing Allowance: N$%.2f\n", employeeHousing[i]);
        printf("Transport Allowance: N$%.2f\n", employeeTransport[i]);

        printf("Gross Salary: N$%.2f\n",
               calculateSalary(
                   employeeBasic[i],
                   employeeHousing[i],
                   employeeTransport[i]
               ));
    }
}


/* Search for an employee by ID */
void searchEmployee(void)
{
    int searchID;
    int i;
    int found = 0;

    if (employeeCount == 0)
    {
        printf("\nNo employees have been added yet.\n");
        return;
    }

    printf("\n===== SEARCH EMPLOYEE =====\n");

    printf("Enter Employee ID: ");
    scanf("%d", &searchID);

    for (i = 0; i < employeeCount; i++)
    {
        if (employeeIDs[i] == searchID)
        {
            printf("\nEmployee found.\n");
            printf("Employee ID: %d\n", employeeIDs[i]);
            printf("Name: %s\n", employeeNames[i]);
            printf("Department: %s\n", employeeDepartments[i]);
            printf("Basic Salary: N$%.2f\n", employeeBasic[i]);
            printf("Housing Allowance: N$%.2f\n", employeeHousing[i]);
            printf("Transport Allowance: N$%.2f\n", employeeTransport[i]);

            printf("Gross Salary: N$%.2f\n",
                   calculateSalary(
                       employeeBasic[i],
                       employeeHousing[i],
                       employeeTransport[i]
                   ));

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("\nEmployee not found.\n");
    }
}
