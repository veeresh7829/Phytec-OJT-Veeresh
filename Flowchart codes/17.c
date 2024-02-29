#include <stdio.h>

int main() 
{
    int seconds;

    printf("Enter the number of seconds: ");
    scanf("%d", &seconds);

    int hours = seconds / 3600; // Calculate hours
    int minutes = (seconds % 3600) / 60; // Calculate remaining minutes
    int remainingSeconds = seconds % 60; // Calculate remaining seconds

    printf("The time in hours:minutes:seconds format is: %d:%d:%d\n", hours, minutes, remainingSeconds);

    return 0;
}

