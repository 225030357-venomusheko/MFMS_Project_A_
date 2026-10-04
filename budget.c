#include <stdio.h>
#include <string.h>
#include "budget.h"
#include "input.h"

double calculateRemainingBudget(const Budget *budget) {
    return budget->allocated - budget->expenditure;
}

int isWithinBudget(const Budget *budget) {
    return budget->expenditure <= budget->allocated;
}

static int budgetIdExists(const Budget budgets[], int count, int id) {
    int i;
    for (i = 0; i < count; i++)
        if (budgets[i].id == id) return 1;
    return 0;
}

void addBudget(Budget budgets[], int *count) {
    Budget b;

    if (*count >= MAX_BUDGETS) {
        printf("Budget storage is full.\n");
        return;
    }

    printf("\n--- Add Department Budget ---\n");
    do {
        b.id = readInt("Budget ID: ", 1, 999999);
        if (budgetIdExists(budgets, *count, b.id))
            printf("That budget ID already exists.\n");
    } while (budgetIdExists(budgets, *count, b.id));

    readNonEmptyString("Department: ", b.department, STR_SIZE);
    b.allocated = readDouble("Allocated budget (N$): ", 0.0, 100000000000.0);
    b.expenditure = readDouble("Expenditure (N$): ", 0.0, 100000000000.0);

    budgets[*count] = b;
    (*count)++;

    printf("Budget recorded successfully.\n");
}

void displayBudgets(const Budget budgets[], int count) {
    int i;

    printf("\n--- Budget Information ---\n");
    if (count == 0) {
        printf("No budgets registered.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        double remaining = calculateRemainingBudget(&budgets[i]);

        printf("\nID: %d\n", budgets[i].id);
        printf("Department: %s\n", budgets[i].department);
        printf("Allocated: N$%.2f\n", budgets[i].allocated);
        printf("Expenditure: N$%.2f\n", budgets[i].expenditure);

        if (isWithinBudget(&budgets[i]))
            printf("Remaining Budget: N$%.2f\nStatus: WITHIN BUDGET\n", remaining);
        else
            printf("Budget Exceeded By: N$%.2f\nStatus: OVER BUDGET\n", -remaining);
    }
}

void searchBudget(const Budget budgets[], int count) {
    char department[STR_SIZE];
    int i, found = 0;

    readNonEmptyString("Enter department to search: ", department, STR_SIZE);

    for (i = 0; i < count; i++) {
        if (strcmp(budgets[i].department, department) == 0) {
            printf("\nDepartment: %s | Allocated: N$%.2f | Expenditure: N$%.2f | Remaining: N$%.2f\n",
                   budgets[i].department, budgets[i].allocated,
                   budgets[i].expenditure,
                   calculateRemainingBudget(&budgets[i]));
            found = 1;
        }
    }

    if (!found) printf("No matching department budget found.\n");
}

void budgetMenu(Budget budgets[], int *count) {
    int choice;

    do {
        printf("\n--- Budget Management ---\n");
        printf("1. Enter departmental budget\n");
        printf("2. Display budgets\n");
        printf("3. Search budget\n");
        printf("4. Return to main menu\n");

        choice = readInt("Enter your choice: ", 1, 4);

        switch (choice) {
            case 1: addBudget(budgets, count); break;
            case 2: displayBudgets(budgets, *count); break;
            case 3: searchBudget(budgets, *count); break;
            case 4: break;
        }
    } while (choice != 4);
}
