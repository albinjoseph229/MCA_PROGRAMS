#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <process.h>
struct dictionary
{
    char name[20];
    struct dictionary *left, *right;
};
typedef struct dictionary dict;
dict *root = NULL;
int check(char a[], char b[])
{
    int i, j, c;
    for (i = 0, j = 0; a[i] != '\0' && b[j] != '\0'; i++, j++)
    {
        if (a[i] > b[j])
        {
            c = 1;
            break;
        }
        else if (b[j] > a[i])
        {
            c = -1;
            break;
        }
        else
            c = 0;
    }
    if (c == 1)
        return 1;
    else if (c == -1)
        return -1;
    else
        return 0;
}
void insert(dict *temp)
{
    int flag = 0;
    dict *ptr, *p;
    ptr = root;

    if (root == NULL)
        root = temp;
    else
    {
        while (ptr != NULL)
        {
            if (check(temp->name, ptr->name) > 0)
            {

                p = ptr;
                ptr = ptr->right;
            }

            else if (check(temp->name, ptr->name) < 0)
            {
                p = ptr;
                ptr = ptr->left;
            }
            else if (check(temp->name, ptr->name) == 0)
            {
                flag = 1;
                printf("\nName exists!!!!");
                break;
            }
        }
        if (flag == 0 && ptr == NULL)
        {

            if (check(p->name, temp->name) == 1)
                p->left = temp;
            else if (check(p->name, temp->name) == -1)
                p->right = temp;
        }
    }
}
void disp(dict *root)
{
    if (root != NULL)
    {
        disp(root->left);
        printf("%s  ", root->name);
        disp(root->right);
    }
}
void main()
{
    dict *t;
    int ch;
    char w1[20];
    printf("\nBINARY SEARCH TREE USING STRING");
    do
    {
        printf("\n1.Insert\n2.Display\n3.Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            t = (dict *)malloc(sizeof(dict));
            t->left = NULL;
            t->right = NULL;
            printf("Enter name: ");
            scanf("%s", t->name);
            insert(t);

            break;
        case 2:
            printf("\nNames:");
            disp(root);
            printf("\n");
            break;
        case 3:
            exit(1);
            break;
        }
    } while (1);
}
