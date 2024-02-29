#include <stdio.h>

// Function to calculate determinant of a 2x2 matrix
float determinant(float a, float b, float c, float d) {
    return a * d - b * c;
}

int main() {
    float matrix[3][3];
    printf("Enter the elements of the 3x3 matrix:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Calculate determinant
    float det = determinant(matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]) * matrix[2][2] -
                determinant(matrix[0][0], matrix[0][2], matrix[1][0], matrix[1][2]) * matrix[2][1] +
                determinant(matrix[0][1], matrix[0][2], matrix[1][1], matrix[1][2]) * matrix[2][0];

    // Check if the matrix is singular
    if (det == 0) {
        printf("The matrix is singular. Inverse does not exist.\n");
    } else {
        // Calculate the inverse
        float inverse[3][3];
        inverse[0][0] =  determinant(matrix[1][1], matrix[1][2], matrix[2][1], matrix[2][2]) / det;
        inverse[0][1] = -determinant(matrix[0][1], matrix[0][2], matrix[2][1], matrix[2][2]) / det;
        inverse[0][2] =  determinant(matrix[0][1], matrix[0][2], matrix[1][1], matrix[1][2]) / det;
        inverse[1][0] = -determinant(matrix[1][0], matrix[1][2], matrix[2][0], matrix[2][2]) / det;
        inverse[1][1] =  determinant(matrix[0][0], matrix[0][2], matrix[2][0], matrix[2][2]) / det;
        inverse[1][2] = -determinant(matrix[0][0], matrix[0][2], matrix[1][0], matrix[1][2]) / det;
        inverse[2][0] =  determinant(matrix[1][0], matrix[1][1], matrix[2][0], matrix[2][1]) / det;
        inverse[2][1] = -determinant(matrix[0][0], matrix[0][1], matrix[2][0], matrix[2][1]) / det;
        inverse[2][2] =  determinant(matrix[0][0], matrix[0][1], matrix[1][0], matrix[1][1]) / det;

        // Print the inverse matrix
        printf("Inverse of the matrix:\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                printf("%.2f\t", inverse[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}

