#include <stdio.h>

int main() {
    int num, ls;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Enter the number of positions to left shift: ");
    scanf("%d", &ls);

    // Perform left shift
    num = num << ls;

    printf("Result after left shifting: %d\n", num);

    return 0;
}

