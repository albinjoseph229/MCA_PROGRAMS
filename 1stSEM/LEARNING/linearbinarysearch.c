#include <stdio.h>
int n, i;
int arr[50];

int read()
{
    printf("enter the number of elements:");
    scanf("%d", &n);
    printf("enter the elements\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void sort()
{
    int j, t;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < (n - i) - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                t = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = t;
            }
        }
    }
}
void display()
{
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
void lsearch(int e)
{
    int count = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == e)
        {
            printf("%d found at %dth position\n", e, i);
            count++;
        }
    }
    if (count == 0)
    {
        printf("\nelement not found!");
    }
}
void bsearch(int e)
{
    int low = 0;
    int high = n - 1;
    int mid;
    int count = 0;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (e == arr[mid])
        {
            printf("\nelement found");
            count++;
            break;
        }
        else if (e < mid)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    if (count == 0)
    {
        printf("Element not found\n");
    }
}
int main()
{
    read();
    sort();
    display();
    int e;
    printf("\nenter the elemet to search for: ");
    scanf("%d", &e);
    lsearch(e);
    bsearch(e);
}