#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    // Sort the characters in the string
    for (int i = 0; str[i] != '\0'; ++i) {
        for (int j = i + 1; str[j] != '\0'; ++j) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    printf("The string in alphabetical order: %s\n", str);

    return 0;
}

