#include <stdio.h>
#include <string.h>

void combineStrings(char str1[], char str2[]) {
    printf("Combinations:\n");
    
    // If-else statements to determine the order of combination
    if (strcmp(str1, str2) <= 0) {
        // First combination: str1 + str2
        printf("%s%s\n", str1, str2);
        // Second combination: str2 + str1
        printf("%s%s\n", str2, str1);
    } else {
        // First combination: str2 + str1
        printf("%s%s\n", str2, str1);
        // Second combination: str1 + str2
        printf("%s%s\n", str1, str2);
    }
}

int main() {
    char str1[50], str2[50];
    
    printf("Enter first string: ");
    scanf("%s", str1);
    
    printf("Enter second string: ");
    scanf("%s", str2);

    combineStrings(str1, str2);
    
    return 0;
}

