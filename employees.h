#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#define MAX_EMPLOYEES 100
#define STR_SIZE 100

typedef struct {
    int id;
    char name[STR_SIZE];
    char department[STR_SIZE];
    double basicSalary;
    double housingAllowance;
    double transportAllowance;
    double otherAllowance;
} Employee;

double calculateSalary(const Employee *employee);
void employeeMenu(Employee employees[], int *count);
void addEmployee(Employee employees[], int *count);
void displayEmployees(const Employee employees[], int count);
void searchEmployee(const Employee employees[], int count);

#endif
