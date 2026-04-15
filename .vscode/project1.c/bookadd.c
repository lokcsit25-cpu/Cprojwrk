#include<stdio.h>
#include <string.h>
#include<stdlib.h>;

struct Name {
    char book_name[50];
    char author_name[50];
};

struct issued_date {
    int day, month, year;
};

struct book {
    char category[50];
    int price;
    struct Name name;
    struct issued_date date;
};

void addBook(FILE *fp) {
    struct book lib;

    printf("Enter book name: ");
    gets(lib.name.book_name);

    printf("Enter author name: ");
    gets(lib.name.author_name);

    printf("Enter category: ");
    gets(lib.category);

    printf("Enter issued date (DD MM YYYY): ");
    scanf("%d %d %d", &lib.date.day, &lib.date.month, &lib.date.year);

    printf("Enter price: ");
    scanf("%d", &lib.price);
    getchar(); // consume newline

    // Write to file
    fprintf(fp, "%s\t%-4s\t%02d-%02d-%04d\t%s\t%d\n",
            lib.name.book_name,
            lib.name.author_name,
            lib.date.day, lib.date.month, lib.date.year,
            lib.category,
            lib.price);
}

int main() {
    FILE *fp = fopen("library.txt", "w");
    if (fp == NULL) {
        printf("File not found!\n");
        return 0;
    }

    int book_num, i;
    printf("Enter number of books: ");
    scanf("%d", &book_num);
    getchar(); // consume newline

    fprintf(fp, "Book Name\t\tAuthor Name\tIssued Date\tCategory\t\tPrice\n");
    fprintf(fp, "-------------------------------------------------------------------------------------\n");

    for (i = 0; i < book_num; i++) {
        printf("\nEnter details of book %d\n", i + 1);
        addBook(fp);
    }

    fclose(fp);
    printf("\nBooks saved to library.txt successfully!\n");
    return 0;
}
