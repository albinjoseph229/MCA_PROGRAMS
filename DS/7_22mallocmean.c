#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i;
    int count;
    int *arr;
    int sum=0;
    int mean;

    printf("enter the total no of elements");
    scanf("%d",&count);
    arr=(int *)malloc(count* sizeof(int));

    for(i = 0;i < count; i++)
    {
        printf("Enter the element %d",(i+1));
        scanf("%d",arr+1);

        sum += *(arr+i);
    }
    printf("%d",sum);
    free(arr);
    return 0;
}