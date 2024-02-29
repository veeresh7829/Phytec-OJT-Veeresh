#include <stdio.h>

// Function to calculate factorial of a number
int factorial(int num)
{
    int fact = 1;
    if (num > 1)
    {
        for (int i = 2; i <= num; i++)
       	{
            fact =fact*i;
        }
    }
    return fact;
}

int main() 
{
    int n, sum = 0;

    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) 
    {
        sum = sum+factorial(i);
    }

    printf("Sum of factorials of the series up to %d is: %d\n", n, sum);

    return 0;
}

