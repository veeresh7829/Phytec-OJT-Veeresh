#include <stdio.h>

int main() {
    int day, month, year;

    // Input date from the user
    printf("Enter the date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    // Check if the month is valid
    if (month < 1 || month > 12) {
        printf("Invalid month entered!\n");
        return 1;
    }

    // Check if the day is valid for the given month
    if (day < 1 || day > 31) {
        printf("Invalid day entered!\n");
        return 1;
    }

    // Adjust month and year for Zeller's Congruence formula
    if (month < 3) {
        month += 12;
        year--;
    }

    // Apply Zeller's Congruence algorithm to find the day of the week
    int dayOfWeek = (day + (13 * (month + 1)) / 5 + year + year / 4 - year / 100 + year / 400) % 7;

    // Map the result to the corresponding day of the week
    char* days[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    // Output the result
    printf("The day of the week for %d-%d-%d is %s.\n", year, month, day, days[dayOfWeek]);

    return 0;
}

