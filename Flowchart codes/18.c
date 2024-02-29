#include <stdio.h>

int main() {
    int size;
    printf("Enter the size of square matrix: ");
    scanf("%d", &size);

    int sum = 0;
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            int element;
            scanf("%d", &element);
            if (i >= j) {
                printf("%d ", element);
                sum += element;
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    printf("Sum of elements in the lower triangle: %d\n", sum);

    return 0;
}

