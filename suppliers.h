#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100

typedef struct {
    int id;
    char name[100];
    char email[100];
    char telephone[30];
    char town[50];
} Supplier;

void supplierMenu(void);
void addSupplier(void);
void displaySuppliers(void);
void searchSupplier(void);
int supplierIDExists(int id);

#endif