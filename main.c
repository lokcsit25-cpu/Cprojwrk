#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[100];
    int year;
    int available;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Library is full!\n");
        return;
    }
    Book b;
    printf("Enter book ID: ");
    scanf("%d", &b.id);
    printf("Enter title: ");
    scanf(" %[^\n]", b.title);
    printf("Enter author: ");
    scanf(" %[^\n]", b.author);
    printf("Enter year: ");
    scanf("%d", &b.year);
    b.available = 1;
    library[bookCount++] = b;
    printf("Book added successfully!\n");
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books in library.\n");
        return;
    }
    printf("Library Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d, Title: %s, Author: %s, Year: %d, Available: %s\n",
               library[i].id, library[i].title, library[i].author, library[i].year,
               library[i].available ? "Yes" : "No");
    }
}

void searchBook() {
    char title[100];
    printf("Enter title to search: ");
    scanf(" %[^\n]", title);
    for (int i = 0; i < bookCount; i++) {
        if (strcmp(library[i].title, title) == 0) {
            printf("Found: ID: %d, Title: %s, Author: %s, Year: %d, Available: %s\n",
                   library[i].id, library[i].title, library[i].author, library[i].year,
                   library[i].available ? "Yes" : "No");
            return;
        }
    }
    printf("Book not found.\n");
}

void removeBook() {
    int id;
    printf("Enter book ID to remove: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (library[i].id == id) {
            for (int j = i; j < bookCount - 1; j++) {
                library[j] = library[j + 1];
            }
            bookCount--;
            printf("Book removed successfully!\n");
            return;
        }
    }
    printf("Book not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nLibrary Record Keeping System\n");
        printf("1. Add Book\n");
        printf("2. Display Books\n");
        printf("3. Search Book\n");
        printf("4. Remove Book\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                removeBook();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}