#include <stdio.h>

#define ROWS1 3
#define COLS1 3
#define ROWS2 3
#define COLS2 3

void matrixMultiply(int mat1[ROWS1][COLS1], int mat2[ROWS2][COLS2], int result[ROWS1][COLS2]) {
    int i, j, k;

    // Initialize result matrix with zeros
    for (i = 0; i < ROWS1; i++) {
        for (j = 0; j < COLS2; j++) {
            result[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (i = 0; i < ROWS1; i++) {
        for (j = 0; j < COLS2; j++) {
            for (k = 0; k < COLS1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void displayMatrix(int mat[ROWS1][COLS2]) {
    int i, j;

    for (i = 0; i < ROWS1; i++) {
        for (j = 0; j < COLS2; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int mat1[ROWS1][COLS1] = {{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    int mat2[ROWS2][COLS2] = {{9, 8, 7},
                               {6, 5, 4},
                               {3, 2, 1}};

    int result[ROWS1][COLS2];

    // Multiply matrices
    matrixMultiply(mat1, mat2, result);

    // Display the result
    printf("Result of matrix multiplication:\n");
    displayMatrix(result);

    return 0;
}

