// wap to read the highest price of  books recorded in the library.txt file and calculate the total price of all books
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
void readBooks() {
    struct Book book;
    FILE *file = fopen("library.txt", "r");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }
    int highest_price = 0;
    int total_price = 0;
    while (fscanf(file, "%[^\t]\t%[^\t]\t%[^\t]\t%[^\t]\t%d\n", book.name, book.author, book.category, book.issued_date, &book.price) == 5) {
        if (book.price > highest_price) {
            highest_price = book.price;
        }
        total_price += book.price;
    }
    fclose(file);
    printf("Highest price of books: %d\n", highest_price);
    printf("Total price of all books: %d\n", total_price);
}
int main() {
    readBooks();
    return 0;
}
