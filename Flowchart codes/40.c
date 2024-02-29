#include <stdio.h>

#define ROWS 3
#define COLS 3

int main() {
    int matrix[ROWS][COLS];
    int i, j;

    // Input matrix elements from the user
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("Enter element at position (%d, %d): ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    // Display the matrix using if-else statements
    printf("\nMatrix:\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]); // Print the element followed by a tab
        }
        printf("\n"); // Move to the next row after printing all elements in a row
    }

    return 0;
}

