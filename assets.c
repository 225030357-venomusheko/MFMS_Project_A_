#include <stdio.h>
#include <string.h>
#include "assets.h"
#include "input.h"

static int assetIdExists(const Asset assets[], int count, int id) {
    int i;
    for (i = 0; i < count; i++)
        if (assets[i].id == id) return 1;
    return 0;
}

void addAsset(Asset assets[], int *count) {
    Asset a;

    if (*count >= MAX_ASSETS) {
        printf("Asset storage is full.\n");
        return;
    }

    printf("\n--- Add Asset ---\n");
    do {
        a.id = readInt("Asset ID: ", 1, 999999);
        if (assetIdExists(assets, *count, a.id))
            printf("That asset ID already exists.\n");
    } while (assetIdExists(assets, *count, a.id));

    readNonEmptyString("Asset name: ", a.name, STR_SIZE);
    readNonEmptyString("Asset type: ", a.type, STR_SIZE);
    a.purchaseValue = readDouble("Purchase value (N$): ", 0.0, 100000000000.0);
    readNonEmptyString("Department: ", a.department, STR_SIZE);
    readNonEmptyString("Condition: ", a.condition, STR_SIZE);

    assets[*count] = a;
    (*count)++;

    printf("Asset added successfully.\n");
}

void displayAssets(const Asset assets[], int count) {
    int i;

    printf("\n--- Asset Register ---\n");
    if (count == 0) {
        printf("No assets registered.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("%d. ID: %d | Name: %s | Type: %s | Value: N$%.2f | Department: %s | Condition: %s\n",
               i + 1, assets[i].id, assets[i].name, assets[i].type,
               assets[i].purchaseValue, assets[i].department, assets[i].condition);
    }
}

void searchAsset(const Asset assets[], int count) {
    char term[STR_SIZE];
    int i, found = 0;

    if (count == 0) {
        printf("No assets registered.\n");
        return;
    }

    readNonEmptyString("Enter asset name, type or department: ", term, STR_SIZE);

    for (i = 0; i < count; i++) {
        if (strcmp(assets[i].name, term) == 0 ||
            strcmp(assets[i].type, term) == 0 ||
            strcmp(assets[i].department, term) == 0) {
            printf("ID: %d | %s | %s | N$%.2f | %s | %s\n",
                   assets[i].id, assets[i].name, assets[i].type,
                   assets[i].purchaseValue, assets[i].department, assets[i].condition);
            found = 1;
        }
    }

    if (!found) printf("No matching asset found.\n");
}

void assetMenu(Asset assets[], int *count) {
    int choice;

    do {
        printf("\n--- Asset Management ---\n");
        printf("1. Add asset\n");
        printf("2. Display assets\n");
        printf("3. Search asset\n");
        printf("4. Return to main menu\n");

        choice = readInt("Enter your choice: ", 1, 4);

        switch (choice) {
            case 1: addAsset(assets, count); break;
            case 2: displayAssets(assets, *count); break;
            case 3: searchAsset(assets, *count); break;
            case 4: break;
        }
    } while (choice != 4);
}
