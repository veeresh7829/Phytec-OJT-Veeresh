#include <stdio.h>

int main() {
    int num, shift;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Enter the number of positions to right shift: ");
    scanf("%d", &shift);

    // Perform right shift
    num = num >> shift;

    printf("Result after right shifting: %d\n", num);

    return 0;
}

