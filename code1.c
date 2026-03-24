// wap to enter the name of books ,author, price, issue date and category for library record keeping system
#include<stdio.h>
struct library{
    char book_name[50];
    char author_name[50];
    char category[50];
    char issued_date[50];
    int price;
};
int main(){
    struct library lib[2];
    FILE *fp;
    fp = fopen("projectc.txt", "w");
    int i;
    printf("enter book name author name category issued date price");
    for(i=0;i<2;i++){
        scanf("%s %s %s %s %d",&lib[i].book_name,&lib[i].author_name,&lib[i].category,&lib[i].issued_date,&lib[i].price);
        fprintf(fp,"%s  %s  %s  %s  %d \n",lib[i].book_name,lib[i].author_name,lib[i].category,lib[i].issued_date,lib[i].price);
    }
    printf("written successfully");
    fclose(fp);

    return 0;
}           