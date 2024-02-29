#include <stdio.h>

int main() {
    float matrix[3][3];
    printf("Enter the elements of the 3x3 matrix:\n");
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            scanf("%f", &matrix[i][j]);

    float det = 0;

    // Calculate the determinant
    det += matrix[0][0] * (matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1]);
    det -= matrix[0][1] * (matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0]);
    det += matrix[0][2] * (matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0]);

    printf("Determinant of the matrix is: %.2f\n", det);

    return 0;
}

