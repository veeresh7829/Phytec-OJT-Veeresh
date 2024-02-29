#include <stdio.h>

int main() {
    int start, end;

    printf("Enter the start of the range: ");
    scanf("%d", &start);

    printf("Enter the end of the range: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are: ", start, end);

    for (int i = start; i <= end; ++i) {
        int isPrime = 1; // Assume i is prime initially

        if (i <= 1) {
            continue; // Skip 0 and 1 as they are not prime
        }

        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0) {
                isPrime = 0; // i is not prime
                break;
            }
        }

        if (isPrime) {
            printf("%d ", i); // Print prime number
        }
    }
    printf("\n");

    return 0;
}

