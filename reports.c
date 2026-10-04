#include <stdio.h>
#include "reports.h"
#include "input.h"

void employeeReport(const Employee employees[], int count) {
    int i;
    double total = 0.0, highest = 0.0, lowest = 0.0;

    printf("\n========== EMPLOYEE REPORT ==========\n");

    if (count == 0) {
        printf("No employees registered.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        double salary = calculateSalary(&employees[i]);
        total += salary;

        if (i == 0 || salary > highest) highest = salary;
        if (i == 0 || salary < lowest) lowest = salary;
    }

    printf("Total Employees: %d\n", count);
    printf("Average Salary: N$%.2f\n", total / count);
    printf("Highest Salary: N$%.2f\n", highest);
    printf("Lowest Salary: N$%.2f\n", lowest);
}

void budgetReport(const Budget budgets[], int count) {
    int i, exceeded = 0;
    double allocated = 0.0, expenditure = 0.0;

    printf("\n========== BUDGET REPORT ==========\n");

    if (count == 0) {
        printf("No budgets registered.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        allocated += budgets[i].allocated;
        expenditure += budgets[i].expenditure;
        if (!isWithinBudget(&budgets[i])) exceeded++;
    }

    printf("Total Allocated Budget: N$%.2f\n", allocated);
    printf("Total Expenditure: N$%.2f\n", expenditure);
    printf("Remaining Budget: N$%.2f\n", allocated - expenditure);
    printf("Departments Exceeding Budget: %d\n", exceeded);

    if (exceeded > 0) {
        printf("\nDepartments over budget:\n");
        for (i = 0; i < count; i++) {
            if (!isWithinBudget(&budgets[i])) {
                printf("- %s (Exceeded by N$%.2f)\n",
                       budgets[i].department,
                       -calculateRemainingBudget(&budgets[i]));
            }
        }
    }
}

void supplierReport(const Supplier suppliers[], int count) {
    printf("\n========== SUPPLIER REPORT ==========\n");
    displaySuppliers(suppliers, count);
}

void assetReport(const Asset assets[], int count) {
    int i;
    double totalValue = 0.0;

    printf("\n========== ASSET REPORT ==========\n");
    displayAssets(assets, count);

    for (i = 0; i < count; i++)
        totalValue += assets[i].purchaseValue;

    if (count > 0)
        printf("\nTotal registered asset value: N$%.2f\n", totalValue);
}

void reportsMenu(const Employee employees[], int employeeCount,
                 const Budget budgets[], int budgetCount,
                 const Supplier suppliers[], int supplierCount,
                 const Asset assets[], int assetCount) {
    int choice;

    do {
        printf("\n--- Reports ---\n");
        printf("1. Employee Report\n");
        printf("2. Budget Report\n");
        printf("3. Supplier Report\n");
        printf("4. Asset Report\n");
        printf("5. Return to main menu\n");

        choice = readInt("Enter your choice: ", 1, 5);

        switch (choice) {
            case 1: employeeReport(employees, employeeCount); break;
            case 2: budgetReport(budgets, budgetCount); break;
            case 3: supplierReport(suppliers, supplierCount); break;
            case 4: assetReport(assets, assetCount); break;
            case 5: break;
        }
    } while (choice != 5);
}
