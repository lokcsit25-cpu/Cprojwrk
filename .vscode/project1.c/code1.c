// wap to enter the data of 24 books including name author name category issued date and price for the library record keeping system using file handling and structure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Book {
    char name[50];
    char author[50];
    char category[20];
    char issued_date[20];
    int price;
};
void addBook() {
    struct Book book;
    FILE *file = fopen("library.txt", "a");  // Changed to "a" (append) mode
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    printf("Enter book name: ");
    fgets(book.name, sizeof(book.name), stdin);
    book.name[strcspn(book.name, "\n")] = 0; // Remove newline character
    printf("Enter author name: ");
    fgets(book.author, sizeof(book.author), stdin);
    book.author[strcspn(book.author, "\n")] = 0; // Remove newline character
    printf("Enter category: ");
    fgets(book.category, sizeof(book.category), stdin);
    book.category[strcspn(book.category, "\n")] = 0; // Remove newline character
    printf("Enter issued date: ");
    fgets(book.issued_date, sizeof(book.issued_date), stdin);
    book.issued_date[strcspn(book.issued_date, "\n")] = 0; // Remove newline character
    printf("Enter price: ");
    scanf("%d", &book.price);
    getchar(); // Consume the newline character left by scanf
    fprintf(file, "%s\t%s\t%s\t%s\t%d\n", book.name, book.author, book.category, book.issued_date, book.price);
    fclose(file);
}
int main() {
    for (int i = 0; i < 4; i++) {
        printf("Enter details for book %d:\n", i + 1);
        addBook();
    }
    return 0;
}
