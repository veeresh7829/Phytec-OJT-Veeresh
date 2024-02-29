#include <stdio.h>

int main() {
    int decimalNumber, quotient, remainder;
    char hexadecimalNumber[100];
    int i = 0;

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    quotient = decimalNumber;

    while (quotient != 0) {
        remainder = quotient % 16;

        // Convert remainder to hexadecimal character
        if (remainder < 10)
            hexadecimalNumber[i++] = remainder + '0';
        else
            hexadecimalNumber[i++] = remainder + 'A' - 10;

        quotient = quotient / 16;
    }

    printf("Hexadecimal equivalent of %d is: ", decimalNumber);
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimalNumber[j]);
    printf("\n");

    return 0;
}

