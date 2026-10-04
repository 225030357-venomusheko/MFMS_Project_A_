# PAP521S – Municipal Financial Management System (MFMS)

## Project A – Foundation System

**Language:** ANSI C (C99)  
**Compiler:** GCC  
**Recommended IDE:** Visual Studio Code  
**Version Control:** Git & GitHub

## Group Members

Genofefa Venomusheko - 225030357
Jordan Nakale - 225123576 
Asteria N Ausiku - 224080563
Izane Rocheta Barman - 224027514
Linda Mutileni - 223138266
Raphael Hatzkin - 224091581
Hanseb Maandag - 225041707

## 1. Project Description

The Municipal Financial Management System (MFMS) is a menu-driven C application designed as the foundation version of a municipal financial management system. It manages employees, departmental budgets, suppliers and municipal assets and produces basic reports.

## 2. System Features

- Main menu with clear navigation
- Employee management
  - Add employees
  - Display employees
  - Search by employee name or department
  - Calculate total salary
- Budget management
  - Record departmental budgets
  - Record expenditure
  - Calculate remaining budget
  - Identify departments over budget
- Supplier management
  - Add suppliers
  - Display suppliers
  - Search by name or location
- Asset management
  - Register assets
  - Display assets
  - Search by name, type or department
- Reports
  - Employee report
  - Budget report
  - Supplier report
  - Asset report
- Input validation for menu choices, numbers and empty text fields
- Modular C source files using header files and functions

## 3. Project Structure

MFMS/
- main.c
- input.c
- input.h
- employees.c
- employees.h
- budget.c
- budget.h
- suppliers.c
- suppliers.h
- assets.c
- assets.h
- reports.c
- reports.h
- README.md
- TECHNICAL_REPORT.md
- INDIVIDUAL_CONTRIBUTION.md

## 4. Compilation

Ensure GCC compiler is installed.
Open a terminal in the project directory.
Compile the program using:
gcc main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms
Run the program:
On Linux/Mac:
./mfms
On Windows:
mfms.exe

## 5. How to Run

1. Start the program.
2. Select a module from the main menu.
3. Add records before attempting searches or reports.
4. Use the module menus to display and search records.
5. Use Reports to view calculated summaries.
6. Select Exit from the main menu to close the program.

## 6. Group Responsibilities

| Member | Responsibility |

| Izane Rocheta Barman | Employee Management |

| Jordan Nakale | Budget Management |

| Linda Mutileni | Supplier Management |

| Raphael Hatzkin | Asset Management |

| Maandag Hanseb | Reports |

| Asteria N Ausiku | Functions, integration and validation |

| Genofefa Venomusheko | Testing, documentation and Git coordination |


## 7. GitHub Workflow

The project was developed collaboratively using GitHub to ensure proper version control, transparency, and equal contribution from all group members.

Repository Setup
-A central GitHub repository was created for the project, and all group members were added as collaborators. The repository follows a structured layout with separate source files for each module.

Development Process
-Each group member was responsible for a specific module. Members cloned the repository to their local machines and worked on their assigned components independently. Changes were made incrementally, and members committed their work regularly using meaningful commit messages. This ensured that progress was tracked and contributions were clearly visible.

Version Control Practices
* Each member used `git add`, `git commit`, and `git push` to upload their work
* Members frequently used `git pull` to stay updated with the latest changes
* Work was integrated continuously to avoid conflicts and ensure compatibility between modules
* The project was not developed on a single machine; all members contributed individually

https://github.com/225030357-venomusheko/MFMS_Project_A_

## 8. Testing Checklist

- [ ] Main menu accepts valid choices.
- [ ] Invalid menu choices are rejected.
- [ ] Negative salaries are rejected.
- [ ] Negative budgets are rejected.
- [ ] Empty names are rejected.
- [ ] Duplicate IDs are rejected.
- [ ] Employee salary totals are calculated correctly.
- [ ] Budget balances are calculated correctly.
- [ ] Over-budget departments are identified.
- [ ] Supplier records can be searched.
- [ ] Asset records can be searched.
- [ ] Reports calculate correct totals and averages.
- [ ] Program returns safely to previous menus.
- [ ] Program exits correctly.
