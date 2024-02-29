#include <stdio.h>

     // Function to convert binary to hexadecimal
void binaryToHexadecimal(char binary[]) {
    int decimal = 0;
    sscanf(binary, "%d", &decimal);
    printf("Hexadecimal equivalent: %X\n", decimal);
}

int main() {
    char binary[20];
    printf("Enter a binary number: ");
    scanf("%s", binary);
    binaryToHexadecimal(binary);
    return 0;
}

