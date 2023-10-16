#include <stdio.h>
int binary(int arr[], int size, int e)
{
    int low, mid, high,flag=0;
    low = 0;
    high = size - 1;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (arr[mid] == e)
        {
            printf("Element fount at%d", mid);
            flag=1;
        }
        else if(arr[mid]<e)
        {
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    if(flag==0)
    {
        printf("Element not found\n");
    }
}
int linear(int arr[], int size, int e)
{
    int i = 0, flag = 0;
    for (i = 0; i < size; i++)
    {
        if (arr[i] == e)
        {
            printf("element found at index:%d\n", i);
            flag = 1;
        }
    }
    if (flag == 0)
    {
        printf("element not found\n");
    }
}
int main()
{
    int arr[] = {12, 14, 16, 18, 20, 22, 26};
    int size = sizeof(arr) / sizeof(int);
    int e = 111;
    binary(arr,size,e);
    linear(arr, size, e);
}