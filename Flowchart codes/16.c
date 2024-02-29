#include <stdio.h>

int main() 
{
    float m1, c1, m2, c2;

    printf("Enter the slope and y-intercept of line 1: ");
    scanf("%f %f", &m1, &c1);

    printf("Enter the slope and y-intercept of line 2: ");
    scanf("%f %f", &m2, &c2);

    if (m1 == m2) 
    {
        printf("The two lines are parallel.\n");
    } 
    else 
    {
        printf("The two lines are not parallel.\n");
    }

    return 0;
}

