#include <stdio.h>
#include <string.h>
#include "employees.h"
#include "input.h"

double calculateSalary(const Employee *employee) {
    return employee->basicSalary
         + employee->housingAllowance
         + employee->transportAllowance
         + employee->otherAllowance;
}

static int employeeIdExists(const Employee employees[], int count, int id) {
    int i;
    for (i = 0; i < count; i++) {
        if (employees[i].id == id) return 1;
    }
    return 0;
}

void addEmployee(Employee employees[], int *count) {
    if (*count >= MAX_EMPLOYEES) {
        printf("Employee storage is full.\n");
        return;
    }

    Employee e;
    printf("\n--- Add Employee ---\n");

    do {
        e.id = readInt("Employee ID: ", 1, 999999);
        if (employeeIdExists(employees, *count, e.id))
            printf("That employee ID already exists.\n");
    } while (employeeIdExists(employees, *count, e.id));

    readNonEmptyString("Name: ", e.name, STR_SIZE);
    readNonEmptyString("Department: ", e.department, STR_SIZE);
    e.basicSalary = readDouble("Basic salary (N$): ", 0.0, 100000000.0);
    e.housingAllowance = readDouble("Housing allowance (N$): ", 0.0, 100000000.0);
    e.transportAllowance = readDouble("Transport allowance (N$): ", 0.0, 100000000.0);
    e.otherAllowance = readDouble("Other allowance (N$): ", 0.0, 100000000.0);

    employees[*count] = e;
    (*count)++;

    printf("Employee added successfully.\n");
}

void displayEmployees(const Employee employees[], int count) {
    int i;

    printf("\n--- Employee List ---\n");
    if (count == 0) {
        printf("No employees registered.\n");
        return;
    }

    for (i = 0; i < count; i++) {
        printf("\nID: %d\n", employees[i].id);
        printf("Name: %s\n", employees[i].name);
        printf("Department: %s\n", employees[i].department);
        printf("Basic Salary: N$%.2f\n", employees[i].basicSalary);
        printf("Housing Allowance: N$%.2f\n", employees[i].housingAllowance);
        printf("Transport Allowance: N$%.2f\n", employees[i].transportAllowance);
        printf("Other Allowance: N$%.2f\n", employees[i].otherAllowance);
        printf("Total Salary: N$%.2f\n", calculateSalary(&employees[i]));
    }
}

void searchEmployee(const Employee employees[], int count) {
    char term[STR_SIZE];
    int i, found = 0;

    if (count == 0) {
        printf("No employees registered.\n");
        return;
    }

    readNonEmptyString("Enter employee name or department to search: ", term, STR_SIZE);

    for (i = 0; i < count; i++) {
        /* strcmp() provides exact department matching as well as name matching. */
        if (strcmp(employees[i].name, term) == 0 ||
            strcmp(employees[i].department, term) == 0) {
            printf("\nID: %d | Name: %s | Department: %s | Total Salary: N$%.2f\n",
                   employees[i].id, employees[i].name, employees[i].department,
                   calculateSalary(&employees[i]));
            found = 1;
        }
    }

    if (!found) printf("No matching employee found.\n");
}

void employeeMenu(Employee employees[], int *count) {
    int choice;

    do {
        printf("\n--- Employee Management ---\n");
        printf("1. Add employee\n");
        printf("2. Display employees\n");
        printf("3. Search employee\n");
        printf("4. Return to main menu\n");

        choice = readInt("Enter your choice: ", 1, 4);

        switch (choice) {
            case 1: addEmployee(employees, count); break;
            case 2: displayEmployees(employees, *count); break;
            case 3: searchEmployee(employees, *count); break;
            case 4: break;
        }
    } while (choice != 4);
}
