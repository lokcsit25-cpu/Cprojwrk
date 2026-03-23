// to dissplay  books by specific author
#include<stdio.h>
#include<string.h>
struct book
{
    char title[50];
    char author[50];
    int year;
};
int main()
{
    struct book library[100];
    int n, i;
    char search_author[50];

    printf("Enter the number of books: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter title of book %d: ", i + 1);
        scanf("%s", library[i].title);
        printf("Enter author of book %d: ", i + 1);
        scanf("%s", library[i].author);
        printf("Enter publication year of book %d: ", i + 1);
        scanf("%d", &library[i].year);
    }

    printf("Enter the author to search for: ");
    scanf("%s", search_author);

    printf("Books by %s:\n", search_author);
    for(i = 0; i < n; i++)
    {
        if(strcmp(library[i].author, search_author) == 0)
        {
            printf("Title: %s, Year: %d\n", library[i].title, library[i].year);
        }
    }

    return 0;
}