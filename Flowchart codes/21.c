#include <stdio.h>

int main() {
    int startYear, endYear, count = 0;

    printf("Enter the start year: ");
    scanf("%d", &startYear);
    
    printf("Enter the end year: ");
    scanf("%d", &endYear);

    for (int year = startYear; year <= endYear; ++year) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            printf("%d\n", year);
            count++;
        }
    }

    printf("Total number of leap years: %d\n", count);

    return 0;
}

