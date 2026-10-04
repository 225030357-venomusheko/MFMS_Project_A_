#ifndef BUDGET_H
#define BUDGET_H

#define MAX_BUDGETS 50
#define STR_SIZE 100

typedef struct {
    int id;
    char department[STR_SIZE];
    double allocated;
    double expenditure;
} Budget;

double calculateRemainingBudget(const Budget *budget);
int isWithinBudget(const Budget *budget);
void budgetMenu(Budget budgets[], int *count);
void addBudget(Budget budgets[], int *count);
void displayBudgets(const Budget budgets[], int count);
void searchBudget(const Budget budgets[], int count);

#endif
