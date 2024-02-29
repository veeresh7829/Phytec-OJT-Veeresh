#include <stdio.h>

int main()
{
    int n, reversedNumber = 0, r;

    printf("Enter an integer: ");
    scanf("%d", &n);

    while (n != 0)
    {
        r = n % 10;
        reversedNumber = reversedNumber * 10 + r;
        n = n/10;
    }

    printf("Reversed number: %d\n", reversedNumber);

    return 0;
}

