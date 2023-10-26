#include <stdio.h>
#include <stdlib.h>

// Define a structure for books
struct Book {
    char author_name[100];
    char book_name[100];
};

// Function to read n books and store them in an array using pointers
void readBooks(struct Book *books, int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter author name for book %d: ", i + 1);
        scanf("%s", books[i].author_name);
        printf("Enter book name for book %d: ", i + 1);
        scanf("%s", books[i].book_name);
    }
}

// Function to display n books using pointers
void displayBooks(struct Book *books, int n) {
    printf("List of Books:\n");
    for (int i = 0; i < n; i++) {
        printf("Book %d:\n", i + 1);
        printf("Author: %s\n", books[i].author_name);
        printf("Book Title: %s\n", books[i].book_name);
    }
}

int main() {
    int n;

    printf("Enter the number of books: ");
    scanf("%d", &n);

    // Create an array of books using dynamic memory allocation
    struct Book *books = (struct Book *)malloc(n * sizeof(struct Book));

    if (books == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Read books and display them
    readBooks(books, n);
    displayBooks(books, n);

    // Free the dynamically allocated memory
    free(books);

    return 0;
}
