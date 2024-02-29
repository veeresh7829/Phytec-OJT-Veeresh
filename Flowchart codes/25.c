#include <stdio.h>

#define ROWS 3
#define COLS 3

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int matrix[ROWS][COLS], transpose[COLS][ROWS];

    // Input the matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            scanf("%d", &matrix[i][j]);

    // Compute the transpose
    for (int i = 0; i < ROWS; i++) {
        for (int j = i; j < COLS; j++) {
            if (i != j) {
                swap(&matrix[i][j], &matrix[j][i]);
            }
        }
    }

    // Print the transpose
    printf("Transpose of the matrix:\n");
    for (int i = 0; i < COLS; i++) {
        for (int j = 0; j < ROWS; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }

    return 0;
}


