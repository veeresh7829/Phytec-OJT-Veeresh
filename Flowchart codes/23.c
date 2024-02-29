#include <stdio.h>

int main() {
    int num;
    
    // Input the number
    printf("Enter a number: ");
    scanf("%d", &num);

    // Find the position of the LSB
    int lsb_position = 0;
    while (num % 2 == 0 && num != 0) {
        num /= 2;
        lsb_position++;
    }

    printf("Position of LSB is: %d\n", lsb_position);

    return 0;
}

