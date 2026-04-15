#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

void readBooks(FILE *fp) {
    struct book lib;
    char line[200];

    // Skip header lines
    fgets(line, sizeof(line), fp);
    fgets(line, sizeof(line), fp);

    printf("\n%-25s %-20s %-12s %-15s %-6s\n", 
           "Book Name", "Author Name", "Issued Date", "Category", "Price");
    printf("----------------------------------------------------------------------------------\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        // Parse the line: Book Name\tAuthor Name\tDD-MM-YYYY\tCategory\tPrice
        char *token = strtok(line, "\t");
        if (token == NULL) continue;
        strcpy(lib.name.book_name, token);

        token = strtok(NULL, "\t");
        if (token == NULL) continue;
        strcpy(lib.name.author_name, token);

        token = strtok(NULL, "\t");
        if (token == NULL) continue;
        sscanf(token, "%d-%d-%d", &lib.date.day, &lib.date.month, &lib.date.year);

        token = strtok(NULL, "\t");
        if (token == NULL) continue;
        strcpy(lib.category, token);

        token = strtok(NULL, "\t");
        if (token == NULL) continue;
        lib.price = atoi(token);

        printf("%-25s %-20s %02d-%02d-%04d %-15s %-6d\n",
               lib.name.book_name,
               lib.name.author_name,
               lib.date.day, lib.date.month, lib.date.year,
               lib.category,
               lib.price);
    }
}
int main() {
    FILE *fp = fopen("library.txt", "r");
    if (fp == NULL) {
        printf("File not found!\n");
        return 0;
    }

    readBooks(fp);
    fclose(fp);
    return 0;
}
