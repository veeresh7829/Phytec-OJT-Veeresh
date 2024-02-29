#include <stdio.h>

int main()
{
    int rows;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    for (int i = 1; i <= rows; i++)
    {
        int j = 1;
        if (i > 1)
       	{
            while (j < i)
	    {
                printf(" ");
                j++;
            }
        }
        j = i;
        while (j <= rows)
       	{
            printf("* ");
            j++;
        }
        printf("\n");
    }

    return 0;
}

