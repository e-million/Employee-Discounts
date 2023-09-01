# Employee-Discount

## Introduction

This C program is designed to calculate employee discounts based on years of employment and employee status. It allows you to input employee information and calculate discounts for each employee's purchase. The program keeps track of year-to-date (YTD) discounts and provides a summary of all employees processed.

1. Run the Program: Execute the compiled program:
  ./employee_discount_calculator

2. Input Employee Information: Follow the prompts to input employee details such as years   employed,   previous purchases, employee status (Manager or Employee), and the total purchase for the day.

3. Repeat for Additional Employees: You can process multiple employees one after the other. The program will continue to ask if you have another employee to process.

4. View Summary: After processing all employees, the program will display a summary, including the total purchases before and after discounts are applied.

**Employee Discounts**
Discount rates are determined as follows:

- For employees with 1 to 3 years of employment:
  - Managers (M or m): 20%
  - Employees (E or e): 10%

- For employees with 4 to 6 years of employment:
  - Managers (M or m): 24%
  - Employees (E or e): 14%

- For employees with 7 to 10 years of employment:
  - Managers (M or m): 30%
  - Employees (E or e): 20%

- For employees with 11 to 15 years of employment:
  - Managers (M or m): 35%
  - Employees (E or e): 25%

For employees with more than 15 years of employment:
  - Managers (M or m): 40%
  - Employees (E or e): 30%

**Sample Output** 
----------EMPLOYEE SUMMARY----------
Total before discount for the day: $xyz
Total after discounts applied: $abc
