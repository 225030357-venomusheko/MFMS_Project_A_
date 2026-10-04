#ifndef SUPPLIERS_H
#define SUPPLIERS_H

#define MAX_SUPPLIERS 100
#define STR_SIZE 100

typedef struct {
    int id;
    char name[STR_SIZE];
    char email[STR_SIZE];
    char telephone[STR_SIZE];
    char location[STR_SIZE];
} Supplier;

void supplierMenu(Supplier suppliers[], int *count);
void addSupplier(Supplier suppliers[], int *count);
void displaySuppliers(const Supplier suppliers[], int count);
void searchSupplier(const Supplier suppliers[], int count);

#endif
