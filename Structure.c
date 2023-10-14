
// Syntax
/*
struct structure_name{
    datatype1 member_name1;
    datatype2 member_name2;             -> no memory is allocated during declaration
    datatype3 member_name3;
    ...
};

we have to define its instance to use structure in our program

struct structure_name{
    datatype1 member_name1;
    datatype2 member_name2;
    ...
}variable1,variable2;

or 

struct structure_name variable1,variable2;

we can access structure member using the dot operator

structure_name.member1;
structure_name.member2;

*/

#include <stdio.h>

struct book{
    float price;
    int pages;
    char name[50];
};

int main()
{
    struct book book;
    printf("Enter the book name:\n");
    fgets(book.name,sizeof(book.name),stdin);
    printf("Enter the book price:\n");
    scanf("%f",&book.price);
    printf("Enter the number of pages in book:\n");
    scanf("%d",&book.pages);
    printf("\n");
    printf("Name: ");
    puts(book.name);
    printf("\nPrice: %f",book.price);
    printf("\nNumber of pages: %d",book.pages);
    printf("\n");
    return 0;
}
