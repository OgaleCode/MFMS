# MFMS
## Municipal Financial Management System - PAP521S Project A
## Development Environment: ** Visual Studio Code + GCC (ANSI C / C99)  

---

## Group Members & Individual Responsibilities
* **Student 1 Dylan Esau (220087318):** Employee Management Module
* **Student 2 Hendrina Shifeleni (226164519):** Budget Management Module
* **Student 3 Magdalena Jakob (226037967):** Supplier Management Module
* **Student 4 Ryan Kamolakwamwe (226051625):** Asset Management Module
* **Student 5 Catherine Shiimi (226094901):** System Reports Module
* **Student 6 Katjimune Marry (226048373):** Functions, Integration, and Data Validation
* **Student 7 Elago Niilenge (226016153):** Testing, Documentation, and Git Coordination

---

## Project Description
The Municipal Financial Management System (MFMS) is a foundational, menu-driven command-line application developed in ANSI C (C99) for municipal operations. The system enables local government authorities to track personnel records, monitor departmental budget allocations and expenditure, manage supplier information, maintain an asset register, and generate summary financial reports.

---

## System Features
* **Employee Management:** Add, display, and search employee records, as well as calculate basic salary, housing allowances, and transport allowances.
* **Budget Management:** Record departmental budget allocations, track expenditure, calculate remaining balances, and highlight departments exceeding budget constraints.
* **Supplier Management:** Store contact and location details for municipal suppliers and enable searching and comparison of supplier records.
* **Asset Management:** Register municipal assets (such as vehicles, equipment, and buildings), track purchase values, and display asset registers.
* **Reports Module:** Generate summary reports covering employee salaries, budget statuses, supplier lists, and registered assets.

---

## Compilation Instructions
To compile the system using the GCC compiler in VS Code or Terminal, run:

```bash
gcc -std=c99 main.c employees.c budget.c suppliers.c assets.c reports.c -o mfms