// ------------------------------------------------------------------------------------------
// Name: Million Eyassu
// Class: C 1
// Abstract: Test 1
// ------------------------------------------------------------------------------------------

// ------------------------------------------------------------------------------------------
// Includes
// ------------------------------------------------------------------------------------------
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

// ------------------------------------------------------------------------------------------
// Prototypes
// ------------------------------------------------------------------------------------------
double getDiscountRate(int intYearsEmployed, char charEmployeeStatus);
void getInput(int* pintYearsEmployed, double* pdblPreviousPurchases, char* pcharEmployeeStatus, double* pdblTotalPurchase);
void processEmployee(int* pintHasAnotherEmployee, double* pdblYtdDiscountTotal, double* pdblTodayTotalBeforeDiscount, double* pdblTodayTotalAfterDiscount);

// ------------------------------------------------------------------------------------------
// Name: main
// Abstract: This is where the program starts
// ------------------------------------------------------------------------------------------
int main() {
    // Initialize variables
    int intHasAnotherEmployee = 1;
    double dblYtdDiscountTotal = 0.0;
    double dblTodayTotalBeforeDiscount = 0.0;
    double dblTodayTotalAfterDiscount = 0.0;

    // Process employees until user chooses to exit
    while (intHasAnotherEmployee) {
        processEmployee(&intHasAnotherEmployee, &dblYtdDiscountTotal, &dblTodayTotalBeforeDiscount, &dblTodayTotalAfterDiscount);
    }

    // Display summary of all employees
    printf("----------EMPLOYEE SUMMARY----------\n");
    printf("Total before discount for the day: $%.2lf\n", dblTodayTotalBeforeDiscount);
    printf("Total after discounts applied: $%.2lf\n", dblTodayTotalAfterDiscount);

    return 0;
}

// ------------------------------------------------------------------------------------------
// Name: getDiscountRate
// Abstract: Determines the discount rate based on years of employment and employee status
// ------------------------------------------------------------------------------------------
double getDiscountRate(int intYearsEmployed, char charEmployeeStatus) {
    if (intYearsEmployed >= 1 && intYearsEmployed <= 3) {
        return (charEmployeeStatus == 'M' || charEmployeeStatus == 'm') ? 0.2 : 0.1;
    }
    else if (intYearsEmployed >= 4 && intYearsEmployed <= 6) {
        return (charEmployeeStatus == 'M' || charEmployeeStatus == 'm') ? 0.24 : 0.14;
    }
    else if (intYearsEmployed >= 7 && intYearsEmployed <= 10) {
        return (charEmployeeStatus == 'M' || charEmployeeStatus == 'm') ? 0.3 : 0.2;
    }
    else if (intYearsEmployed >= 11 && intYearsEmployed <= 15) {
        return (charEmployeeStatus == 'M' || charEmployeeStatus == 'm') ? 0.35 : 0.25;
    }
    else if (intYearsEmployed > 15) {
        return (charEmployeeStatus == 'M' || charEmployeeStatus == 'm') ? 0.4 : 0.3;
    }
    return 0.0;
}

// ------------------------------------------------------------------------------------------
// Name: getInput
// Abstract: Gets input values for employee information
// ------------------------------------------------------------------------------------------
void getInput(int* pintYearsEmployed, double* pdblPreviousPurchases, char* pcharEmployeeStatus, double* pdblTotalPurchase) {
    // Prompts user, gets input, and then determines if it is the correct data type, greater than 0, not empty, and numeric
    printf("Number of years employed: ");
    while (scanf("%d", pintYearsEmployed) != 1 || *pintYearsEmployed <= 0) {
        printf("Invalid input. Please enter a valid number of years employed (numeric, >0): ");
        while (getchar() != '\n'); // Loops through string and clears until it reaches \n
    }

    printf("Total amount of previous purchases before discount: ");
    while (scanf("%lf", pdblPreviousPurchases) != 1 || *pdblPreviousPurchases < 0) {
        printf("Invalid input. Please enter a valid total amount of previous purchases (numeric, >=0): ");
        while (getchar() != '\n'); // Loops through string and clears until it reaches \n
    }

    printf("Employee status (M for manager, E for employee): ");
    while (scanf(" %c", pcharEmployeeStatus) != 1 || (*pcharEmployeeStatus != 'M' && *pcharEmployeeStatus != 'm' && *pcharEmployeeStatus != 'E' && *pcharEmployeeStatus != 'e')) {
        printf("Invalid input. Please enter a valid employee status (M for manager, E for employee): ");
        while (getchar() != '\n'); // Loops through string and clears until it reaches \n
    }

    printf("Total of today's purchase: ");
    while (scanf("%lf", pdblTotalPurchase) != 1 || *pdblTotalPurchase < 0) {
        printf("Invalid input. Please enter a valid total of today's purchase (numeric, >=0): ");
        while (getchar() != '\n');// Loops through string and clears until it reaches \n
    }
    printf("\n");
}



// ------------------------------------------------------------------------------------------
// Name: processEmployee
// Abstract: Processes the employee information and updates totals
// ------------------------------------------------------------------------------------------
void processEmployee(int* pintHasAnotherEmployee, double* pdblYtdDiscountTotal, double* pdblTodayTotalBeforeDiscount, double* pdblTodayTotalAfterDiscount) {
    int intYearsEmployed = 0;
    double dblPreviousPurchases = 0.0;
    char charEmployeeStatus = '\0';
    double dblTotalPurchase = 0.0;

    getInput(&intYearsEmployed, &dblPreviousPurchases, &charEmployeeStatus, &dblTotalPurchase);

    double dblDiscountRate = getDiscountRate(intYearsEmployed, charEmployeeStatus);

    double dblYtdDiscount = dblPreviousPurchases * dblDiscountRate;
    if (dblYtdDiscount >= 200.0) {
        dblYtdDiscount = 200.0;
    }

    double dblPurchaseDiscount = dblTotalPurchase * dblDiscountRate;
    if ((dblYtdDiscount + dblPurchaseDiscount) > 200.0) {
        dblPurchaseDiscount = 200.0 - dblYtdDiscount;
    }

    double dblTotalWithDiscount = dblTotalPurchase - dblPurchaseDiscount;

   // displayEmployeeInformation(*pintHasAnotherEmployee);

    // Prints Employee Info
    printf("----------EMPLOYEE INFORMATION----------\n");
    printf("Employee discount percentage: %.2lf%%\n", dblDiscountRate * 100);
    printf("YTD Amount of discount in dollars: $%.2lf\n", dblYtdDiscount);
    printf("Total purchase today before discount: $%.2lf\n", dblTotalPurchase);
    printf("Employee discount this purchase: $%.2lf\n", dblPurchaseDiscount);
    printf("Total with discount: $%.2lf\n", dblTotalWithDiscount);
    printf("\n");

    // adds values to pointers
    *pdblYtdDiscountTotal += dblYtdDiscount;
    *pdblTodayTotalBeforeDiscount += dblTotalPurchase;
    *pdblTodayTotalAfterDiscount += dblTotalWithDiscount;

    printf("Do you have another employee? (1 for Yes, 0 for No): ");
    while (scanf("%d", pintHasAnotherEmployee) != 1 || (*pintHasAnotherEmployee != 0 && *pintHasAnotherEmployee != 1)) {
        printf("Invalid input. Please enter a valid option (1 for Yes, 0 for No): ");
        while (getchar() != '\n'); // Clear input buffer
    }
    printf("\n");
}