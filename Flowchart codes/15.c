#include <stdio.h>

int main()
{
    int start, end, sum = 0;

    printf("Enter the starting range: ");
    scanf("%d", &start);
    printf("Enter the ending range: ");
    scanf("%d", &end);

    if (start == end)
    {
        printf("Invalid input. Starting range cannot be equal to ending range.\n");
        return 1;
    }

    if (start > end)
    {
        int temp = start;
        start = end;
        end = temp;
    }

    for (int i = start; i <= end; i++)
    {
        if (i % 5 != 0)
       	{
            sum =sum+ i;
        }
    }

    printf("Sum of numbers not divisible by 5 in the range %d to %d is: %d\n", start, end, sum);

    return 0;
}

