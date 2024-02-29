#include <stdio.h>

int main() {
    int num, n;
    
    // Input number and bit position from the user
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter the position of the bit (0-indexed): ");
    scanf("%d", &n);
    
    // Shift 1 to the left by n positions
    int mask = 1 << n;

    // Check if the nth bit is set or not using if statement
    if (num & mask) {
        printf("The %dth bit in %d is set (1).\n", n, num);
    } else {
        printf("The %dth bit in %d is not set (0).\n", n, num);
    }
    
    return 0;
}

