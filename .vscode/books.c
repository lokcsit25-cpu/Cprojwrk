#include<stdio.h>
struct books{
    char book_name[50];
    char issued_date[50];
    char author_name[50];
    char category[30];
    int price;
};
int main(){
    struct books lib[24];  // creating object of books
    FILE *fp;  // making file pointer
    fp=fopen("books.txt","w");  // making the file in write mode
    // writing details of books
    printf("Enter details of books:\n");
    for(int i=0;i<24;i++){
        printf("Book %d name:",i+1);
        fgets(lib[i].book_name,sizeof(lib[i].book_name),stdin);
        printf("Issued Date (DD-MM-YYYY):");
        fgets(lib[i].issued_date,sizeof(lib[i].issued_date),stdin);
        printf("Author name:");
        fgets(lib[i].author_name,sizeof(lib[i].author_name),stdin);
        printf("Category of book %d:",i+1);
        fgets(lib[i].category,sizeof(lib[i].category),stdin);
        printf("Price of book %d:",i+1);
        scanf("%d",&lib[i].price);
        getchar();  // to consume the newline character left by scanf
    
       // writing whole line to the file
       fprintf(fp,"%s %s %s %s %d\n",lib[i].book_name,lib[i].issued_date,lib[i].author_name,lib[i].category,lib[i].price);
    }
    printf("Written successfully!");
    fclose(fp);
}