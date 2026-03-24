// to display  books by specific author
#include<stdio.h>
#include<string.h>
struct library{
    char book_name[50];
    char author_name[50];
    char category[50];
    char issued_date[50];
    int price;
};
int main()
{
    struct library lib[24];
    int n, i;
    char search_author[50];

    printf("Enter the number of books: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter title of book %d: ", i + 1);
        scanf("%s", lib[i].book_name);
        printf("Enter author of book %d: ", i + 1);
        scanf("%s", lib[i].author_name);
        printf("Enter category of book %d: ", i + 1);
        scanf("%s", lib[i].category);
        printf("Enter issued date of book %d: ", i + 1);
        scanf("%s", lib[i].issued_date);
        printf("Enter price of book %d: ", i + 1);
        scanf("%d", &lib[i].price);
    }

    printf("Enter the author to search for: ");
    scanf("%s", search_author);

    printf("Books by %s:\n", search_author);
    for(i = 0; i < n; i++)
    {
        if(strcmp(lib[i].author_name,search_author) == 0)
        {
            printf("Title: %s, Category: %s, Issued Date: %s, Price: %d\n", lib[i].book_name, lib[i].category, lib[i].issued_date, lib[i].price);
        }
    }

    return 0;
}