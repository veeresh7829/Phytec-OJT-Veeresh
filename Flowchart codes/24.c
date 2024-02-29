#include <stdio.h>

int main() {
    int num;
    
    // Input the number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Find the position of the MSB
    int msb_position = 0;
    while (num > 1) {
        num /= 2;
        msb_position++;
    }

    printf("Position of MSB is: %d\n", msb_position);

    return 0;
}

