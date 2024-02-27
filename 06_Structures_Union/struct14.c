#include <stdio.h>

#define MAX_EMPLOYEES 100

struct Employee 
{
    char name[50];
    int employeeID;
    float salary;
};

int main()
{
    int numEmployees;
    printf("Enter the number of employees: ");
    scanf("%d", &numEmployees);

    if (numEmployees < 1 || numEmployees > MAX_EMPLOYEES) {
        printf("Invalid number of employees. Please enter a number between 1 and %d.\n", MAX_EMPLOYEES);
        return 1; // Exit with error
    }

    struct Employee employees[MAX_EMPLOYEES];

    for (int i = 0; i < numEmployees; i++)
    {
        printf("\nEnter details for employee %d:\n", i + 1);
        printf("Enter employee name: ");
        scanf("%s", employees[i].name);
        printf("Enter employee ID: ");
        scanf("%d", &employees[i].employeeID);
        printf("Enter employee salary: ");
        scanf("%f", &employees[i].salary);
    }

    printf("\nEmployee Details\n");
    for (int i = 0; i < numEmployees; i++)
    {
        printf("\nDetails for employee %d:\n", i + 1);
        printf("Name: %s\n", employees[i].name);
        printf("Employee ID: %d\n", employees[i].employeeID);
        printf("Salary: %.2f\n", employees[i].salary);
    }

    return 0;
}

