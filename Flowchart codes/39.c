#include <stdio.h>

int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    return result;
}

int countDigits(int number) {
    int count = 0;
    while (number != 0) {
        number /= 10;
        ++count;
    }
    return count;
}

int isArmstrong(int number) {
    int originalNumber = number;
    int count = countDigits(number);
    int sum = 0;
    
    while (originalNumber != 0) {
        int digit = originalNumber % 10;
        sum += power(digit, count);
        originalNumber /= 10;
    }
    
    return sum == number;
}

int main() {
    int low, high;
    
    printf("Enter two numbers(intervals): ");
    scanf("%d %d", &low, &high);
    
    printf("Armstrong numbers between %d and %d are: ", low, high);

    // Ensure low is smaller than high
    if (high < low) {
        int temp = low;
        low = high;
        high = temp;
    }

    // Find Armstrong numbers in the given range
    for (int number = low + 1; number < high; ++number) {
        if (isArmstrong(number)) {
            printf("%d ", number);
        }
    }

    return 0;
}

