#include <stdio.h>

struct Rectangle 
{
    float length;
    float width;
};

int main() 
{
    struct Rectangle rect;

    printf("Enter length of rectangle: ");
    scanf("%f", &rect.length);
    printf("Enter width of rectangle: ");
    scanf("%f", &rect.width);

    printf("\nRectangle Properties\n");
    printf("Length: %.2f\n", rect.length);
    printf("Width: %.2f\n", rect.width);
    printf("Area: %.2f\n", rect.length * rect.width);
    printf("Perimeter: %.2f\n", 2 * (rect.length + rect.width));

    return 0;
}

