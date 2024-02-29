#include <stdio.h>

int main() {
    int hours, minutes;

    // Input Indian time
    printf("Enter Indian time (hh:mm): ");
    scanf("%d:%d", &hours, &minutes);

    // Convert Indian time to London time
    hours -= 5;
    minutes -= 30;

    // Adjust negative minutes
    if (minutes < 0) {
        minutes += 60;
        hours -= 1;
    }

    // Adjust negative hours
    if (hours < 0) {
        hours += 24;
    }

    // Output London time
    printf("London time is: %.2d:%.2d\n", hours, minutes);

    return 0;
}

