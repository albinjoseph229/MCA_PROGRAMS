#include <stdio.h>
#include <stdlib.h>
struct book
{
    char author_name[20];
    char book_name[20];
};
struct book *a;
int i, n;
void read()
{
    a = (struct book *)malloc(sizeof(struct book));
    for (i = 0; i < n; i++)
    {
        printf("\n Enter details of book %d", i + 1);
        printf("\n ------------------------");
        printf("\n Enter book name:");
        gets(a[i].book_name);
        printf("\n Enter author name:");
        gets(a[i].author_name);
    }
}
void disp()
{
    for (i = 0; i < n; i++)
    {
        printf("\n===================");
        printf("\nDetails of book %d", i + 1);
        printf("\n===================");
        printf("\n Book name:%s", a[i].book_name);
        printf("\n Author name:%s", a[i].author_name);
    }
}

void main()
{
    printf("\n Enter no of books you want to enter:");
    scanf("%d", &n);
    getchar();
    read();
    disp();
}
