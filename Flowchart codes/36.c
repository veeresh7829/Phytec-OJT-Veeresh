#include <stdio.h>

// Function to convert binary to octal
void binaryToOctal(char binary[]) {
    int decimal = 0;
    sscanf(binary, "%d", &decimal);
    printf("Octal equivalent: %o\n", decimal);
}

int main() {
    char binary[20];
    printf("Enter a binary number: ");
    scanf("%s", binary);
    binaryToOctal(binary);
    return 0;
}

