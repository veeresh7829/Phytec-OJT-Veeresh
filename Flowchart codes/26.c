#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    // Check if lengths are different
    if (len1 != len2) {
        printf("Strings are not anagrams.\n");
        return 0;
    }

    // Sort both strings
    for (int i = 0; i < len1 - 1; i++) {
        for (int j = i + 1; j < len1; j++) {
            if (str1[i] > str1[j]) {
                char temp = str1[i];
                str1[i] = str1[j];
                str1[j] = temp;
            }
            if (str2[i] > str2[j]) {
                char temp = str2[i];
                str2[i] = str2[j];
                str2[j] = temp;
            }
        }
    }

    // Check if sorted strings are equal
    if (strcmp(str1, str2) == 0)
        printf("Strings are anagrams.\n");
    else
        printf("Strings are not anagrams.\n");

    return 0;
}

