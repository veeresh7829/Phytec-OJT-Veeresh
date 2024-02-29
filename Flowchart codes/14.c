#include <stdio.h>
int main() 
{
    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (int i = 0; i < rows; i++) 
    {
        int coef = 1;
        for (int space = 1; space <= rows - i; space++)
       	{
            printf("  "); // Printing spaces for formatting
        }
        for (int j = 0; j <= i; j++)
       	{
            if (j != 0)
	    {
                coef = coef * (i - j + 1) / j;
            }
            printf("%4d", coef); // Printing coefficients with proper formatting
        }
        printf("\n");
    }

    return 0;
}
 
