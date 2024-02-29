#include <stdio.h>

int main() {
    int num, n;
    
    // Input number and bit position from the user
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("Enter the position of the bit (0-indexed) to toggle: ");
    scanf("%d", &n);
    
    // Toggling the nth bit
    num ^= (1 << n);

    // Output the modified number
    printf("Number after toggling %dth bit: %d\n", n, num);
    
    return 0;
}

