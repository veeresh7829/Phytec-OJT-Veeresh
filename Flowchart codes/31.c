#include <stdio.h>

// Function to calculate the Greatest Common Divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate the LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int result = 1;
    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);
        result = lcm(result, num);
    }

    printf("LCM of the numbers is: %d\n", result);

    return 0;
}

