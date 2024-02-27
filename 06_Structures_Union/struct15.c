#include <stdio.h>

#define MAX_BOOKS 100

struct Book 
{
    char title[100];
    char author[50];
    int pages;
};

int main()
{
    int numBooks;
    printf("Enter the number of books: ");
    scanf("%d", &numBooks);

    if (numBooks < 1 || numBooks > MAX_BOOKS) {
        printf("Invalid number of books. Please enter a number between 1 and %d.\n", MAX_BOOKS);
        return 1; // Exit with error
    }

    struct Book books[MAX_BOOKS];

    for (int i = 0; i < numBooks; i++) 
    {
        printf("\nEnter details for book %d:\n", i + 1);
        printf("Enter book title: ");
        scanf("%s", books[i].title);
        printf("Enter book author: ");
        scanf("%s", books[i].author);
        printf("Enter number of pages: ");
        scanf("%d", &books[i].pages);
    }

    printf("\nBook Details\n");
    for (int i = 0; i < numBooks; i++)
    {
        printf("\nDetails for book %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Pages: %d\n", books[i].pages);
    }

    return 0;
}

