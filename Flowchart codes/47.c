#include <stdio.h>

int main() {
    float real1, imag1, real2, imag2;
    
    printf("Enter the real and imaginary parts of the first complex number: ");
    scanf("%f %f", &real1, &imag1);
    
    printf("Enter the real and imaginary parts of the second complex number: ");
    scanf("%f %f", &real2, &imag2);

    // Check if the denominator is zero
    if (real2 == 0 && imag2 == 0) {
        printf("Error! Division by zero is not allowed.\n");
        return 1; // Return with error status
    }

    // Perform division
    float real_result = (real1 * real2 + imag1 * imag2) / (real2 * real2 + imag2 * imag2);
    float imag_result = (imag1 * real2 - real1 * imag2) / (real2 * real2 + imag2 * imag2);

    printf("Result of division: %.2f + %.2fi\n", real_result, imag_result);
    
    return 0;
}

