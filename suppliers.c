#include <stdio.h>
#include <string.h>
#include "suppliers.h"
#include "input.h"

static int supplierIdExists(const Supplier suppliers[], int count, int id) {
    int i;
    for (i = 0; i < count; i++)
        if (suppliers[i].id == id) return 1;
    return 0;
}

void addSupplier(Supplier suppliers[], int *count) {
    Supplier s;

    if (*count >= MAX_SUPPLIERS) {
        printf("Supplier storage is full.\n");
        return;
    }

    printf("\n--- Add Supplier ---\n");
    do {
        s.id = readInt("Supplier ID: ", 1, 999999);
        if (supplierIdExists(suppliers, *count, s.id))
            printf("That supplier ID already exists.\n");
    } while (supplierIdExists(suppliers, *count, s.id));

    readNonEmptyString("Supplier name: ", s.name, STR_SIZE);
    readNonEmptyString("Email: ", s.email, STR_SIZE);
    readNonEmptyString("Telephone number: ", s.telephone, STR_SIZE);
    readNonEmptyString("Town/Location: ", s.location, STR_SIZE);

    suppliers[*count] = s;
    (*count)++;

    printf("Supplier added successfully.\n");
}

void displaySuppliers(const Supplier suppliers[], int count) {
    int i;

    printf("\n--- Supplier List ---\n");
    if (count == 0) {
        printf("No suppliers registered.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("%d. ID: %d | Name: %s | Email: %s | Tel: %s | Location: %s\n",
               i + 1, suppliers[i].id, suppliers[i].name, suppliers[i].email,
               suppliers[i].telephone, suppliers[i].location);
    }
}

void searchSupplier(const Supplier suppliers[], int count) {
    char term[STR_SIZE];
    int i, found = 0;

    if (count == 0) {
        printf("No suppliers registered.\n");
        return;
    }

    readNonEmptyString("Enter supplier name or location: ", term, STR_SIZE);

    for (i = 0; i < count; i++) {
        if (strcmp(suppliers[i].name, term) == 0 ||
            strcmp(suppliers[i].location, term) == 0) {
            printf("ID: %d | %s | %s | %s | %s\n",
                   suppliers[i].id, suppliers[i].name, suppliers[i].email,
                   suppliers[i].telephone, suppliers[i].location);
            found = 1;
        }
    }

    if (!found) printf("No matching supplier found.\n");
}

void supplierMenu(Supplier suppliers[], int *count) {
    int choice;

    do {
        printf("\n--- Supplier Management ---\n");
        printf("1. Add supplier\n");
        printf("2. Display suppliers\n");
        printf("3. Search supplier\n");
        printf("4. Return to main menu\n");

        choice = readInt("Enter your choice: ", 1, 4);

        switch (choice) {
            case 1: addSupplier(suppliers, count); break;
            case 2: displaySuppliers(suppliers, *count); break;
            case 3: searchSupplier(suppliers, *count); break;
            case 4: break;
        }
    } while (choice != 4);
}
