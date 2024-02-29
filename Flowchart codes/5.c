#include <stdio.h>

int main()
{
    int num1, num2, num3, num4;

    printf("Enter four numbers: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    int max, min;

    // Assume num1 as both max and min initially
    max = num1;
    min = num1;

    // Compare num2 with max and min
    if (num2 > max)
    {
        max = num2;
    }
    else if (num2 < min) 
    {
        min = num2;
    }

    // Compare num3 with max and min
    if (num3 > max)
    {
        max = num3;
    }
    else if (num3 < min)
    {
        min = num3;
    }

    // Compare num4 with max and min
    if (num4 > max)
    {
        max = num4;
    }
    else if (num4 < min) 
    {
        min = num4;
    }

    printf("Maximum number: %d\n", max);
    printf("Minimum number: %d\n", min);

    return 0;
}

